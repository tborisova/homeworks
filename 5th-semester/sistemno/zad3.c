#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

  int pid, fd;
  char buf[5];

  if((pid = fork()) == -1){
    write(2, "Fork failed", 13);
    return 1;
  }

  if(pid != 0){ // in parent
    int *status;
    wait(status);

    fd = open("asdf.txt", O_RDWR | O_APPEND);
    write(fd, "7", 1); // сега във файла има: 1234567
    lseek(fd, 0, SEEK_SET); // отиваме на първа позиция във файла
    int n = read(fd, buf, 5); // четем 5 байта от файла: 12345
    write(1, buf, n); // пишем това, което сме прочели на stdout. В резултат програмата извежда: 12345
  }else{ // in child 
    fd = open("asdf.txt", O_CREAT | O_WRONLY, 0644);
    dup2(fd, 1); // тук казваме, че това, което се пише на stdout се пише във файла, защото echo ще пише във файл с дескриптор - 1
    close(fd);
    execlp("echo", "echo", "123456", 0);
  }

  return 0;
}



