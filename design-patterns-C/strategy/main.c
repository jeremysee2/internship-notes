#include "Customer.h"
#include "CustomerCategories.h"

static CustomerPtr createBronzeCustomer(const char* name, const Address* address)
{
    return createCustomer(name, address, bronzePriceStrategy);
}