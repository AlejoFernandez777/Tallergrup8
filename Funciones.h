#ifndef SOLUCION1_H
#define SOLUCION1_H

#define MAX_PRODUCTS 5
#define MAX_NAME_LEN 50

// Prototipos de funciones
void addProduct(char productNames[][MAX_NAME_LEN], int quantities[], int times[], int resources[], int* productCount);
void editProduct(char productNames[][MAX_NAME_LEN], int quantities[], int times[], int resources[], int productCount);
void deleteProduct(char productNames[][MAX_NAME_LEN], int quantities[], int times[], int resources[], int* productCount);
void calculateTotals(char productNames[][MAX_NAME_LEN], int quantities[], int times[], int resources[], int productCount, int timeLimit, int resourceLimit);
void displayProducts(char productNames[][MAX_NAME_LEN], int quantities[], int times[], int resources[], int productCount);

#endif
