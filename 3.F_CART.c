#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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