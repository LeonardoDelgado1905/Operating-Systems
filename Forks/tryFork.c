#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	pid_t pid = fork();
	if(pid == -1)
		return -1;
	else if(pid == 0)
		printf("Hola soy el padre!\n");
	else
		printf("Hola soy el hijo! jejejej!\n");

	return 0;
}

