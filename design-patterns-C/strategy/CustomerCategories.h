#ifndef CUSTOMERCATEGORIES_H
#define CUSTOMERCATEGORIES_H

// http://www.adampetersen.se/Patterns%20in%20C%203,%20STRATEGY.pdf

// Function prototypes
double bronzePriceStrategy(double amount, double shipping);
double silverPriceStrategy(double amount, double shipping);
double goldPriceStrategy(double amount, double shipping);

#endif