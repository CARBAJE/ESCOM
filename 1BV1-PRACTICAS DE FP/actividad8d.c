#include <stdio.h>
#include <math.h>

main(void)
{
int n;
int Val_Abs;

printf("Ingrese su numero");
scanf("%i", &n);

Val_Abs = fabs(n);

printf("El velor absoluto de %i es: |%i|", n, Val_Abs);

return 0;

}