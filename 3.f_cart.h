#ifndef F_CART_H
#define F_CART_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f_buy();
void readProduct(struct product **products, int *productCount);
void displayProduct(struct product *products, int productCount);


#endif