#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"
#include "f_buy.h"
#include "f_cart.h"
#include "f_confirm"


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
	char product_id[30];
	char product_name[30];
	int price;
	int final_sum;
	char payment[100];
	char status[30];
	int user_id;
	int cart_id;
};

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_LENGTH 20
#define MAX_ITEMS 10

int lastAssignedID = 0;







//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


int main()
{
	struct Product products[NUM_PRODUCTS] = {
        {001, "oreon", 100, 15000},
        {002, "nabati", 100, 30000},
        {003, "coca", 100, 10000},
        {004, "pepsi", 100, 10000},
        {005, "chocoPie", 100, 30000},
        {006, "custas", 100, 32000},
        {007, "Alpenliepe", 100, 12000},
        {011, "7up", 100, 7000},
        {012, "mirinda", 100, 8000},
        {013, "Nestle", 100, 50000},
        {014, "Milka", 100, 13000},
        {015, "Kitkat", 100, 20000},
        {016, "Danisa", 100, 50000},
        {017, "Lu", 100, 35000},
        {020, "solie", 100, 25000},
        {021, "Roca", 100, 30000},
        {022, "starburst", 100, 24000},
        {023, "Nerds", 100, 12000}
    };
	void readProduct(struct product *Arrproduct, int *number);
	MainMenu();
    int option=0;
	do{
		printf("Choose your option: ");
		scanf("%d", &option);
		switch (option){
			case 0:{
				printf("\n");
				printf("\n");
				printf("You have exited the application!\n");
				break;
			}
			case 1:{
				printf("\n");
				printf("\n");
				printf("List goods: \n");
			    // func: in san pham  
			    void showProduct(struct product *Arrproduct, int number);
			    
			    MenuSales();
			    int n;
				printf("Enter your option: ");
				scanf("%d",&n);
			    switch(n){
			    	case 0:{
			    		// func: chuyen ve giao dien chinh 
			    		printf("Move to Menu\n");
						break;
					}
					case 1:{// bat dau lua chon mat hang mong muon 
						void addCart();
						break;
					}
					default:{
                        printf("Invalid option!\n");
						break;
				  	}
				}
			}
			case 2 :{// Cart : check bills 
		        printf("\n");
		        printf("\n");	        
				//func: hien thi hoa don dang luu tru (hoa don chua thanh toan)
			    CheckCart();
			    int opt = 0;
				switch (opt){
					case 0:{// thoat ve menu

						break;
					}
					case 1:{// lua chon gio hang 

						break;
					}
                    default:{
                        printf("Invalid option!\n");
                        break;
                    }
				}
			}
			case 3:{ //check don mua 
				printf("\n");
				printf("\n");
				// func: check don mua 

				break;
			}
			default:{
                printf("Invalid option!\n");
                break;
            }		
    	}
	}while (option != 0);
}