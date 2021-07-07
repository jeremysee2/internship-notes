#include "Customer.h"
#include "customerStrategy.h"
#include "customerCategories.h"

void placeOrder(struct Customer* customer, const Order* order)
{
    double totalAmount = Customer->priceStrategy(order->amount, order->shipping);
    // Add more code to process the order...
}

// Class constructor
CustomerPtr createCustomer (const char* name, const Address* address, customerPriceStrategy priceStrategy)
{
    CustomerPtr customer = malloc(sizeof *Customer);

    if (NULL != customer) {
        // Bind the initial strategy supplied by the client
        customer->priceStrategy = priceStrategy;
        // Initialise the other attributes of the customer here
    }
    return customer;
}

void changePriceCategory(CustomerPtr customer, customerPriceStrategy newPriceStrategy)
{
    assert(NULL != customer);
    // Rebind pointers to a new 
    customer->priceStrategy = newPriceStrategy;
}