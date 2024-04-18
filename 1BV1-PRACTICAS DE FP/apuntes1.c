#include <stdio.h>

int main()
{
	for(int i=8 ; i<=17 ; i++)
		printf("*");
	printf("\n \n");

	for(int i=10; i<=100 ; i+=5)
		printf("%i, ",i);
	printf("\n \n");

	for(int i=0; i<50 ; i++)
		printf("%d, ", i*4);
	printf("\n \n");

	for(int i=4; i<=200; i+=4)
		printf("%d, ",i);
	printf("\n \n");

	for(int i=0, cont=0 ; cont<50; i++)
		if(i%4 == 0)
		{
			printf("%d, ",i);
			cont++;
		}
	printf("\n \n");

	for(int i = 1800; i<=1840; i+=2)
		printf("%d, ", i);
	printf("\n \n");

	for(int i = 500 ; i>=-500 ; i--)
		if(i%6 == 0 || i%7 == 0)
			printf("%d, ", i);
	printf("\n");
	
	return 0;
}

