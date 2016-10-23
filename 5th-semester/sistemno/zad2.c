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

	if(argc <= 1){
		perror("Username should be specified");
	}

	int fd, status;

	pid_t pid;


	pid = fork();

	if(pid == 0){
		fd = open("output2", O_WRONLY|O_CREAT|O_TRUNC, 0640);
		if(fd == -1){
			perror("error opening file");
		}
		close(1);
		dup(fd);
		close(fd);
		execl("/usr/bin/who", "who", "-u", NULL);
	}else if(pid < 0){
		perror("error");
	}else{
		wait(&status); //, &status);

		char buff[MAX_SIZE];
		int bytes_read;
		fd = open("output2", O_RDONLY);
		if(fd == -1 ){
			perror("error opening the file for reading");
		}
		if((bytes_read = read(fd, buff, MAX_SIZE)) < 0){
			perror("error reading from file");
		}else{
			if(strstr(buff, argv[1]) != NULL){
				fprintf(stdout, "YES");
			}else{
				fprintf(stdout, "NO");
			}
		}
	}

	return 0;
}