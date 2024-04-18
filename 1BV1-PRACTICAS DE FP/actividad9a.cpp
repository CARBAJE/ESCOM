// Ingresa n números enteros positivos y/o cero, cuenta e imprime cuantos ceros se han ingresado.
// José Emiliano Carrillo Barreiro
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n =100;
    int count = 0;
    srand(time(NULL));

    for(n, count; n>0; n--)
    {
        int alt_n = rand() % 10;

        printf("%i, ",alt_n);

        if(alt_n == 0)
        {
            count++;
        }
    }

    cout<<"\nEl total de ceros es:"<< count;

    return 0;

}