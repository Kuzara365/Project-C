#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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