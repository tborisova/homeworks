#include "myinclude.h"

int main(){
	int fd1, fd2, fd3;

	// fd1 = open("fff.txt", O_RDONLY | O_CREAT, 0644);
	fd2 = open("fff.txt", O_WRONLY | O_CREAT, 0644);
	// fd3 = open("fff.txt", O_RDWR | O_CREAT, 0644);

	char buff[100];

	write(fd2, "Hello world", 11);
	
	lseek(fd2, -3, SEEK_END),

	// read(fd3, buff, 6);
	// printf("%s\n", buff); // Hello 

	// read(fd1, buff, 5);
	// printf("%s\n", buff); // Hello

	write(fd2, "chil", 4);
	// write(fd2, "!!!", 3);
	close(fd2);
	// read(fd1, buff, 9);
	// printf("%s\n", buff); // chil!!!
	return 0;
}
