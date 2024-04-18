#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

typedef struct{
    float circunferencia;
    int diametro;
}Dimension;

typedef struct{
    char nombre[TAM];
    int masa;
    Dimension dimension;
}Planeta;


Planeta* crearPlaneta(Dimension, int, char*);
void destruirPlaneta(Planeta *);
void imprimirPlaneta(Planeta );
void actualizarNombrePlaneta(Planeta *, char *);
void inicioOperacion(int, char**);
