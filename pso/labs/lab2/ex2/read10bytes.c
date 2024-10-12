#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFFER_SIZE 10

int main()
{
char buffer[BUFFER_SIZE];

int fd=open("numbers", O_RDONLY);

if (fd == -1)
{
	printf("error opening the file");
	return -1;
}

int bytesRead=read(fd,buffer,BUFFER_SIZE);
printf("bytes read:%d\n",bytesRead);

write(1,buffer, bytesRead);

return 0;
}
