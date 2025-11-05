#include <stdio.h>
#include "funciones.h"

int main() {
    char id[10][10], nombre[10][20];
    float precio[10];
    int stock[10];
    int cont = 0;
    int opc;
    char nombreBuscado[20];

    do {
        printf("\nSelecciona una opcion:\n");
        printf("1. Ingresar un producto\n");
        printf("2. Calcular el precio total del inventario\n");
        printf("3. Producto mas caro\n");
        printf("4. Producto mas barato\n");
        printf("5. Precio promedio\n");
        printf("6. Buscar un producto\n");
        printf("7. Ver todos los productos\n");
        printf("8. Salir\n");
        printf(">> ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                cont = ingresarProducto(id, nombre, precio, stock, cont);
                break;
            case 2:
                printf("El precio total del inventario es: %.2f\n", calcularTotalInventario(precio, stock, cont));
                break;
            case 3:
                productoMasCaro(precio, nombre, cont);
                break;
            case 4:
                productoMasBarato(precio, nombre, cont);
                break;
            case 5:
                printf("El precio promedio de los productos es: %.2f\n", calcularPrecioPromedio(precio, cont));
                break;
            case 6:
                printf("Ingrese el nombre del producto a buscar: ");
                scanf("%s", nombreBuscado);
                buscarProducto(nombre, precio, cont, nombreBuscado);
                break;
            case 7:
                verProductos(id, nombre, precio, stock, cont);
                break;
            case 8:
                printf("Hasta luego.\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }

    } while (opc != 8);

    return 0;
}
