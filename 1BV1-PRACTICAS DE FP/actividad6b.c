//Recibir una cantidad en segundos y mostrarla en HH:MM:mm

#include <stdio.h>

main(void)
{
    int nums, recinums; //nums=la cantidad de segundos señalados. recinums_el reciproco de "nums"
    int h, m, s;

    printf("Ingrese los segundos que quiere transformar");
    scanf("%i", &nums);

    h = nums/3600;
    recinums = nums%3600;
    m = recinums/60;
    s = recinums%60;

    printf("%i segundos es igual a %i:%i:%i horas",nums, h, m, s);
    return 0;
}