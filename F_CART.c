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

int lastAssignedID = 0;

// Function to add new cart
void addCart(struct cart **carts, int *cartCount, char *product_id, char *product_name, float price, float sum, char *coupon, float final_sum, int user_id)
{
    *carts = (struct cart *)realloc(*carts, (*cartCount + 1) * sizeof(struct cart));
    (*carts)[*cartCount].id = ++lastAssignedID; // Increment and assign new ID
    strcpy((*carts)[*cartCount].product_id, product_id);
    strcpy((*carts)[*cartCount].product_name, product_name);
    (*carts)[*cartCount].price = price;
    (*carts)[*cartCount].sum = sum;
    (*carts)[*cartCount].final_sum = final_sum;
    (*carts)[*cartCount].user_id = user_id;
    (*cartCount)++;
    printf("Created new cart successfully.\n");
}

// Function to update cart
void updateCart(struct cart *carts, int cartCount, int id, float new_final_sum)
{
    for (int i = 0; i < cartCount; i++)
    {
        if (carts[i].id == id)
        {
            carts[i].final_sum = new_final_sum;
            printf("Updated cart successfully.\n");
            return;
        }
    }
    printf("Cart with corresponding ID not found.\n");
}

// Function to delete cart
void deleteCart(struct cart **carts, int *cartCount, int id)
{
    int found = 0;
    for (int i = 0; i < *cartCount; i++)
    {
        if ((*carts)[i].id == id)
        {
            for (int j = i; j < *cartCount - 1; j++)
            {
                (*carts)[j] = (*carts)[j + 1];
            }
            (*cartCount)--;
            found = 1;
            printf("Deleted cart successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Cart with corresponding ID not found.\n");
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
    CheckCart();
    int opt=0;
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
                           updateCart(struct cart *carts, int cartCount, int id, float new_final_sum);
                           break;
                        }
                        case 2:{ // func : xoa don hang
                            deleteCart(struct cart **carts, int *cartCount, int id);
                            break;
                        }
                        case 3:{ // func : xac nhan mua hang 
                            void enterUserInfo(struct user *user);
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
}