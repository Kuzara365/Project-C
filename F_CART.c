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
    int product_id;
    char product_name[30];
    int quantity;
    int price;
    int sum;
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
    int product_id;
    char product_name[30];
    int price;
    int final_sum;
    char payment[100];
    char status[30];
    int user_id;
    int cart_id;
};

void newCart(struct cart **carts, int *cartCount)
{
    *cartCount += 1;
    *carts = (struct cart *)realloc(*carts, *cartCount * sizeof(struct cart));
    (*carts)[*cartCount - 1].id = *cartCount;
}

void displayCart(struct cart *carts, int cartCount)
{
    for (int i = 0; i < cartCount; i++)
    {
        printf("Cart ID: %d\n", carts[i].id);
        printf("Product ID: %d\n", carts[i].product_id);
        printf("Product name: %s\n", carts[i].product_name);
        printf("Quantity: %d\n", carts[i].quantity);
        printf("Price: %d\n", carts[i].price);
        printf("Sum: %d\n", carts[i].sum);
        printf("User ID: %d\n", carts[i].user_id);
    }
}

void addCart(struct cart **carts, int *cartCount, struct product *products, int productCount, int user_id)
{
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++)
    {
        if (products[i].id == id)
        {
            newCart(carts, cartCount);
            (*carts)[*cartCount - 1].product_id = products[i].id;
            strcpy((*carts)[*cartCount - 1].product_name, products[i].product_name);
            (*carts)[*cartCount - 1].price = products[i].price;
            (*carts)[*cartCount - 1].user_id = user_id;
            printf("Enter quantity: ");
            scanf("%d", &(*carts)[*cartCount - 1].quantity);
            (*carts)[*cartCount - 1].sum = (*carts)[*cartCount - 1].price * (*carts)[*cartCount - 1].quantity;
            break;
        }
    }
}

void deleteCart(struct cart **carts, int *cartCount, int user_id)
{
    for (int i = 0; i < *cartCount; i++)
    {
        if ((*carts)[i].user_id == user_id)
        {
            for (int j = i; j < *cartCount - 1; j++)
            {
                (*carts)[j] = (*carts)[j + 1];
            }
            *cartCount -= 1;
            *carts = (struct cart *)realloc(*carts, *cartCount * sizeof(struct cart));
        }
    }
}

void ChangeQuantity(struct cart **carts, int *cartCount, int id, int new_quantity)
{
    printf("Enter new quantity: ");
    scanf("%d", &new_quantity);
    for (int i = 0; i < *cartCount; i++)
    {
        if ((*carts)[i].id == id)
        {
            (*carts)[i].quantity = new_quantity;
            (*carts)[i].sum = (*carts)[i].price * new_quantity;
            break;
        }
    }
}


void enterUserInfo(struct user *user) {
    printf("Enter your Id: ");
    scanf("%d", &user->id);

    printf("Your name: ");
    scanf("%s", user->name);

    printf("Your address: ");
    scanf("%s", user->address);

    printf("Phone number: ");
    scanf("%s", user->phone_number);
}

void CheckCart()
{
	printf("|*****************CART*****************|\n");
	printf("|**0.Move to menu.                   **|\n");
	printf("|**1.Select bills.                   **|\n");
	printf("|**************************************|\n");
}


void f_cart(){
    int opt;
    struct cart *carts = NULL;
    int cartCount = 0;
    struct user user;
    printf("Enter option: ");
    scanf("%d", &opt);
    do {
        switch(opt){
            case 0:{
                printf("Move to Menu!");
                break;
            }
            case 1:{
                //func: chon bill muon chinh sua
                
                //menu lua chon chinh sua + xoa don :
                int n = 0; 
                printf("Option:");
                scanf("%d", n);
                do{
                    switch (n){
                        case 0:{
                            printf("Move to menu!");
                            break;
                        }
                        case 1:{// func: chinh sua don hang
                            int id, new_quantity;
                            printf("Enter cart ID: ");
                            scanf("%d", &id);
                            ChangeQuantity(&carts, &cartCount, id, new_quantity);
                            break;
                        }
                        case 2:{ // func : xoa don hang
                            deleteCart(&carts, &cartCount, user.id);
                            break;
                        }
                        case 3:{ // func : xac nhan mua hang 
                            enterUserInfo(&user);
                        }
                    }
                }while( n != 0);
            }
            default:{
                printf("Invalid option!");
                break;
            }
        }
    }while(opt != 0);

    free(carts);
}