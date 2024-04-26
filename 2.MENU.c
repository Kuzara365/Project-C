#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MainMenu()
{
	printf("|=============ONLINE SALES SYSTEM==============|\n");
	printf("|==  0.Exit.                                 ==|\n");
    printf("|==  1.Check goods.                          ==|\n");
	printf("|==  2.Cart: check your bills.               ==|\n");
	printf("|==  3.Check purchased orders.               ==|\n");
	printf("|==============================================|\n");
} 

void MenuSales()
{
	printf("|****************SALES PAGE******************|\n");
	printf("|**0.Exit.                                 **|\n");
	printf("|**1.Select goods.                         **|\n"); 
	printf("|********************************************|\n");
}

void CheckCart()
{
	printf("|*****************CART*****************|\n");
	printf("|**0.Move to menu.                   **|\n");
	printf("|**1.Select bills.                   **|\n");
	printf("|**************************************|\n");
}