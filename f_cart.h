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
    float price;
};

struct cart
{
    int id;
    char product_id[30];
    char product_name[30];
    float price;
    float sum;
    char coupon[30];
    float final_sum;
    int user_id;
};

struct user
{
    int id;
    char name[30];
    char address[30];
    char phone_number[15];
};

struct order
{
    int id;
    char product_id[30];
    char product_name[30];
    float price;
    float final_sum;
    char payment[100];
    char status[30];
    int user_id;
    int cart_id;
};

void f_cart();
void addCart(struct cart **carts, int *cartCount, char *product_id, char *product_name, float price, float sum, float final_sum, int user_id);
void updateCart(struct cart *carts, int cartCount, int id, float new_final_sum);
void deleteCart(struct cart **carts, int *cartCount, int id);
void enterUserInfo(struct user *user);
void CheckCart();

#endif