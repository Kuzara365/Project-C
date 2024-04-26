#ifndef F_CART_H
#define F_CART_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f_check();
//lay thong tin khach hang 
void ExportUser(struct user *users, int userCount);
void readUser(struct user **users, int *userCount);
void displayUser(struct user *users, struct order *order, int userCount);

//lay thong tin bill cua khach hang 
void ExportOrder(struct order *orders, int orderCount);
void readOrder(struct order **orders, int *orderCount);
void displayOrder(struct order *orders, int orderCount);

#endif