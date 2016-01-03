#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>

#define MAX_SIZE 10000

int main(int argc, char **argv){
	int pid, status;


	pid = fork();

	if(pid < 0){
		perror("error while forking");
	}else if(pid == 0){ // child
		execlp("who", "who", NULL);
	}else{ // parent
		wait(&status);
	}

	return 0;
}