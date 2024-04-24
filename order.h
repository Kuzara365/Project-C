#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for order
typedef struct order {
    char *name;
    int quantity;
    float price;
    struct order *next;
} Order;
