#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={
    "Galletas",
    "Snack",
    "Cigarrillos",
    "Caramelos",
    "Bebidas"
}; 

struct {
int ProductoID;      //Numerado en ciclo iterativo   
int Cantidad;        // entre 1 y 10 
char *TipoProducto;   // Algún valor del arreglo TiposProductos       
float PrecioUnitario; // entre 10 - 100 
}typedef Producto;

struct {   
int ClienteID;         // Numerado en el ciclo iterativo       
char *NombreCliente;   // Ingresado por usuario  
int CantidadProductosAPedir; // (aleatorio entre 1 y 5) 
Producto *Productos;   //El tamaño de este arreglo depende de la variable // “CantidadProductosAPedir” 
}typedef Cliente;   

float costoTotal(Producto p); 

int main(){

srand(time(NULL));

// Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de clientes.

int cantC;


    printf("\n ////// DISTRIBUIDORA ////// \n");
do{
    printf("\n Ingrese la cantidad de clientes: ");
    scanf("%d", &cantC);
    fflush(stdin);
}while(cantC < 1 || cantC > 5);

// Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior. 

Cliente *clientes = malloc(cantC * sizeof(Cliente));

    for(int i = 0; i < cantC; i++){
        float totalCliente = 0;
        clientes[i].ClienteID = i+1;
        clientes[i].NombreCliente = malloc(50*sizeof(char));
        printf("\n Ingrese el nombre del cliente n%d: ", i+1);
        gets(clientes[i].NombreCliente);
        fflush(stdin);
        clientes[i].CantidadProductosAPedir = rand()% 5 + 1;
        clientes[i].Productos = malloc(clientes[i].CantidadProductosAPedir*sizeof(Producto));

         printf("\n ----------- CLIENTE -----------");
        printf("\n Nombre Cliente: %s", clientes[i].NombreCliente);
        printf("\n ClienteID: %d", clientes[i].ClienteID);
        printf("\n Cantidad de Productos: %d", clientes[i].CantidadProductosAPedir);

        for(int j = 0; j<clientes[i].CantidadProductosAPedir;j++){
            clientes[i].Productos[j].ProductoID = j+1;
            clientes[i].Productos[j].Cantidad = rand() % 10+1;
            clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];

            Producto p = clientes[i].Productos[j];
            float costo = costoTotal(p);
            totalCliente += costo;

            printf("\n ----------- PRODUCTOS -----------");
            printf("\n Producto ID: %d", clientes[i].Productos[j].ProductoID);
            printf("\n Cantidad: %d", clientes[i].Productos[j].Cantidad);
            printf("\n Precio Unitario: %.2f", clientes[i].Productos[j].PrecioUnitario);
            printf("\n Nombre del Producto: %s", clientes[i].Productos[j].TipoProducto);

            
        }
         printf("\n ----------- COSTO TOTAL -----------");
        printf("\n CostoTotal: %.2f \n", totalCliente);

    }


    for (int i = 0; i < cantC; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    
    free(clientes);

return 0;
}


float costoTotal(Producto p){
    return (p.Cantidad * p.PrecioUnitario);
}