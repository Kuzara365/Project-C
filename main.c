#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	char pruct_name[30];
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
	int phone_number;
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

int main()
{
	FILE *file;
	file = fopen("product.csv", "r");
}