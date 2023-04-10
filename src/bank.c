#include "main.h"
#include "System.h"
#include "Scanner.h"
#include "Bank.h"

import SYSTEM System;

boolean compareStrings(String str1, String str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0' || str2[i] == '\0')
            break;
        i++;
    }
    if (str1[i] < str2[i]) {
        return false;
    } else {
        return true;
    }
}

ACCOUNT* new_Account(size_t size){
    size = size > 255 ? 255 : size;
    ACCOUNT* account = (ACCOUNT*)malloc(sizeof(ACCOUNT) * size);
    account->name = (String)malloc(sizeof(char) * 31);
    account->accountNumber = (String)malloc(sizeof(char) * 15);
    account->password = (String)malloc(sizeof(char) * 21);
    return account;
}

ACCOUNT createAccount(FILE *fp){
    fopen("account.txt", "a");
    ACCOUNT account = {
        .name = (String)malloc(sizeof(char) * 31),
        .accountNumber = (String)malloc(sizeof(char) * 15),
        .password = (String)malloc(sizeof(char) * 21)
    };
    Scanner sc = new_Scanner(System.in);
    System.out.print("Enter your name(limet 30): ");
    account.name = sc.next();
    System.out.print("Enter your account number(limit 14): ");
    account.accountNumber = sc.next();
    System.out.print("Enter your password(limit 20): ");
    account.password = sc.next();
    fprintf(fp, "%s %s %s", account.name, account.accountNumber, account.password);
    fclose(fp);
    return account;
}

void sortAccount(ACCOUNT *account, FILE *fp) {
    uint8_t i, j, min_index;
    uint8_t size = sizeof(account) / sizeof(account[0]);
    ACCOUNT temp;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (compareStrings(account[j].accountNumber, account[min_index].accountNumber) == 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = account[i];
            account[i] = account[min_index];
            account[min_index] = temp;
        }
    }
}

void readAccount(ACCOUNT *account, FILE *fp){
    uint8_t i = 0;
    fopen("account.txt", "r");
    while(fscanf(fp, "%s %s %s", account[i].name, account[i].accountNumber, account[i].password) != EOF) i++;
    fclose(fp);
}

void printAccount(ACCOUNT *account, FILE *fp){

}

ManageAccount new_ManageAccount(){
    ManageAccount manage = {
        .new_Account = new_Account,
        .createAccount = createAccount,
        .sortAccount = sortAccount,
        .printAccount = printAccount
    };
    return manage;
}
