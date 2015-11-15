#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h> 

int main(int argc, char **argv){

	for(int i = 0; i < argc; i++){
		printf("%s\n", argv[i]);
	}

	int fd;

	if(argc <= 1){
		perror("Filename should be added!");
	}

	fd = open(argv[1], O_RDWR | O_APPEND);

	if(fd < 0){
		perror("File is not opened!");
	}else{
		fprintf(stdout, "File is opened\n");
	}

	char buf[10000];
	int bytes_read;

	while((bytes_read = read(fd, buf, 10000)) > 0){
		for(int i = 0; i < bytes_read; i++){
			if(buf[i] >= '0' && buf[i] <= '9'){
				fprintf(stdout, "%c", buf[i]);
			}else{
				write(fd, &buf[i], 1);
			}
		}
	}

	return 0;
}