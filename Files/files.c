#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *file;
	file = fopen("input.txt", "r");
	if(file==NULL){
		printf("error leyendo el archivo\n");
	}
	int numero;
	int numero2;
	fscanf(file, "%d", &numero);
	fscanf(file, "%d", &numero2);
	//cerrar el flujo	
	fclose(file);
	
	FILE *fileOut;
	fileOut = fopen("out.txt", "w");
	//verficiar error
	fprintf(fileOut, "la suma de los numeros es : %d\n",numero+numero2);
	//cerrar flujo
	fclose(fileOut);
}
