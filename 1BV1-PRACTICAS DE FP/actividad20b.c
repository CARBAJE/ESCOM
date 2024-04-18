#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i= 0 , j = 0;
    int array[10][20];
    
	srand(time(NULL));
	
	for(i ; i < 10 ; i++){
		for(j ; j < 20 ; j++){
			array[i][j] = rand() % (90-65) +65 + 1;
		}
	}
}