#pragma once

// Bank.h
#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Customer.h"

using namespace std;

class Bank {
private:
    string branchID;
    string address;
    vector<string> customerIDs;
    int customerCount;
    int activeAccounts;

public:
    Bank(string& branchID, string& address);
    void addCustomer(Customer& customer);
    void removeCustomer(string& customerID);
    // 기타 필요한 메서드 추가
};

#endif
