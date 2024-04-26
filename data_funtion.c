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
	char pruct_name[30];
	int price;
	int sum;
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
	char product_name[30];
    int quantity;
	int price;
	int final_sum;
	char payment[100];
	char status[30];
	int user_id;
};

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_LENGTH 20
#define MAX_ITEMS 10

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

//Export user to file
void ExportUser(struct user *users, int userCount)
{
    FILE *userData = fopen("user.csv", "a");
    if (userData == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    else
    {
        for (int i = 0; i < userCount; i++)
        {
            fprintf(userData, "%d, ", users[i].id);
            fprintf(userData, "%s, ", users[i].name);
            fprintf(userData, "%s, ", users[i].address);
            fprintf(userData, "%d, ", users[i].phone_number);
        }
        fclose(userData);
    }
}

//read user from file
void readUser(struct user **users, int *userCount)
{
    char line[100];
    char *data;
    FILE *userData = fopen("user.csv", "r");
    if (userData == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    else
    {
        while (fgets(line, 100, userData) != NULL)
        {
            (*userCount)++;
            *users = (struct user *)realloc(*users, *userCount * sizeof(struct user));

            data = strtok(line, ",");
            (*users)[*userCount - 1].id = atoi(data);

            data = strtok(NULL, ",");
            strcpy((*users)[*userCount - 1].name, data);

            data = strtok(NULL, ",");
            strcpy((*users)[*userCount - 1].address, data);

            data = strtok(NULL, ",");
            (*users)[*userCount - 1].phone_number = atoi(data);
        }
        fclose(userData);
    }
}

//Display user compared to userID in Order
void displayUser(struct user *users, struct order *order, int userCount)
{
    for (int i = 1; i < userCount; i++)
    {
        for (int j = 1; j < userCount; j++)
        {
            if (users[i].id == order[j].user_id)
            {
                printf("Name: %s\n", users[i].name);
                printf("Address: %s\n", users[i].address);
                printf("Phone number: %d\n", users[i].phone_number);
                printf("--------------------------------------\n");
            }
        }
    }
}

void ExportOrder(struct order *orders, int orderCount)
{
    FILE *orderData = fopen("order.csv", "a");
    if (orderData == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    else
    {
        for (int i = 0; i < orderCount; i++)
        {
            fprintf(orderData, "%d, ", orders[i].id);
            fprintf(orderData, "%s, ", orders[i].product_name);
            fprintf(orderData, "%d, ", orders[i].quantity);
            fprintf(orderData, "%d, ", orders[i].price);
            fprintf(orderData, "%d, ", orders[i].final_sum);
            fprintf(orderData, "%s, ", orders[i].payment);
            fprintf(orderData, "%s, ", orders[i].status);
            fprintf(orderData, "%d, ", orders[i].user_id);
        }
        fclose(orderData);
    }
}

//Import order from file
void readOrder(struct order **orders, int *orderCount)
{
    char line[100];
    char *data;
    FILE *orderData = fopen("order.csv", "r");
    if (orderData == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    else
    {
        while (fgets(line, 1000, orderData) != NULL)
        {
            (*orderCount)++;
            *orders = (struct order *)realloc(*orders, *orderCount * sizeof(struct order));

            data = strtok(line, ",");
            (*orders)[*orderCount - 1].id = atoi(data);

            data = strtok(NULL, ",");
            strcpy((*orders)[*orderCount - 1].product_name, data);

            data = strtok(NULL, ",");
            (*orders)[*orderCount - 1].quantity = atoi(data);

            data = strtok(NULL, ",");
            (*orders)[*orderCount - 1].price = atoi(data);

            data = strtok(NULL, ",");
            (*orders)[*orderCount - 1].final_sum = atoi(data);

            data = strtok(NULL, ",");
            strcpy((*orders)[*orderCount - 1].payment, data);

            data = strtok(NULL, ",");
            strcpy((*orders)[*orderCount - 1].status, data);

            data = strtok(NULL, ",");
            (*orders)[*orderCount - 1].user_id = atoi(data);
        }
        fclose(orderData);
    }
}

void displayOrder(struct order *orders, int orderCount)
{
    printf("List of order \n");
    for (int i = 1; i < orderCount; i++)
    {
        printf("ID Order: %d \n", orders[i].id);
        printf("Product: %s   ", orders[i].product_name);
        printf("Quantity %d   ", orders[i].quantity);
        printf("Price %d   ", orders[i].price);
        printf("Sum %d\n", orders[i].final_sum);
        printf("Payment type: %s\n", orders[i].payment);
        printf("Status: %s\n", orders[i].status);
        printf("User ID: %d\n", orders[i].user_id);
    }

}

int main() {
	struct product *products = NULL;
    struct order *orders = NULL;
    struct user *users = NULL;
    int userCount = 0, orderCount = 0, productCount = 0;
    int choice;
	do {
        readProduct(&products, &productCount);
        readOrder(&orders, &orderCount);
        readUser(&users, &userCount);
        printf("1. Display product\n");
        printf("2. Read order from file\n");
        printf("3. Export order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            displayProduct(products, productCount);
            break;
        case 2:
            displayOrder(orders, orderCount);
            displayUser(users, orders, userCount);
            break;
        case 3:
            ExportOrder(orders, orderCount);
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);
    return 0;
}