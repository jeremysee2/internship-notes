#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerStrategy.h"

typedef struct Customer* CustomerPtr;

typedef struct Address
{
    char* street;
}Address;

typedef struct List
{
    char* names;
}List;

struct Customer
{
    const char* name;
    Address address;
    List orders;
    // Bind the strategy to customer
    customerPriceStrategy priceStrategy;
};

#endif