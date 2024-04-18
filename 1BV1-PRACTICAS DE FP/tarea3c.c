//conversiones basicas en c

#include <stdio.h>

int main(void)
{
    float f1 = 123.125 , f2;
    int i1, i2 = -150;
    char c = 'a';

    i1 = f1;    //Conversion de "float" a "int"
    printf("%f asingnado a un int da como resultado %i\n", f1, i1);

    f1 = i2;   //Conversion de "int" a "float"
    printf("%i asignado a un float da como resultado %f\n", i2, f1);

    f1 = i2 / 100;   //int dividido por int
    printf("%i dividido entre 100 da como resultado %f\n", i2, f1);

    f2 = i2 / 100.0;   //int dividido por float
    printf("%i dividido entre 100.0 da como resultado %f\n", i2, f2);

    f2 = (float) i2 / 100; //operador tipo "cast"
    printf("(float) %i dividido entre 100 da como resultado %f\n", i2, f2);

    return 0;
}