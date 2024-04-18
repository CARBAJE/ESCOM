//cualcular el area y volumen de un cilindro
#include <stdio.h>
int main()
{
    int r, h; //r=radio y h=altura
    float pi = 3.1416;
    float Al, Ab, At, V; //Al=área de lateral, At=Área total, Ab=Área base, V=volumen

    printf("Ingrese el radio de la base:");
    scanf("%i", &r);
    printf("Ingrese la altura de la base:");
    scanf("%i", &h);
    Al = 2*pi*r*h;
    Ab = pi*r*r;
    At = 2*Ab + Al;
    V = pi*r*r*h; 
    printf("El area lateral del cilindro es: %.2f\n", Al);
    printf("El area de la base del cilindro es: %.2f\n", Ab);
    printf("El area total del cilindro es: %.2f\n", At);
    printf("El volumen del cilindro es: %.2f\n", V);
    return 0;
}