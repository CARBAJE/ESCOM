#include "actividad4_b.h"
void scan(FILE* BD , Persona* lista , int i){
    char nombres[20] = {0};
    char paises_o[20] = {0};
    float altura;
    int telefono;

    while(!feof(BD) && i < TAM){
        fflush(stdin);
        fscanf(BD ,"%s	%s	%f	%d", &paises_o , &nombres , &altura , &telefono);
        strcpy(lista[i].nombre , nombres);
        strcpy(lista[i].pais_origen , paises_o);
        lista[i].altura = altura;
        lista[i].telefono = telefono;
        i++;
    }
    fclose(BD);
}

void printTDA(Persona* lista , int i){
    printf("\nELEMENTOS EN EL ARREGLO\n");
    for(i=0; i < TAM ; i++){
        printf("%s\t%s\t%.2f\t%d\n", lista[i].pais_origen , lista[i].nombre , lista[i].altura , lista[i].telefono);
    }
}

void selection_sort(Persona* array){
    float temp = 0;
    for(int i = 0 ; i < TAM-1 ; i++){
        for(int j=i+1 ; j <= TAM-1 ; j++){
                if(array[i].altura > array[j].altura){
                    temp = array[i].altura;
                    array[i].altura = array[j].altura;
                    array[j].altura = temp;
                }
            }
    }
}

void merge(Persona*array , int begin , int mid , int end){
    int i = begin , j = mid+1 , k = 0 ; //variables que definen las posiciones iniciales a ordenar
    Persona* output = (Persona*) calloc(end-begin+1 , sizeof(Persona)); //arreglo que almacenara los datos rdenados

    while(i<=mid && j<=end){ //bloque de codigo que ordena el arreglo en el rango limitado por las variables i , mid , j , end
        if((int)array[i].nombre[0] <= (int)array[j].nombre[0]){ //comparador de magnitud para el caso de i
            output[k] = array[i];
            k++; i++;
        }
        else if((int)array[i].nombre[0] >= (int)array[j].nombre[0]){ //comparador de magnitud para el caso de j
            output[k] = array[j];
            k++; j++;
        }
    }

    while(i<=mid){ //bloque que ordena los valores mayores en caso que esten en el lado izquierdo
        output[k] = array[i];
        k++; i++;
    }
    while(j<=end){//bloque que ordena los valores mayores en caso que esten en el lado derecho
        output[k] = array[j];
        k++; j++;
    }

    for(i = begin ; i <= end ; i++){ //intercambia los datos ya oredenados al arreglo original
        array[i] = output[i-begin];
    }
}

void merge_sort(Persona*array , int begin , int end){
    if(begin < end){ //begin = 0 , entonces , mientras end o begin no lleguen al otro se hara la recursividad
        int mid = (end+begin) /2; 
        
        merge_sort(array , begin , mid); //divide la parte de la izquierda
        merge_sort(array , mid+1 , end); // divide la pate de la derecha
        merge(array , begin , mid , end); //mezcla
    }
}

void bubble_sort(Persona* array){
    Persona temp={0};
    for(int i = 0 ; i < TAM-1 ; i++){
        for(int j = 0 ; j < TAM - i - 1 ; j++){
            if(array[j].telefono > array[j+1].telefono){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void insertion_sort(Persona* array){
    int i = 0 , j = 0;
    Persona pivote = {0};

    for(i = 1 ; i < TAM ; i++ ){
        pivote = array[i];
        j = i - 1;
        while(j >= 0 && pivote.pais_origen[0] < array[j].pais_origen[0]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = pivote;
    }
}

int menu(int argc, char** argv){
    Persona lista[TAM];
    FILE* BD = fopen("C:\\Users\\lenovo\\Desktop\\CODIGOS FUENTES\\2BM1-ALGORITMOS Y ESTRUCTURAS DE DATOS\\PRACTICAS\\BD_Personas.txt" , "r");
    int i = 0 , j = 0 , valor = 0;
    int opcion=0;

    if(BD == NULL){
        perror("Hubo un error al leer el archivo\n");
        exit(1);
    }

    scan(BD , lista , i);

    do{
        printf("Igrese la opcion que desee ejecutar\n");
        printf("1-Mostrar lista de personas en desorden\n");
        printf("2-Mostrar lista de personas por altura\n");
        printf("3-Mostrar lista de personas por la segunda letra del nombre\n");
        printf("4-Mostrar lista de personas por numero telefonico\n");
        printf("5-Mostrar Personas por pais de origen\n");
        printf("0-SALIR DEL PROGRAMA\n");
        printf("Ingrese la opcion a escoger: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion){
            case 0:
                return 0;
            break;

            case 1:
                printTDA(lista, i);
            break;

            case 2:
                selection_sort(lista);
                printTDA(lista, 0);
            break;

            case 3:
                merge_sort(lista , 0 ,TAM);// begin = 0 ; end = TAM (constante que define el tamaño del arreglo "lista")
                printTDA(lista, 0);
            break;

            case 4:
                bubble_sort(lista);
                printTDA(lista, 0);
            break;

            case 5: 
                insertion_sort(lista);
                printTDA(lista, 0);
            break;

            default:
                printf("INGRESE UNA OPCION VALIDA\n");
            break;
        }
    }while(opcion != 0);
}