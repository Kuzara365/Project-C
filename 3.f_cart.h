#ifndef F_CART_H
#define F_CART_H

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

struct user
{
    int id;
    char name[30];
    char address[30];
    char phone_number[15];
};

void f_cart();
void newCart(struct cart **carts, int *cartCount);
void displayCart(struct cart *carts, int cartCount);
void addCart(struct cart **carts, int *cartCount, struct product *products, int productCount, int user_id);

#endif