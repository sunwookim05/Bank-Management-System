#include "main.h"

#pragma once
#ifndef __BANK_H
#define __BANK_H

typedef struct _ACCOUNT_{
    String name;
    String accountNumber;
    String password;
} ACCOUNT;

typedef struct _ManageAccount_{
    ACCOUNT* (*new_Account)(size_t);
    ACCOUNT (*createAccount)(String, String, String, FILE*);
    void (*sortAccount)(ACCOUNT*, FILE*);
    void (*readAccount)(ACCOUNT*, FILE*);
    void (*printAccount)(ACCOUNT*, FILE*);
} ManageAccount;

ManageAccount new_ManageAccount();

#pragma warning(pop)
#endif
