//tarea3f

#include <stdio.h>

main(void)
{
    char key;

    printf("teclea una tecla en tu teclado:");
    key = getchar();
    printf("Presionaste la tecla '%c' key.\n", key);
    printf("Es el valor ACSII %d.\n", key);
    return (0);
}