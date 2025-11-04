#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para ingresar un producto
void ingresarProducto(char id[10][10], char nombre[10][20], float precio[10], int stock[10], int *cont) {
    if (*cont >= 10) {
        printf("No se pueden ingresar mas productos. Límite alcanzado.\n");
        return;
    }

    printf("Ingrese el ID del producto %d: ", *cont);
    scanf("%s", id[*cont]);
    while (getchar() != '\n'); // limpiar buffer 

    printf("Ingrese el nombre del producto %d: ", *cont);
    fgets(nombre[*cont], 20, stdin);
    int len = strlen(nombre[*cont]) - 1;
    if (nombre[*cont][len] == '\n') nombre[*cont][len] = '\0';

    // Validar precio solo positivos
    while (1) {
        printf("Ingrese el precio del producto %d: ", *cont);
        if (scanf("%f", &precio[*cont]) != 1 || precio[*cont] <= 0) {
            printf("Entrada invalida. Ingrese un numero positivo.\n");
            while (getchar() != '\n'); // limpiar buffer
        } else {
            break;
        }
    }
    // Validar stock solo enteros positivos
    while (1) {
        printf("Ingrese el stock del producto %d: ", *cont);
        if (scanf("%d", &stock[*cont]) != 1 || stock[*cont] <= 0) {
            printf("Entrada inválida. Ingrese un número entero positivo.\n");
            while (getchar() != '\n'); // limpiar buffer
        } else {
            break;
        }
    }

    (*cont)++;
}
// Calcular el total del inventario
float calcularTotalInventario(float precio[10], int stock[10], int cont) {
    float total = 0;
    for (int i = 0; i < cont; i++) {
        total += precio[i] * stock[i];
    }
    return total;
}
// Producto más caro
void productoMasCaro(float precio[10], char nombre[10][20], int cont) {
    if (cont == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    float max = precio[0];
    int index = 0;
    for (int i = 1; i < cont; i++) {
        if (precio[i] > max) {
            max = precio[i];
            index = i;
        }
    }
    printf("El producto mas caro es: %s con un precio de %.2f\n", nombre[index], max);
}
// Producto más barato
void productoMasBarato(float precio[10], char nombre[10][20], int cont) {
    if (cont == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    float min = precio[0];
    int index = 0;
    for (int i = 1; i < cont; i++) {
        if (precio[i] < min) {
            min = precio[i];
            index = i;
        }
    }
    printf("El producto mas barato es: %s con un precio de %.2f\n", nombre[index], min);
}
// Precio promedio
float calcularPrecioPromedio(float precio[10], int cont) {
    if (cont == 0) return 0;
    float total = 0;
    for (int i = 0; i < cont; i++) {
        total += precio[i];
    }
    return total / cont;
}
// Buscar producto
void buscarProducto(char nombre[10][20], float precio[10], int cont, char nombreBuscado[20]) {
    for (int i = 0; i < cont; i++) {
        if (strcmp(nombre[i], nombreBuscado) == 0) {
            printf("Producto encontrado: %s, Precio: %.2f\n", nombre[i], precio[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}
// 🔹 Nueva función: Ver todos los productos
void verProductos(char id[10][10], char nombre[10][20], float precio[10], int stock[10], int cont) {
    if (cont == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n-------- LISTA DE PRODUCTOS --------\n");
    printf("#\tID\t\tNombre\t\t\tPrecio\t\tStock\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < cont; i++) {
        printf("%d\t%s\t\t%-15s\t%.2f\t\t%d\n", i + 1, id[i], nombre[i], precio[i], stock[i]);
    }

    printf("------------------------------------------------------------\n");
}
