#include "tda.h"

Planeta* crearPlaneta(Dimension dim, int masa, char* nombre){
    Planeta *p=(Planeta *)malloc(sizeof(Planeta));
    if(p==NULL){
        perror("Se acabo la memoria");
    } else{
        p->dimension=dim;
        p->masa=masa;
        strcpy(p->nombre,nombre);
    }
    return p;
}

void destruirPlaneta(Planeta *p){
    free(p);
}

void imprimirPlaneta(Planeta p){
    printf("Nombre del planeta: %s\n",p.nombre);
    printf("Masa del planeta: %d\n", p.masa);
    printf("Circunferencia del planeta: %f\n", p.dimension.circunferencia);
    printf("Diametro del planeta: %d\n", p.dimension.diametro);
}

void actualizarNombrePlaneta(Planeta *p, char *nuevoNombre){
    strcpy(p->nombre,nuevoNombre);
} 

void inicioOperacion(int argc, char** argv){
    int opcUsuario=0;
    Planeta *planeta;
    Dimension dimension;
    float circunferencia;
    int masa;
    char nombre[TAM];
    int diametro;
    do{
        puts("Eliga una de las siguientes las opciones:");
        puts("1.- Alta de planeta");
        puts("2.- Destruir de planeta");
        puts("3.- Imprimir datos del planeta");
        puts("4.- Cambiar nombre a planeta");
        puts("0.- Salir del programa");
        fflush(stdin);
        scanf("%d",&opcUsuario);
        switch (opcUsuario){
            case 1:
                puts("Ingresa diametro del planeta");
                fflush(stdin);
                scanf("%d", &diametro);
                puts("Ingresa nombre del planeta");
                fflush(stdin);
                scanf("%s",nombre);
                puts("Ingresa circunferencia del planeta");
                fflush(stdin);
                scanf("%f", &dimension.circunferencia);
                puts("Ingresa masa del planeta");
                fflush(stdin);
                scanf("%d", &masa);
                dimension.diametro=diametro;
                planeta=crearPlaneta(dimension,masa,nombre);
                break;
            case 2:
                if(planeta!=NULL)
                    destruirPlaneta(planeta);
                break;
            case 3:
                if(planeta!=NULL)
                    imprimirPlaneta(*planeta);
                break;
            case 4:
                puts("Ingresa el nuevo nombre del planeta");
                fflush(stdin);
                scanf("%s", &nombre[0]);
                actualizarNombrePlaneta(planeta, nombre);
                break;
            default:
                opcUsuario=0;
                puts("Terminando programa...");
                break;
        }
    } while(opcUsuario!=0);

}