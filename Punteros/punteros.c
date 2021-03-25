#include <stdlib.h>
#include <stdio.h>

int main(){
	//int arr[10] = {1, 2, 4, 5, 6, 7, 8, 9, 19};
	//int *p = arr[0];
	//printf("el dato en la posicion %p es %d\b", p, *p);
	FILE *fileOut = fopen("input.txt", "w");
	int arr[10];
	int *p2 = malloc(10*sizeof(int));
	
	for(int i = 1; i <= 10; i++)
		arr[i-1] = i;
	for(int i = 1; i <= 10; i++)
		*(p2+i-1) = i*i;
	//imprimir direcciones DE memoria
	for(int i = 1; i <= 10; i++)
		printf("%p, ", &arr[i-1]);  
	printf("\n");
	for(int i = 1; i <= 10; i++)
		printf("%p", (p2+i-1));

	//MATRICES
	//forma1
	int *p3 = malloc(9*sizeof(int));
	//forma2
	int **p4 = malloc(3*sizeof(int *));
	for(int i = 0; i < 3; i++)
		*(p4+i) = malloc(3*sizeof(int));

	//asignar valor a x, y
	int x = 0; 
	int y = 2;
	int val = 34;
	(*(*(p4+x)+y)) = val;
	printf("en la posicion %d, %d esta el numero: %d\n", x, y, *(*(p4+x)+y));  
	return 0;
}
