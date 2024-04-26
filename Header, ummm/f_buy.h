#ifndef F_BUY_H
#define F_BUY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product
{
	int id;
	char product_name[30];
	int remain;
	int price;
};


struct cart
{
	int id;
	char product_id[30];
	char product_name[30];
	int price;
	int sum;
	int final_sum;
	int user_id;
};

void f_buy();
void readProduct(struct product **products, int *productCount);
void displayProduct(struct product *products, int productCount);


#endif

