//Pedir al usuario las medidas de dos rectángulos y decir cual tiene mayor área

#include <stdio.h>

int main()
{
    float aa, ab, ba, bb;
    float AA, AB;

    printf("Escriba los dos lados de su rectangulo");
    scanf("%f %f", &aa, &ab);
    printf("Escriba los dos lados del segundo rectangulo");
    scanf("%f %f", &ba, &bb);

    AA = aa*ab;
    AB = ba*bb;

    if(AA>AB)
        printf("El primer rectangulo abarca un area mayor que el segundo");
    else
        printf("El segundo rectangulo abarca un area mayor o igual que el primero");

    return 0;
}