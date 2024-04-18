/*

    Problema: Construir un aplicativo para recolectar: 
    color, forma y dimensiones de un equipo de cómputo.

    Utilizar funciones para construir las estructuras y para
    modificar cualquier atributo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct{  //47
    char color[40];
    int8_t forma;  //0: Cuadrada; 1: Rectangular; ...
    int16_t diagonalPantalla;
    int32_t longitudLado;
} Equipo;

Equipo* creaEquipo(char*,int8_t, int16_t, int32_t);
void modificaColorEquipo(Equipo*, char*);
void imprimeEquipo(Equipo);

void main(){
    Equipo* miPC=creaEquipo("Negro", 0, 19, 34);
    modificaColorEquipo(miPC,"Azul");
    imprimeEquipo(*miPC);
    free(miPC);
}

/*
    Función que realiza la creación de un equipo
    @param color Requiere un color en formato cadena
    @param form Un estado de la forma del Equipo; 0->Cuadrado, 1 -> Rectangular
    @param diagonal Valor de la diagonal de la pantalla (pulgadas)
    @return Un equipo creado con los datos enviados
*/
Equipo* creaEquipo(char* color,int8_t form, int16_t diagonal, int32_t longitud){
    Equipo* miEquipoL=(Equipo*) malloc(sizeof(Equipo));
    if(miEquipoL==NULL){
        perror("No hay memoria para el equipo");
        exit(1);
    }
    miEquipoL->diagonalPantalla=diagonal;
    miEquipoL->forma=form;
    (*miEquipoL).longitudLado=longitud;
    strcpy(miEquipoL->color,color);
    return miEquipoL;
}

void modificaColorEquipo(Equipo* equipo, char* color){
    strcpy(equipo->color,color);
}

void imprimeEquipo(Equipo eq){
    printf("Equipo color: %s\n",eq.color);
    printf("Equipo diagonal: %d\n",eq.diagonalPantalla);
    printf("Equipo forma: %s\n",eq.forma==0?"Cuadrada":"Rectangular");
}
