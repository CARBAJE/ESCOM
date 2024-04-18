//Pedir un numero de tres cifras como “palabras”, e imprimirlo como numero.

#include <stdio.h>
#include <string.h>

int main()
{
    char n1, n2, n3;

    printf("Escriba tres numeros en formato de abecedario y del cero al nueve");
    scanf("%s %s %s", &n1, &n2, &n3);

    printf("EL número ingresado en digitos es: %s %s %s", n1, n2, n3);

    char a[20] = "n1";
    char b[20] = "n2";
    char c[30] = "n3";

    switch (n1)
    {
        case 1:
            if(strcmp (a, b) == 0)
            printf(2);
            break;
    
    return 0;

    }

return 0;
}