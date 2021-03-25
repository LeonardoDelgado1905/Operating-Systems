#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	int pipefd[2];
	int r;
	int tam_msg = 10;
	char buf[tam_msg+1];
	pid_t pid;
	r = pipe(pipefd);
	if(r < 0){
		printf("error pipe()");
		exit(-1);
	}
	pid = fork();
	if(pid < 0){
		perror("Error fork");
		exit(-1);
	}
	if(pid == 0){//Hijo
		//hijo escribe pip - pipefd[1]
		close(pipefd[0]);
		r = write(pipefd[1], "ante tu me pichaba", tam_msg);
		printf("Mi numero es r: %d\n", r);
		//Hande errors
		if(r != tam_msg) perror("no escribio bieeeen");

		close(pipefd[1]);
		exit(0);
	}
	else{//Padre
		//padre lee pipe - pipefd[0]
		close(pipefd[1]);
		r = read(pipefd[0], buf, tam_msg);
		printf("Mi numero es (lectura) r: %d", r);
		if(r != tam_msg) perror("no leyooo bieeeen");
		buf[r] = 0;
		close(pipefd[0]);
		printf("\nMensaje del hijo: %s \n", buf);
	}
	return 0;

}
