#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{

int fd=open("test_file", O_WRONLY | O_CREAT, 0555);

printf("test_file exist with the file descriptor %d\n", fd);

int unlinked=unlink("test_file");

return 0;
}
