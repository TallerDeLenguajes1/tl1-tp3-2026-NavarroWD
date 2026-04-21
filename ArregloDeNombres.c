/* Nota 1: La librería más común para trabajar con cadenas de caracteres es string.h. Algunas 
de sus funciones más importantes son: 
• strlen(<cadena>): Devuelve la longitud de la cadena sin tomar en cuenta el caracter de 
final de cadena. 
• strcpy(<cadena_destino>, <cadena_origen>) : Copia el contenido de 
<cadena_origen> en <cadena_destino>. 
• strcat(<cadena_destino>, <cadena_origen>) : Concatena el contenido de 
<cadena_origen> al final de <>. 
• strcmp(<cadena1>, <cadena2>) : Compara las dos cadenas y devuelve un 0 si las dos 
cadenas son iguales, un número negativo si <cadena1> es menor que <cadena2> y un número 
positivo (mayor que cero) si <cadena1> es mayor que <cadena2> */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mostrarPersonas(char *V[], int x); // mando el vector, con cantidad de personas
void buscarNombre(char *V[], int x, int TAMA); // funcion buscar nombre por ID

int main(){

int TAM = 5;
char *V[TAM];
char buff[50];

    for(int i = 0 ; i < TAM; i++){
    printf("\n Ingrese %d nombres de personas (ID n: %d): ",TAM, i+1);
    gets(buff);

    int tamCadena = strlen(buff);

    V[i] = (char *)malloc(tamCadena*sizeof(char)+1);
    strcpy(V[i], buff);
    }

    
    // mostrarPersonas(V, TAM);

    // Ingreso y busqueda del ID
    int id;
    printf("Ingrese el ID deseado: \n");
    scanf("%d", &id);
    buscarNombre(V, id, TAM);

    // Liberacion de memoria 

    for(int i = 0; i<TAM; i++){
    free(V[i]);
}

return 0;
}

void mostrarPersonas(char *V[], int x){
    for(int i = 0; i < x; i++){
        printf("\n Nombre n%d: %s \n", i+1, V[i]);
    }
}

void buscarNombre(char *V[], int x, int TAM){
    if(x >= 1 && x < TAM){
        puts(V[x-1]);
    }else{
        printf("\n No se encontró el valor buscado.");
    }
}