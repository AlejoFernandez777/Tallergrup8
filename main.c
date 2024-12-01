#include <stdio.h>
#include "solucion1.h"

int main() {
    char productNames[MAX_PRODUCTS][MAX_NAME_LEN];
    int quantities[MAX_PRODUCTS], times[MAX_PRODUCTS], resources[MAX_PRODUCTS];
    int productCount = 0, option;
    int timeLimit, resourceLimit;

    printf("Ingrese el tiempo máximo disponible: ");
    scanf("%d", &timeLimit);
    printf("Ingrese los recursos máximos disponibles: ");
    scanf("%d", &resourceLimit);

    do {
        printf("\n--- Menú ---\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Calcular totales\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1: addProduct(productNames, quantities, times, resources, &productCount); break;
            case 2: editProduct(productNames, quantities, times, resources, productCount); break;
            case 3: deleteProduct(productNames, quantities, times, resources, &productCount); break;
            case 4: displayProducts(productNames, quantities, times, resources, productCount); break;
            case 5: calculateTotals(productNames, quantities, times, resources, productCount, timeLimit, resourceLimit); break;
            case 6: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (option != 6);

    return 0;
}
