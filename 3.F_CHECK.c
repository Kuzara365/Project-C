#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	int sum;
	char payment[100];
	char status[30];
	int user_id;
};

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
    FILE *userData = fopen("E:/Project C/Data/user.csv", "r");
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

//Display user
void displayUser(struct user *users, struct order *order, int userCount)
{
    for (int i = 1; i < userCount; i++)
    {
        if (users[i - 1].id == order[i - 1].user_id)
        {
            printf("User ID: %d", users[i].id);
            printf("\nName: %s\n", users[i].name);
            printf("Address: %s\n", users[i].address);
            printf("Phone number: %d\n", users[i].phone_number);
            printf("\n");
        }
    }
    printf("--------------------------------------\n");
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
            fprintf(orderData, "%d, ", orders[i].sum);
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
            (*orders)[*orderCount - 1].sum = atoi(data);
            
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
    int final_sum = 0;
    for (int i = 1; i < orderCount; i++)
    {
        if (orders[i].id != orders[i - 1].id)
        {
            
            if (final_sum != 0){
                printf("\t\t\t\tFinal sum: %d\n", final_sum);
                }
            printf("--------------------------------------\n");
            final_sum = 0;
            printf("ID Order: %d\n", orders[i].id);
            printf("User ID: %d\n", orders[i].user_id);
            printf("Payment type: %s\n", orders[i].payment);
            printf("Status: %s\n", orders[i].status);
            printf("Product \t Quantity\tPrice\tSum\n");
        }
        printf("%s \t\t\t", orders[i].product_name);
        printf("%d \t", orders[i].quantity);
        printf("%d \t", orders[i].price);
        printf("%d \t", orders[i].sum);
        printf("\n");
        final_sum += orders[i].sum;
    }
    printf("\t\t\t\tFinal sum: %d\n", final_sum);
}  

void f_check(){
    struct user *users = NULL;
    struct order *orders = NULL;
    int userCount = 0;
    int orderCount = 0;
    printf("Customer's information:\n");
    ExportUser(users,  userCount);
    readUser(&users, &userCount);
    displayUser(users, orders, userCount);

    printf("Bill:\n");
    readOrder(&orders, &orderCount);
    displayOrder(orders, orderCount);
};