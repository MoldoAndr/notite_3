#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
 
#define BUFFER_SIZE 1

int main()
{

int fd=open("numbers", O_RDONLY);
lseek(fd, 3, SEEK_SET);
char buffer[BUFFER_SIZE];
int bytesRead=read(fd, buffer, BUFFER_SIZE);
printf("bytes read: %d\n", bytesRead);
write(1, buffer, BUFFER_SIZE);

return 0;
}
