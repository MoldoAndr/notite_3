#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
 
#define BUFSIZE 16
 
int main(int argc, char **argv, char **envp)
{
	if (argc < 3)
	{
		printf("Not enough arguments");
		exit(-1);
	}
	 

	int   fdin      = open(argv[1], O_RDONLY);
 
	if (fdin < 0) {
		perror("read at open!");
		exit(-1);
	}
	char *buffer    = (char*) malloc (BUFSIZE);
	ssize_t readBytes = 0;
 
 	if (argc == 2)
	{	
	do {
		readBytes = read(fdin, buffer, BUFSIZE);
		write(STDOUT_FILENO, buffer, readBytes);
	} while(readBytes > 0);
 	}
	else
	{	
		int fdout 	= open(argv[2], O_WRONLY | O_CREAT, 0666);
		do {
		readBytes = read(fdin, buffer, BUFSIZE);
		for (int i=0;i<readBytes;i++)
		{
		if (buffer[i] == 0x00)
			{
				write(fdout, buffer, i);
				close(fdout);
				close(fdin);
				break;
			}
		}
		write(fdout, buffer, readBytes);
		} while(readBytes > 0);
		close(fdout);
	}
	if (readBytes < 0)
		printf("Error on read!");
 
	return 0;
}

