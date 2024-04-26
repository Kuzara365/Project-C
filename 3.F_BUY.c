#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int lastAssignedID = 0;


//import data from product.csv
void readProduct(struct product **products, int *productCount) {
    char line[1000];
    char *data;
    FILE * productData = fopen("product.csv", "r");
    if (productData == NULL) {
        printf("Error opening file\n");
        return;
    }
    else {
        while (fgets(line, 100, productData) != NULL) {
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

//show product
void showProduct(struct product *Arrproduct, int number)
{
	for (int i = 0; i < number; i++)
	{
		printf("ID: %d\n", Arrproduct[i].id);
		printf("Product name: %s\n", Arrproduct[i].product_name);
		printf("Remain: %d\n", Arrproduct[i].remain);
		printf("Price: %f\n", Arrproduct[i].price);
	}
}


// Function to add new cart
void addCart(struct cart **carts, int *cartCount, char *product_id, char *product_name, int price, int sum, char *coupon, int final_sum, int user_id)
{
    *carts = (struct cart *)realloc(*carts, (*cartCount + 1) * sizeof(struct cart));
    (*carts)[*cartCount].id = ++lastAssignedID;
    strcpy((*carts)[*cartCount].product_id, product_id);
    strcpy((*carts)[*cartCount].product_name, product_name);
    (*carts)[*cartCount].price = price;
    (*carts)[*cartCount].sum = sum;
    (*carts)[*cartCount].final_sum = final_sum;
    (*carts)[*cartCount].user_id = user_id;
    (*cartCount)++;
    printf("Created new cart successfully.\n");
}