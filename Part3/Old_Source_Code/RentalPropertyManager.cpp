#include "RentalPropertyManager.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <assert.h>
#include <exception>


/**************************************************************************************
 * HELPER FUNCITON PROTOTYPES
 **************************************************************************************/


vector<string> tokenize(const string &, string);
void trimSpaces(string &);
Tenant tenantFromLine(string);
string mapGender(string);
bool mapPaymentStatus(string);
vector<string> readLines(ifstream &);
void openDataFile(ifstream &, string);
Manager managerFromLine(string);
template <class T>
void loadData(string, vector<T> &, T (*)(string));


/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/


const size_t TENANT_FILE_LINE_LENGTH = 13;
const size_t MANAGER_FILE_LINE_LENGTH = 12;


/**************************************************************************************
 * MEMBER FUNCTION DEFINITIONS
 **************************************************************************************/


void RentalPropertyManager::loadManagers(string filepath) {
    loadData(filepath, managerList, managerFromLine);
}

void RentalPropertyManager::loadTenants(string filepath) {
    loadData(filepath, tenantList, tenantFromLine);
}

double RentalPropertyManager::calcCollectedRentTotal() const {
    double sum = 0;
    for (auto tenant : tenantList) {
        sum += tenant.calcPaidFeesTotal();
    }
    return sum;
}

double RentalPropertyManager::calcCollectedRentForMonth(int month) const {
    double sum = 0;
    for (auto tenant : tenantList) {
        sum += tenant.calcPaidFeesforMonth(month);
    }
    return sum;
}

string RentalPropertyManager::generateCollectedRentMonthlySummary() const {
    stringstream x;
    x.precision(2);
    x.setf(ios::fixed);
    
    //Calculate total collected rent for each month and output string with summary amounts
    x << "COLLECTED MONTHLY RENT SUMMARY:" << endl;
    for (int i = 0; i < 6; i++) {
        x << "Month " << i << " - Rent: $" << calcCollectedRentForMonth(i) << endl;
    }
    return x.str();
}

double RentalPropertyManager::calcUnpaidRentTotal() const {
    double total= 0.0;
    
    for(auto t : tenantList)
    {
        total += t.calcUnpaidFeesTotal();
    }    
    return total;
}

double RentalPropertyManager::calcUnpaidRentForMonth(int month) const {
    double total= 0.0;
    
    for(auto t : tenantList)
    {
        total += t.calcUnpaidFeesForMonth(month);
    }    
    return total;    
}

double RentalPropertyManager::calcManagerExpenseTotal() const {

    double total= 0.0;
    
    for(auto m : managerList)
    {
        total += m.calcExpenseTotal();
    }    
    return total;
}

double RentalPropertyManager::calcManagerExpenseForMonth(int month) const {
   double total= 0.0;
    
    for(auto m : managerList)
    {
        total += m.getExpenseForMonth(month);
    }    
    return total;
}

string RentalPropertyManager::generateManagerExpenseMonthlySummary() const {
    stringstream x;
    x.precision(2);
    x.setf(ios::fixed);
    
    //Calculate total maanger expenses for each month and output string with summary amounts
    x << "MANAGER EXPENSES SUMMARY:" << endl;
    for (int i = 0; i < 6; i++) {
        x << "Month " << i << " - Manager Expenses: $" << calcManagerExpenseForMonth(i) << endl;
    }
    return x.str();
}

double RentalPropertyManager::calcManagerRemunerationTotal() const {
   double total= 0.0;
    
    for(auto m : managerList)
    {
        total += m.calcRemunerationTotal();
    }
    
    return total;
}

double RentalPropertyManager::calcManagerRemunerationForMonth(int month) const {
   double total= 0.0;
    
    for(auto m : managerList)
    {
        total += m.calcRemunerationForMonth(month);
    }
    
    return total;
}

string RentalPropertyManager::generateManagerRemunerationMonthlySummary() const {
    stringstream x;
    x.precision(2);
    x.setf(ios::fixed);
    
    //Calculate total manager remuneration (salary and bonus) for each month and output string with summary amounts
    x << "MANAGER REMUNERATION SUMMARY:" << endl;
    for (int i = 0; i < 6; i++) {
        x << "Month " << i << " - Remuneration Paid: $" << calcManagerRemunerationForMonth(i) << endl;
    }
    return x.str();
}

double RentalPropertyManager::calcNetIncomeTotal() const {
   double total= 0.0;
    
    for(auto t : tenantList)
    {
        total += t.calcPaidFeesTotal();
    }
    for(auto m : managerList)
    {
        total -= m.calcExpenseTotal();
        total -= m.calcRemunerationTotal();
    }    
    return total;
}

double RentalPropertyManager::calcNetIncomeForMonth(int month) const {
     double total= 0.0;
    
    for(auto t : tenantList)
    {
        total += t.calcPaidFeesforMonth(month);
    }
    for(auto m : managerList)
    {
        total -= m.getExpenseForMonth(month);
        total -= m.calcRemunerationForMonth(month);
    }    
    return total;
}

