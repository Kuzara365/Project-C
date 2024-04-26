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
