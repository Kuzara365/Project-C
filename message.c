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
    strcpy((*carts)[*cartCount].coupon, coupon);
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

// Function to add new order
void addOrder(struct order **orders, int *orderCount, char *product_id, char *product_name, float price, float final_sum, char *payment, char *status, int user_id, int cart_id)
{
    *orders = (struct order *)realloc(*orders, (*orderCount + 1) * sizeof(struct order));
    (*orders)[*orderCount].id = ++lastAssignedID; // Increment and assign new ID
    strcpy((*orders)[*orderCount].product_id, product_id);
    strcpy((*orders)[*orderCount].product_name, product_name);
    (*orders)[*orderCount].price = price;
    (*orders)[*orderCount].final_sum = final_sum;
    strcpy((*orders)[*orderCount].payment, payment);
    strcpy((*orders)[*orderCount].status, status);
    (*orders)[*orderCount].user_id = user_id;
    (*orders)[*orderCount].cart_id = cart_id;
    (*orderCount)++;
    printf("Created new order successfully.\n");
}

// Function to update order
void updateOrder(struct order *orders, int orderCount, int id, char *new_status)
{
    for (int i = 0; i < orderCount; i++)
    {
        if (orders[i].id == id)
        {
            strcpy(orders[i].status, new_status);
            printf("Updated order successfully.\n");
            return;
        }
    }
    printf("Order with corresponding ID not found.\n");
}

// Function to delete order
void deleteOrder(struct order **orders, int *orderCount, int id)
{
    int found = 0;
    for (int i = 0; i < *orderCount; i++)
    {
        if ((*orders)[i].id == id)
        {
            for (int j = i; j < *orderCount - 1; j++)
            {
                (*orders)[j] = (*orders)[j + 1];
            }
            (*orderCount)--;
            found = 1;
            printf("Deleted order successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Order with corresponding ID not found.\n");
    }
}

// Function to check cart
void checkCart(struct cart *carts, int cartCount, int user_id)
{
    printf("\n====== CART ======\n");
    for (int i = 0; i < cartCount; i++)
    {
        if (carts[i].user_id == user_id)
        {
            printf("Cart ID: %d\n", carts[i].id);
            printf("Product ID: %s\n", carts[i].product_id);
            printf("Product Name: %s\n", carts[i].product_name);
            printf("Price: %.2f\n", carts[i].price);
            printf("Sum: %.2f\n", carts[i].sum);
            printf("Coupon: %s\n", carts[i].coupon);
            printf("Final Sum: %.2f\n", carts[i].final_sum);
            printf("User ID: %d\n", carts[i].user_id);
            printf("------------------\n");
        }
    }
    printf("====== END CART ======\n");
}

// Function to check order
void checkOrder(struct order *orders, int orderCount, int user_id)
{
    printf("\n====== ORDERS ======\n");
    for (int i = 0; i < orderCount; i++)
    {
        if (orders[i].user_id == user_id)
        {
            printf("Order ID: %d\n", orders[i].id);
            printf("Product ID: %s\n", orders[i].product_id);
            printf("Product Name: %s\n", orders[i].product_name);
            printf("Price: %.2f\n", orders[i].price);
            printf("Final Sum: %.2f\n", orders[i].final_sum);
            printf("Payment: %s\n", orders[i].payment);
            printf("Status: %s\n", orders[i].status);
            printf("User ID: %d\n", orders[i].user_id);
            printf("Cart ID: %d\n", orders[i].cart_id);
            printf("------------------\n");
        }
    }
    printf("====== END ORDERS ======\n");
}
void saveCart(struct cart *carts, int cartCount, int userId)
{
    FILE *file = fopen("cart.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "User ID: %d\n", userId);
    fprintf(file, "Cart Items:\n");
    for (int i = 0; i < cartCount; i++)
    {
        fprintf(file, "Product ID: %s, Product Name: %s, Price: %.2f, Sum: %.2f, Coupon: %s, Final Sum: %.2f, User ID: %d\n",
                carts[i].product_id, carts[i].product_name, carts[i].price, carts[i].sum, carts[i].coupon, carts[i].final_sum, carts[i].user_id);
    }
    fclose(file);
    printf("Cart saved to cart.txt\n");
}

void saveOrder(struct order *orders, int orderCount, int userId)
{
    FILE *file = fopen("orders.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "User ID: %d\n", userId);
    fprintf(file, "Orders:\n");
    for (int i = 0; i < orderCount; i++)
    {
        fprintf(file, "Order ID: %d, Product ID: %s, Product Name: %s, Price: %.2f, Final Sum: %.2f, Payment: %s, Status: %s, User ID: %d, Cart ID: %d\n",
                orders[i].id, orders[i].product_id, orders[i].product_name, orders[i].price, orders[i].final_sum, orders[i].payment, orders[i].status, orders[i].user_id, orders[i].cart_id);
    }
    fclose(file);
    printf("Orders saved to orders.txt\n");
}

int main()
{
    struct product *products = NULL;
    int productCount = 0;

    struct cart *carts = NULL;
    int cartCount = 0;

    struct user *users = NULL;
    int userCount = 0;

    struct order *orders = NULL;
    int orderCount = 0;

    int choice;
    do
    {
        printf("\n====== MENU ======\n");
        printf("1. Add new cart\n");
        printf("2. Update cart\n");
        printf("3. Delete cart\n");
        printf("4. Add new order\n");
        printf("5. Update order\n");
        printf("6. Delete order\n");
        printf("7. Check cart\n");
        printf("8. Check order\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char product_id[30], product_name[30];
            float price, sum, final_sum;
            int user_id;

            break;
        }
        case 2:
        {
            int id;
            float new_final_sum;
            updateCart(carts, cartCount, id, new_final_sum);
            break;
        }
        case 3:
        {
            int id;
            printf("Enter cart ID to delete: ");
            scanf("%d", &id);
            deleteCart(&carts, &cartCount, id);
            break;
        }
        case 4:
        {
            char product_id[30], product_name[30], payment[100], status[30];
            float price, final_sum;
            int user_id, cart_id;
            addOrder(&orders, &orderCount, product_id, product_name, price, final_sum, payment, status, user_id, cart_id);
            break;
        }
        case 5:
        {
            int id;
            char new_status[30];
            printf("Enter order ID to update: ");
            scanf("%d", &id);
            printf("Enter new status: ");
            scanf("%s", new_status);
            updateOrder(orders, orderCount, id, new_status);
            break;
        }
        case 6:
        {
            int id;
            printf("Enter order ID to delete: ");
            scanf("%d", &id);
            deleteOrder(&orders, &orderCount, id);
            break;
        }
        case 7:
        {
            int user_id;
            printf("Enter user ID to check carts: ");
            scanf("%d", &user_id);
            checkCart(carts, cartCount, user_id);
            break;
        }
        case 8:
        {
            int user_id;
            printf("Enter user ID to check orders: ");
            scanf("%d", &user_id);
            checkOrder(orders, orderCount, user_id);
            break;
        }
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 0);

    // Free allocated memory
    free(products);
    free(carts);
    free(users);
    free(orders);

    return 0;
}
