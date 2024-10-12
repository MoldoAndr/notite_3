#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void wait_for_input(const char *msg)
{
	char buf[32];

	printf(" * %s\n", msg);
	printf(" -- Press ENTER to continue ...");
	fflush(stdout);
	fgets(buf, 32, stdin);
}

int main(void)
{
	int fd1;
	int fd2;
	int rc;

	wait_for_input("beginning");

	/* Open files */
	fd1 = open("tmp1.txt", O_CREAT | O_RDWR, 0644);
	wait_for_input("created tmp1.txt");

	fd2 = open("Makefile", O_RDONLY);
	wait_for_input("opened Makefile");

	/* Redirect stderr to fd1 */
	rc = close(STDERR_FILENO);
	wait_for_input("closed stderr");

	rc = dup(fd1);

	/* Write something to stderr */
	write(STDERR_FILENO, "something", strlen("something"));
	wait_for_input("dup - redirected stderr to fd1. Written "
				   "something to STDERR_FILE. Inspect the associated file.");

	rc = close(fd1);
	wait_for_input("closed fd1");

	/* Redirect stderr to fd2 */
	rc = dup2(fd2, STDERR_FILENO);
	wait_for_input("dup2 - redirected stderr to fd2");

	rc = close(fd2);
	wait_for_input("closed fd2");

	return 0;
}
