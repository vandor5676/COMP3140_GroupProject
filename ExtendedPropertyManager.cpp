#include "ExtendedPropertyManager.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <assert.h>
#include <exception>
#include <vector>


/**************************************************************************************
 * HELPER FUNCITON PROTOTYPES
 **************************************************************************************/
template <class T>
void loadData(string, vector<T> &, T (*)(string));
Manager managerFromLine(string);
Tenant tenantFromLine(string);

//constructor
 ExtendedPropertyManager::ExtendedPropertyManager() 
 {

 }

 
 void ExtendedPropertyManager::loadTenants(string filepath) { 
    loadData(filepath, publicTenantList, tenantFromLine); 
}
void ExtendedPropertyManager::loadManagers(string filepath) { 
    loadData(filepath, publicManagerList, managerFromLine);
}

