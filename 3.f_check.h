#ifndef F_CHECK_H
#define F_CHECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
	int id;
	char name[30];
	char address[30];
	int phone_number;
};

struct order
{
	int id;
	char product_name[30];
    int quantity;
	int price;
	int final_sum;
	char payment[100];
	char status[30];
	int user_id;
};

void f_check();
//lay thong tin khach hang 
void ExportUser(struct user *users, int userCount);
void readUser(struct user **users, int *userCount);
void displayUser(struct user *users, int userCount);

//lay thong tin bill cua khach hang 
void ExportOrder(struct order *orders, int orderCount);
void readOrder(struct order **orders, int *orderCount);
void displayOrder(struct order *orders, int orderCount);

#endif