#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

double leibnizSerie(int ini, int fin){
	double acum = 0;
	for(int i = ini; i <= fin; ++i){
		double minusOne = ((i&1) ? -1 : 1);				
		double element = minusOne/(2.0*i + 1);
		acum += element;
	}
	return acum;
}
int main(){
	pid_t pid;
	printf("pi es: %f\n", leibnizSerie(0, 500));
	int pipefd[2];
	double buffer[1];
	int r;
	int limiteSuperior;
	//limiteSuperior = 10000;
	printf("Ingrese el numero de iteraciones: ");
	scanf("%d", &limiteSuperior);
	r = pipe(pipefd);
	if(r < 0){
		perror("error en la creacion del pipe()");
		exit(-1);
	}
	pid = fork();
	if(pid < 0){
		perror("error en el fork()");
		exit(-1);
	}
	else if(pid == 0){//hijo
		close(pipefd[0]);
		double valorHijo[1] = {leibnizSerie(0, limiteSuperior/2)};
		r = write(pipefd[1],  valorHijo, sizeof(double));
		printf("yo hijo, calculer %f\n", valorHijo[0]);
		if(r != sizeof(double)) perror("error al escribir");
		close(pipefd[1]);
	}
	else{//padre
		close(pipefd[1]);
		r = read(pipefd[0], buffer, sizeof(double)); 
		if(r != sizeof(double)) perror("error al leer");
		close(pipefd[0]);
		printf("mensaje leido %f \n", buffer[0]);
		double calculoPadre = leibnizSerie(limiteSuperior/2 + 1, limiteSuperior);
		printf("Yo padre calcule %f \n", calculoPadre);
		double pi = (calculoPadre + buffer[0])*4;
		printf("Segun Leibniz, Pi = %f\n", pi);
	}
	return 0;
}
