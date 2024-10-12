#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd=open("fake", O_WRONLY | O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
	{	
		printf("file descriptor error");
	}
return 0;
}
