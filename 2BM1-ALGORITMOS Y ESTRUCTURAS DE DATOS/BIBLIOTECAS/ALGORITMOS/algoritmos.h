#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void selection_sort(int* , int );
void insertion_sort(int* , int );
void merge(int* , int , int , int);
void merge_sort(int* , int , int);
void bubble_sort(int* , int);

int sequential_search(int* , int , int);
int binary_search(int* , int , int , int);
int* indexedSequential_search(int* , int); //int* "arreglo" , int "elemento a buscar"