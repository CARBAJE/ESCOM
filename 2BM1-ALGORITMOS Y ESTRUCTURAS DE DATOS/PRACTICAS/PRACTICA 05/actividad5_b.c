#include "actividad5_b.h"

int sequential_search(int* array , int tam , int elemento){
    for(int i = 0 ; i < tam ; i++){
        if(elemento == array[i])
            return i;
    }
    return -1;
}

void MergeRandom(int*array , int begin , int mid , int end){
    int i = begin , j = mid+1 , k = 0 ;
    int* output = (int*) calloc(end-begin+1 , sizeof(int));
    if(output == NULL){
        perror("NO HAY ESPACIO EN MEMORIA");
    }
    while(i<=mid && j<=end){
        if(array[i] <= array[j]){
            output[k] = array[i];
            k++; i++;
        }
        else if(array[i] >= array[j]){
            output[k] = array[j];
            k++; j++;
        }
    }

    while(i<=mid){
        output[k] = array[i];
        k++; i++;
    }
    while(j<=end){
        output[k] = array[j];
        k++; j++;
    }

    for(i = begin ; i <= end ; i++)
        array[i] = output[i-begin];
}

void MergeRandom_sort(int*array , int begin , int end){
    if(begin < end){
        int mid = (end+begin) /2;
        MergeRandom_sort(array , begin , mid);
        MergeRandom_sort(array , mid+1 , end);
        MergeRandom(array , begin , mid , end);
    }
}

void random(int* array){
    int an=0;
    int i=0;

    an = (2 * an + 1) % (int) pow(2 , 32);
    
    while(i < TAM_RANDOM){
        an = (2 * an + 1) % (int) pow(2 , 32); //Linear Congruential Generator or XORshift ¿?
        if(an <= 19 && 0 <= an){
            array[i] = an;
            i++;
        }
    }
}
int MenuRandom(){
    int* array = (int*) calloc (TAM_RANDOM , sizeof(int));
    if(array == NULL){
        perror("NO HAY MEMORIA DISPONIBLE");
        return -1;
    }
    else {
    random(array);
    int numero=0;
    int indice = 0;
    
    printf("Ingrese el numero que quiere encontrar: ");
    fflush(stdin);
    scanf("%i", &numero);
    MergeRandom_sort(array , 0 , TAM_RANDOM-1);
    indice = sequential_search(array , TAM_RANDOM , numero);
    printf("Numero encontrado en el indice: %i\n", indice);
    
    return 0;
    }
}

Pais* scan(FILE* BD ){
    Pais* array = (Pais*) calloc ( TAM_BD , sizeof(Pais) );
    char nombre[20] = {0};
    char idioma[20] = {0};
    int pblcn = 0 , ind = 0;

    for(int i = 0 ; i < TAM_BD && !feof(BD) ; i++){
        fflush(stdin);
        fscanf(BD ,"%d  %s  %d  %s",&ind , &nombre , &pblcn , &idioma);
        array[i].indice = ind;
        array[i].poblacion = pblcn;
        strcpy(array[i].nombre , nombre);
        strcpy(array[i].idioma , idioma);
    }
    fclose(BD);
    return array;
}

void printTDA(Pais array[]){
    printf("\nELEMENTOS EN EL ARREGLO\n");
    for(int i = 0 ; i < TAM_BD ; i++){
        printf("%i\n%s\n%.2i\n%s\n\n", array[i].indice , array[i].nombre , array[i].poblacion , array[i].idioma);
    }
}

void MergePais_sort(Pais* array , int begin , int end){
    if(begin < end){
        int mid = (begin + end) / 2;

        MergePais_sort(array , begin , mid);
        MergePais_sort(array , mid+1 , end);
        MergePais(array , begin , mid , end);
    }
}

void MergePais(Pais* array , int begin , int mid , int end){ 
    int i = begin , j = mid+1 , k = 0;
    Pais* output = (Pais*) calloc(end-begin+1 , sizeof(Pais));

    while( i <= mid  &&  j <= end){
        if(strcmp(array[i].nombre , array[j].nombre) <= 0){
            output[k] = array[i];
            k++ ; i++;
        }
        else if(strcmp(array[i].nombre , array[j].nombre) >= 0){
            output[k] = array[j];
            k++ ; j++;
        }
    }
    while( i <= mid){
        output[k] = array[i];
        k++ ; i++;
    }
    while( j <= end){
        output[k] = array[j];
        k++ ; j++;
    }
    for(i = begin ; i <= end ; i++){
        array[i] = output[i-begin];
    }
}

int BinarySearch_Pais(Pais array[], int begin, int end, char* elemento){
    MergePais_sort(array , begin , end);
    int mid = 0; 
    while(begin <= end){
        mid = (end+begin) / 2;
        if(strcmp(array[mid].nombre , elemento) == 0)
            return mid;

        if(strcmp(array[mid].nombre , elemento) < 0)
            begin = mid+1;

        if(strcmp(array[mid].nombre , elemento) > 0)
            end = mid-1;
    }
    return -1;
}

void EncontrarElemento(Pais* array){
    char elemento[20];
    printf("Ingrese el pais que quiere buscar: ");
    fflush(stdin);
    scanf("%s",&elemento);
    int i = BinarySearch_Pais(array , 0 , TAM_BD , elemento);
    if(i <= -1 && i >= TAM_BD)
        printf("El Pais no se encuentra en la base de datos.\n\n");
    else if(i >= 0 && i < TAM_BD ){
    printf("El pais %s , se encuentra en el indice: %i\n" , elemento , array[i].indice);
    printf("Elementos pertenecientes a la linea %i:\n", array[i].indice);
    printf("%i\n%s\n%i\n%s\n", array[i].indice , array[i].nombre , array[i].poblacion , array[i].idioma);
    }
}

int MenuPais(){
    int opcion = 0 , i = 0;
    FILE* BD = fopen("C:\\Users\\lenovo\\Desktop\\CODIGOS FUENTES\\2BM1-ALGORITMOS Y ESTRUCTURAS DE DATOS\\PRACTICAS\\BD_Paises_ y_poblacion.txt","r");
    Pais* array = scan(BD);

    printf("Ingrese la opcion que desea realizar: ");
    while(opcion < 5){
        printf("MenuPais:\n");
        printf("1-Imprimir array sin ordenar\n");
        printf("2-Imprimir array ordenada\n");
        printf("3-Encontrar un pais de la array\n");
        printf("0-Terminar programa\n");
        printf("Ingrese la opcion a realizar: ");
        fflush(stdin);
        scanf("%i" , &opcion);

        switch(opcion){
            case 0:
                free(array);
                return 0;
            break;

            case 1:
                printTDA(array);
            break;

            case 2:
                MergePais_sort(array , 0 , TAM_BD-1);
                printTDA(array);
            break;

            case 3:
            MergePais_sort(array , 0 , TAM_BD-1);
                EncontrarElemento(array);
            break;

            default:
                printf("Ingrese una opcion valida.\n");
            break;
        }
    }
}

int menu(int indicador){
    while(indicador != 0){
        printf("1-\t Ejecutar programa de generacion y buscador de indice de un arreglo de numeros random\n");
        printf("2-\t Ejecutar programa de Base de Datos sobre paises\n");
        printf("0-\t FIN DEL PROGRAMA\n");
        printf("Ingrese la opcion que desee realizar: ");
        scanf("%i" , &indicador);

        switch(indicador){
            case 1: 
                MenuRandom();
            break;

            case 2:
                MenuPais();
            break;

            default:
                printf("Ingrese una opcion valida.\n");
        }
    }
    return 0;
}