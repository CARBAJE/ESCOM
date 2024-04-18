#include "actividad1_b.h"

MC* crearmc(Med dim, Car tip, char* name){
    
    MC* p = (MC*) calloc(1 , sizeof(MC) );

    if(p == NULL){
        perror("NO HAY SUFICIENTE MEMORIA");
    }
    else{
        p -> dim = dim;
        p -> tip = tip;
        strcpy(p -> nombre , name);
    }
    return p;
}

void impmc(MC p){
    printf("Nombre: %s\n", p.nombre);
    printf("Dimensiones: %d - %i - %i\n", p.dim.bust , p.dim.cint , p.dim.cad);
    printf("Caracteristicas: %iKG - %icm - Ojos: %s\n", p.tip.kg , p.tip.alt , "cafes" );
}

MC* copymc(MC* p){
    MC* pp = (MC*) calloc (1 , sizeof(MC));
    
    if(p == NULL){
        perror("NO HAY SUFICIENTE MEMORIA");
    }
    else{
        pp -> dim = p -> dim;
        p -> tip = p -> tip;
        strcpy(pp -> nombre , p -> nombre);
    }
}

void freemc(MC* p){
    free(p);
}

int menu(int arg , char** argv){
    int op = 0;
    MC* mona = NULL;
    MC* monac = NULL;
    Med dimensiones;
    Car caracteristicas;
    char nom[20];

    do{
        puts("ELiga una de las siguientes opciones:");
        puts("1-Crear Mona");
        puts("2-Imprimir Mona");
        puts("3-Copiar Mona");
        puts("4-Destruir Mona");
        puts("0-SALIR");

        fflush(stdin);
        scanf("%i", &op);

        switch(op){
            case 1:
                fflush(stdin);
                printf("Ingrese dimension 1: ");
                scanf( "%i", &dimensiones.bust);

                fflush(stdin);
                printf("Ingrese dimension 2: ");
                scanf( "%i", &dimensiones.cint);

                fflush(stdin);
                printf("Ingrese dimension 3: ");
                scanf( "%i", &dimensiones.cad);
                
                fflush(stdin);
                printf("Ingrese caracteristica 1: ");
                scanf( "%i", &caracteristicas.kg);

                fflush(stdin);
                printf("Ingrese caracteristica 2: ");
                scanf( "%i", &caracteristicas.alt);

                fflush(stdin);
                printf("Ingrese caracteristica 3: ");
                scanf( "%i", &caracteristicas.ojo);

                fflush(stdin);
                printf("Ingrese el nombre que le quiera dar: ");
                scanf("%s", nom);
                fflush(stdin);

                mona = crearmc(dimensiones, caracteristicas , nom);
                op=6;
                printf("%i\n", dimensiones.bust);
            break;

            case 2:
                if(mona != NULL)
                    impmc(*mona);
                if(mona == NULL){
                    printf("CREE PRIMERO UNA MC\n");
                }
            break;

            case 3:
                if(mona != NULL)
                    monac = copymc(mona);
                if(mona == NULL){
                    printf("CREE PRIMERO UNA MC\n");
                }
            break;

            case 4:
                if(mona != NULL)
                    freemc(mona);
                if(mona == NULL){
                    printf("CREE PRIMERO UNA MC\n");
                }
            break;

            case 0:
                puts("TERMINANDO PROGRAMA");
                return 0;
            break;

            default:
                printf("INGRESE UN VALOR VALIDO DADO EN LAS OPCIONES\n");
            break;
        }

    }while(op != 0);
}
