
void ingresarProducto(char id[10][10], char nombre[10][20], float precio[10], int stock[10], int *cont);
float calcularTotalInventario(float precio[10], int stock[10], int cont);
void productoMasCaro(float precio[10], char nombre[10][20], int cont);
void productoMasBarato(float precio[10], char nombre[10][20], int cont);
float calcularPrecioPromedio(float precio[10], int cont);
void buscarProducto(char nombre[10][20], float precio[10], int cont, char nombreBuscado[20]);
void verProductos(char id[10][10], char nombre[10][20], float precio[10], int stock[10], int cont);

