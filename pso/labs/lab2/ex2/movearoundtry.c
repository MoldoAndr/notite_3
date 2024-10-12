#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFF 1

int main()
{
int fd=open("numbers", O_RDONLY);
lseek(fd,5, SEEK_SET);
char buffer[BUFF];
int readbytes=read(fd, buffer, BUFF);
write(1, buffer, BUFF);

return 0;
}