string RentalPropertyManager::generateNetIncomeMonthlySummary() const {
    stringstream x;
    x.precision(2);
    x.setf(ios::fixed);
    
    //Calculate net income for each month and output string with summary amounts
    x << "NET INCOME SUMMARY:" << endl;
    for (int i = 0; i < 6; i++) {
        x << "Month " << i << " - Net Income: $" << calcManagerRemunerationForMonth(i) << endl;
    }
    return x.str();
}

vector<string> RentalPropertyManager::getAllProfiles() {
    vector <string> profs;
    string x = "";
   
    for(auto t : tenantList) {   
        profs.push_back(t.getProfile());
    }

    for(auto m : managerList) {                   
       profs.push_back(m.getProfile());
    }
    return profs;
}

vector<Tenant> RentalPropertyManager::getTenantsWithUnpaidAmounts() const {
    vector <Tenant> unpaid;
    for(auto t : tenantList) {
        if(t.hasUnpaidFees()) {
            unpaid.push_back(t);
        }
    }
    return unpaid;
}


/**************************************************************************************
 * HELPER FUNCTIONS
 **************************************************************************************/


/**
 * Function to load either tenants or managers from a data file.
 *
 * @param filepath The path of the file to read.
 * @param container The container that will hold the managers or tenants.
 * @param loadproc A function that takes in a line and returns a manager or a tenant.
 */
template <class T>
void loadData(string filepath, vector<T> &container, T (*loadproc)(string)) {

    ifstream file;
    openDataFile(file, filepath);

    // Consume the header line
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    auto lines = readLines(file);
    for (auto line : lines) {
        container.push_back(loadproc(line));
    }
}

/**
 * Builds a tenant object from a line read from a tenant data file.
 * 
 * @param line A line read from a tenant CSV data file.
 */
Tenant tenantFromLine(string line) {

    auto tokens = tokenize(line, ",");
    
    if (tokens.size() != TENANT_FILE_LINE_LENGTH) {
        throw invalid_argument("Caught malformed line in tenant data file.\n"
                               "Caused by: " + line);
    }

    // sto_ functions can throw an invalid_argument exception
    Tenant newTenant = Tenant(
        tokens.at(0),
        stoi(tokens.at(1)),
        mapGender(tokens.at(2)),
        stoi(tokens.at(4)),
        tokens.at(5),
        stod(tokens.at(6))
    );
    newTenant.setJob(tokens.at(3));

    newTenant.setPaymentsStatus({
        mapPaymentStatus(tokens.at(7)),
        mapPaymentStatus(tokens.at(8)),
        mapPaymentStatus(tokens.at(9)),
        mapPaymentStatus(tokens.at(10)),
        mapPaymentStatus(tokens.at(11)),
        mapPaymentStatus(tokens.at(12)),
    });

    return newTenant;
}

/**
 * Builds a manager object from a line read from a manager data file.
 * 
 * @param line A line read from a manager CSV data file.
 */
Manager managerFromLine(string line) {

    auto tokens = tokenize(line, ",");
    
    if (tokens.size() != MANAGER_FILE_LINE_LENGTH) {
        throw invalid_argument("Caught malformed line in manager data file."
                               "Caused by: " + line);
    }

    Manager manager = Manager(
        tokens.at(0),
        stoi(tokens.at(1)),
        mapGender(tokens.at(2)),
        tokens.at(3),
        stod(tokens.at(4)),
        stod(tokens.at(5))
    );

    manager.setMonthlyExpenses({
        stod(tokens.at(6)),
        stod(tokens.at(7)),
        stod(tokens.at(8)),
        stod(tokens.at(9)),
        stod(tokens.at(10)),
        stod(tokens.at(11)),
    });

    return manager;
}

void openDataFile(ifstream &file, string filename) {
    file.open(filename);
    if (file.fail()) {
        throw runtime_error("Error opening \"" + filename + "\"");
    }
}

string mapGender(string token) {
    if (token == "M") return "Male";
    if (token == "F") return "Female";
    return "Not Specified";
}

bool mapPaymentStatus(string status) {
    if (status == "Paid") return true;
    return false;
}

vector<string> readLines(ifstream &file) {
    auto lines = vector<string>();
    while(!file.eof()) {
        string line;
        getline(file, line);
        if (line == "") break;
        lines.push_back(line);
    }
    return lines;
}

vector<string> tokenize(const string & input, string delims) {
    vector<string> tokens = vector<string>();
    
    size_t a = 0;
    size_t b = 0;

    while (true) {
        a = input.find_first_not_of(delims, b);
        if (a == string::npos) break;
        b = input.find_first_of(delims, a);

        string token = input.substr(a, b - a);
        trimSpaces(token);

        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

void trimSpaces(string &input) {
    int end = input.size() - 1;
    while (end >= 0 && input.at(end) == ' ' || (input.at(end) < 32 || input.at(end) > 127)) { // strip non-ascii
        input.pop_back();
        end = input.size() - 1;
    }
    int front = 0;
    while (front <= input.size() && input.at(front) == ' ') {
        input.erase(front, 1);
        front = front + 1;
    }
}