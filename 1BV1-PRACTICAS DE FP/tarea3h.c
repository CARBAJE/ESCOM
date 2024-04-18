//tarea3h

#include <stdio.h>

main()
{
    char name [20];
    char color [20];

    printf("¿Cual es tu nombre?");
    scanf("%s",name);
    printf("¿Cual es tu color favorito?");
    scanf("%s",color);
    printf("%s tu color favorito es %s\n", name, color);
    return(0);
}