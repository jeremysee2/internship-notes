#include "customerCategories.h"

double bronzePriceStrategy(double amount, double shipping)
{
    return amount * 0.98 + shipping;
}

double silverPriceStrategy(double amount, double shipping)
{
    return amount * 0.95 + shipping;
}

double goldPriceStrategy(double amount, double shipping)
{
    // Free shipping for Gold customers
    return amount * 0.90;
}