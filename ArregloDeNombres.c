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
int buscarNombrePorPalabra(char *V[], char *pal, int TAM);
void buscarNombrePorID(char *V[], int x, int TAM); // funcion buscar nombre por ID

int main(){

int TAM = 5;
char *V[TAM];
char buff[50];
int opcion;

    for(int i = 0 ; i < TAM; i++){
    printf("\n Ingrese %d nombres de personas (ID n: %d): ",TAM, i+1);
    gets(buff);

    int tamCadena = strlen(buff);

    V[i] = (char *)malloc(tamCadena*sizeof(char)+1);
    strcpy(V[i], buff);
    }

    mostrarPersonas(V, TAM);

    do{
        do{
            printf("\n----------SELECCIONE----------\n");
            printf("Opcion 1: Buscar por ID\n");
            printf("Opcion 2: Buscar por palabra\n");
            printf("Opcion 0: Salir.\n");
            scanf("%d", &opcion);
            fflush(stdin);
        }while(opcion < 0 || opcion > 2);
        switch (opcion)
        {
            case 1: {  // busqueda por id
                int id;
                printf("Ingrese el ID deseado: \n");
                scanf("%d", &id);
                fflush(stdin);
                buscarNombrePorID(V, id, TAM);
            break;
            }
            case 2: {  // busqueda por palabra
                fflush(stdin); // me quedaba un error al hacer merge por un tema entre el scanf y el gets
                char pal[50];
                printf("\nIngrese la palabra a buscar: ");
                gets(pal);
                int buscar = buscarNombrePorPalabra(V, pal, TAM); // pide retornar -1 si no esta
                if(buscar == -1){
                    printf("\n No se encontro la palabra buscada.");
                }else{
                    printf("\n Lo encontrado: %s", V[buscar]);
                }
            break;
            }
            default:
            break;
        }
    }while(opcion != 0); 

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

void buscarNombrePorID(char *V[], int x, int TAM){
    if(x >= 1 && x <= TAM){
        puts(V[x-1]);
    }else{
        printf("\n No se encontró el valor buscado.");
    }
}

int buscarNombrePorPalabra(char *V[], char *pal, int TAM){
    for(int i = 0; i < TAM; i++){
    if(strstr(V[i], pal) != NULL){
        return i;
    }
}
return -1;
}