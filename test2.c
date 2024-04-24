#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void);
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
	char pruct_name[30];
	int price;
	int sum;
	char coupon[30];
	int final_sum;
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
	int price;
	int final_sum;
	char payment[100];
	char status[30];
	int user_id;
	int cart_id;
};

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_LENGTH 20
#define MAX_ITEMS 10

//Import product from file
void readProduct(struct product **products, int *productCount) {
    char line[1000];
    char *data;
    FILE * productData = fopen("E:/Project C/product.csv", "r");
    if (productData == NULL) {
        printf("Error opening file\n");
        return;
    }
    else {
        while (fgets(line, 1000, productData) != NULL) {
            (*productCount)++;
            *products = (struct product *)realloc(*products, *productCount * sizeof(struct product));

            data = strtok(line, ",");
            (*products)[*productCount - 1].id = atoi(data);

            data = strtok(NULL, ",");
            strcpy((*products)[*productCount - 1].product_name, data);

            data = strtok(NULL, ",");
            (*products)[*productCount - 1].remain = atoi(data);

            data = strtok(NULL, ",");
            (*products)[*productCount - 1].price = atoi(data);
        }
        fclose(productData);
    }
}

//Hiển thị sản phẩm
void displayProduct(struct product *products, int productCount) {
    printf("List of product \n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d\n", products[i].id);
        printf("%s\n", products[i].product_name);
        printf("Remain %d\n", products[i].remain);
        printf("Price %d\n", products[i].price);
        printf("--------------------------------------\n");
    }
}

int main() {
	struct product *products = NULL;
	int productCount = 0;
	readProduct(&products, &productCount);
	displayProduct(products, productCount);
	return 0;
}