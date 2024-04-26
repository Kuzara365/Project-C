


//import data from product.csv
void readProduct(struct product *Arrproduct, int *number)
{
	FILE *file;
	file = fopen("E:/Project C/product.csv", "r");
	if (file == NULL)
	{
		printf("Can't open file\n");
	}
	else
	{
		while (!feof(file))
		{
			fscanf(file, "%d,%c,%d,%f\n", &Arrproduct[*number].id);
			fscanf(file, "%c",Arrproduct[*number].product_name);
			fscanf(file, "%d", &Arrproduct[*number].remain);
			fscanf(file, "%f", &Arrproduct[*number].price);
			(*number)++;
		}
	}
	fclose(file);
}


//show product/;llkkkkkkkkk jkllkl
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
void addCart(struct cart **carts, int *cartCount, char *product_id, char *product_name, float price, float sum, char *coupon, float final_sum, int user_id)
{
    *carts = (struct cart *)realloc(*carts, (*cartCount + 1) * sizeof(struct cart));
    (*carts)[*cartCount].id = ++lastAssignedID; // Increment and assign new ID
    strcpy((*carts)[*cartCount].product_id, product_id);
    strcpy((*carts)[*cartCount].product_name, product_name);
    (*carts)[*cartCount].price = price;
    (*carts)[*cartCount].sum = sum;
    //strcpy((*carts)[*cartCount].coupon, coupon);
    (*carts)[*cartCount].final_sum = final_sum;
    (*carts)[*cartCount].user_id = user_id;
    (*cartCount)++;
    printf("Created new cart successfully.\n");
}