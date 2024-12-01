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
                printf("Por favor, ingrese un número válido: ");
                scanf("%s", entradaRequerida);
            }
            requeridos[i] = convertirACadenaNumerica(entradaRequerida);

            printf("Ingrese la nueva cantidad disponible: ");
            char entradaDisponible[10];
            scanf("%s", entradaDisponible);
            while (!esNumeroValido(entradaDisponible)) {
                printf("Por favor, ingrese un número válido: ");
                scanf("%s", entradaDisponible);
            }
            disponibles[i] = convertirACadenaNumerica(entradaDisponible);

            printf("Material editado con éxito.\n");
            return;
        }
    }
    printf("Material no encontrado.\n");
}
