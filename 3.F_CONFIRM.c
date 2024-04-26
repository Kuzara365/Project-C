


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
