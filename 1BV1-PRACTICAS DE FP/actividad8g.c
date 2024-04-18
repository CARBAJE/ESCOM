//Pide una hora al usuario en formato de 24 hrs (HH:MM) y mostrarla en formato de 12 hrs, además mostrar la hora al sumarle un minuto.

#include <stdio.h>

int main()
{
    int h, m;
    int hh, mm;

    printf("Escriba un hora en formato de 24 horas seguido de sus minutos. \nNota usar espacio en vez del signo :");
    scanf("%i %i", &h, &m);

    if(h > 12 && h<24)
    {
        h = h-12;
        printf("La hora en formato de 12 horas es %i:%i PM", h, m);
    }
    if(h < 12)
    {
        h = h;
        printf("La hora en formato de 12 horas es %i:%i AM",h, m);

    }
    if(h >= 24)
    {
        h = 00;
        printf("La hora en formato de 12 horas es %i:%i AM",h, m);
    }
    mm = m+1;
    printf("\nLa hora en formato de 12 horas mas un minuto es %i:%i", h, mm);

return 0;
}