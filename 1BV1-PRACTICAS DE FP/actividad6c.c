//perimetro y área de un triángulo.

#include <stdio.h> 
#include<math.h>
main(void)
{
    float a, b, c, s, P, A;
    double AA;

    printf("Introduzca los tres lados de su triangulo");
    scanf("%f %f %f",&a, &b, &c);
    
    P = a + b + c;
    s = P/2;
    A = (s*(s-a)*(s-b)*(s-c));
    AA =sqrt(A);

    printf("el perimetro es: %.2f\n", P);
    printf("el area del triángulo es: %.2f\n", AA);

    return 0;
}
