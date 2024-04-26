#ifndef F_BUY_H
#define F_BUY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f_buy();
void readProduct(struct product **products, int *productCount);
void displayProduct(struct product *products, int productCount);


#endif

/*
typedef struct {
    char diemden[50];
    char diemdi[50];
    char thoigiankhoihanh[20];
    char thoigianhacanh[20];
    char hanghangkhong[30];
    int thoigianbay;
    char trangthai[30];
} Flight;

int calculateTravelTime(char departurePoint[], char destination[]);

void addFlight(Flight flights[], int *currentFlightID);

void changeFlight(Flight flights[]);

void deleteFlight(Flight flights[], int *currentFlightID);

void showflights(Flight flights[], int index);

void MenuFlights(Flight flights[], int *currentFlightID);

#endif
*/