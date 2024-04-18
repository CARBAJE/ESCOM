#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int8_t bust;
    int8_t cint;
    int8_t cad;
}Med;

typedef struct{
    int8_t kg;
    int16_t alt;
    int8_t ojo;
}Car;

typedef struct{
    Med dim;
    Car tip;
    char nombre[20];
}MC;

MC* crearmc(Med, Car, char*);
void impmc(MC);
MC* copymc(MC*);
void freemc(MC*);
int menu(int , char**);