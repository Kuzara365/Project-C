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


//Import product from file
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


//Display product
void displayProduct(struct product *products, int productCount) {
    printf("List of product \n");
    for (int i = 1; i < productCount; i++) {
        printf("ID: %d\n", products[i].id);
        printf("%s\n", products[i].product_name);
        printf("Remain %d\n", products[i].remain);
        printf("Price %d\n", products[i].price);
        printf("--------------------------------------\n");
    }
}

void f_buy(){
    printf("List of goods");

    void readProduct(struct product **products, int *productCount);
    void displayProduct(struct product *products, int productCount);
    //func : in mat hang 

    printf("|****************SALES PAGE******************|\n");
	printf("|**0.Exit.                                 **|\n");
	printf("|**1.Select goods.                         **|\n"); 
	printf("|********************************************|\n");
    int opt=0;
    printf("Enter your choose: ");
    scanf("%d",opt);
    do{
        switch(opt){
            case 0:{
                break;
            }
            case 1:{
                //func: chon mat hang 
                break;
            }
        }
    }while (opt != 0);
}


int main(){
    	
}