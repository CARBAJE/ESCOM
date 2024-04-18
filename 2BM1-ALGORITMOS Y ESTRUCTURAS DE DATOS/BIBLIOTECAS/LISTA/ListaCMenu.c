#include "Lista.h"

void MenuLista(Lista l , int tam , int* error){
    int opcion = 0;
    int contador = 0;
    int posicion = 0;
    Dato valor = 0;

    while(contador < tam){
            printf("MENU LITSTA\n");
            printf("1-Instertar por Derecha\n");
            printf("2-Instertar por Izquieda\n");
            printf("3-Insertar por Posicion\n");
            printf("4-Extraer por Derecha\n");
            printf("5-Extraer por Izquieda\n");
            printf("6-Extraer por Posicion\n");
            printf("7-Imprimir Lista\n");
            printf("8-Copiar Lista\n");
            printf("9-Vaciar Lista\n");
            printf("0-Destruir LIsta\n");
            printf("Ingrese el metodo por el que quiere anadir un nodo: "); 
            scanf("%i", &opcion);
            
            if(opcion >0 && opcion < 4)
                valor = IngresarDatos(opcion , &posicion , error);

            printf("\n");
            //printf("SU LLEGUE AQUI");
            switch(opcion){
                case 1:
                    InsertarDerecha(l , valor , error);
                    if(*error == 0)
                        contador++;
                break;
                case 2:
                    InsertarIzquierda(l , valor , error);
                    if(*error == 0)
                        contador++;
                break;
                case 3:
                    InsertarPosicion(l , valor ,posicion , error);
                    if(*error == 0)
                        contador++;
                break;
                case 4:
                    valor = ExtraerDerecha(l , error);
                    if(*error == 0)
                        contador--;
                break;
                case 5:
                    valor = ExtraerIzquierda(l , error);
                    if(*error == 0)
                        contador--;
                break;
                case 6:
                    printf("Ingrese la pocion a extraer: ");
                    scanf("%i", &posicion);
                    //printf("LLEGUE AQUI"); /////////////////////////////////////
                    valor = ExtraerPosicion(l , posicion , error);
                    if(*error == 0)
                        contador--;
                break;
                case 7:
                    ImprimirLista(l , error);
                break;
                case 8:
                    /*Lista ll = CopiarLista(l , error);
                    if(*error = 0 && *ll != NULL){
                        printf("Elementos de la lista copiada:\n");
                        ImprimirLista(ll , error);
                    }
                    else{
                        printf("ERROR '%i'. NO SE REALIZO LA COPIA", *error);
                    }*/
                    printf("OPCION NO DISPONIBLE POR EL MOMENTO\n");
                break;
                case 9:
                    VaciarLista(l , error);
                    if(*error == 0)
                        contador = 0;
                break;
                case 0:
                    DestruirLista(l , error);
                    if(*error == 0)
                        break;
                default:
                    printf("Ingrese un valor valido\n");
                break;
            }
            if(opcion >3 && opcion < 7){
                printf("Valor extraido: %i\n", valor);
            }
            printf("\n");
        }
}

Dato IngresarDatos(int opcion , int* posicion ,  int* error){
    Dato valor = 0;
    printf("Ingrese el dato que desee añadir a la lista: ");
    scanf("%i", &valor);
    if(opcion == 3){
        printf("Ingrese la posicion en la que desae añadir el nodo: ");
        scanf("%i" , posicion);
    }
    return valor;
}