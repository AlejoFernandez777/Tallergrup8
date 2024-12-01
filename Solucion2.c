#include <stdio.h>
#include <string.h>
#include "funciones.h" // Incluye las declaraciones y constantes necesarias

// Función para editar un material
void editarMaterial(char materiales[][MAX_NOMBRE], int requeridos[], int disponibles[], int numMateriales) {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del material que desea editar: ");
    getchar(); // Limpia el buffer.
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // Elimina el salto de línea.

    for (int i = 0; i < numMateriales; i++) {
        if (strcmp(materiales[i], nombre) == 0) {
            printf("Editando material '%s'\n", nombre);
            printf("Ingrese el nuevo nombre del material: ");
            fgets(materiales[i], MAX_NOMBRE, stdin);
            materiales[i][strcspn(materiales[i], "\n")] = '\0';

            printf("Ingrese la nueva cantidad requerida: ");
            char entradaRequerida[10];
            scanf("%s", entradaRequerida);
            while (!esNumeroValido(entradaRequerida)) {
                printf("Por favor, ingrese un numero válido: ");
                scanf("%s", entradaRequerida);
            }
            requeridos[i] = convertirACadenaNumerica(entradaRequerida);

            printf("Ingrese la nueva cantidad disponible: ");
            char entradaDisponible[10];
            scanf("%s", entradaDisponible);
            while (!esNumeroValido(entradaDisponible)) {
                printf("Por favor, ingrese un numero valido: ");
                scanf("%s", entradaDisponible);
            }
            disponibles[i] = convertirACadenaNumerica(entradaDisponible);

            printf("Material editado con exito.\n");
            return;
        }
    }
    printf("Material no encontrado.\n");
}

// Función para eliminar un material
void eliminarMaterial(char materiales[][MAX_NOMBRE], int requeridos[], int disponibles[], int *numMateriales) {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del material que desea eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < *numMateriales; i++) {
        if (strcmp(materiales[i], nombre) == 0) {
            printf("Eliminando material '%s'\n", nombre);

            // Desplazar los elementos restantes
            for (int j = i; j < *numMateriales - 1; j++) {
                strcpy(materiales[j], materiales[j + 1]);
                requeridos[j] = requeridos[j + 1];
                disponibles[j] = disponibles[j + 1];
            }

            (*numMateriales)--; // Reducir el contador de materiales
            printf("Material eliminado con exito.\n");
            return;
        }
    }
    printf("Material no encontrado.\n");
}




// Valida si una cadena contiene solo números
int esNumeroValido(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0; // No es un número
        }
    }
    return 1; // Es un número válido
}

// Convierte una cadena numérica a un número entero
int convertirACadenaNumerica(char *str) {
    int numero = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        numero = numero * 10 + (str[i] - '0');
    }
    return numero;
}

// Valida si una cadena contiene solo letras
int esTextoValido(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')) {
            return 0; // Contiene caracteres no alfabéticos
        }
    }
    return 1; // Solo contiene letras
}

// Función para ingresar materiales
void ingresarMateriales(char materiales[][MAX_NOMBRE], int requeridos[], int *numMateriales) {
    char cantidadStr[10];
    printf("Ingrese el numero de materiales: ");
    scanf("%s", cantidadStr);

    while (!esNumeroValido(cantidadStr)) {
        printf("Por favor, ingrese un numero valido: ");
        scanf("%s", cantidadStr);
    }

    *numMateriales = convertirACadenaNumerica(cantidadStr);
    getchar(); // Limpia el buffer antes de leer cadenas con espacios.

    for (int i = 0; i < *numMateriales; i++) {
        printf("Ingrese el nombre del material %d: ", i + 1);
        fgets(materiales[i], MAX_NOMBRE, stdin);
        materiales[i][strcspn(materiales[i], "\n")] = '\0'; // Elimina el salto de línea.

        printf("Ingrese la cantidad requerida de %s: ", materiales[i]);
        scanf("%s", cantidadStr);

        while (!esNumeroValido(cantidadStr)) {
            printf("Por favor, ingrese un numero valido: ");
            scanf("%s", cantidadStr);
        }

        requeridos[i] = convertirACadenaNumerica(cantidadStr);
        getchar(); // Limpia el buffer antes de la siguiente iteración.
    }
}

// Función para ingresar disponibilidad de materiales
void ingresarDisponibilidad(char materiales[][MAX_NOMBRE], int disponibles[], int numMateriales) {
    char cantidadStr[10];
    int cantidad;

    for (int i = 0; i < numMateriales; i++) {
        printf("Ingrese la cantidad disponible de %s: ", materiales[i]);
        scanf("%s", cantidadStr);

        while (!esNumeroValido(cantidadStr)) {
            printf("Por favor, ingrese un numero valido: ");
            scanf("%s", cantidadStr);
        }

        cantidad = convertirACadenaNumerica(cantidadStr);
        disponibles[i] = cantidad;
    }
}

// Función para mostrar el estado de los materiales
void mostrarEstadoMateriales(char materiales[][MAX_NOMBRE], int requeridos[], int disponibles[], int numMateriales) {
    printf("\nReporte de materiales:\n");
    printf("Material    Requerido   Disponible   Estado\n");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < numMateriales; i++) {
        // Determina el estado del material (cumplido o falta)
        char estado[10];
        if (disponibles[i] >= requeridos[i]) {
            strcpy(estado, "Cumplido");
        } else {
            strcpy(estado, "Falta");
        }

        // Imprime la fila formateada
        printf("%-10s %-11d %-11d %s\n", materiales[i], requeridos[i], disponibles[i], estado);
    }
}
