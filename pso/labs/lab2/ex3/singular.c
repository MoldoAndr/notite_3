#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h> /* flock */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> /* errno */

#define LOCK_FILE "/tmp/my_lock_file"

static int fdlock = -1;

static void do_stuff(void)
{
	sleep(2);
}

static void check_lock(void)
{
	int rc;

	fdlock = open(LOCK_FILE, O_CREAT | O_RDWR, 0666);
	if (fdlock == -1) {
		perror("Failed to open lock file");
		exit(EXIT_FAILURE);
	}

	rc = flock(fdlock, LOCK_EX | LOCK_NB);
	if (rc == -1) {
		if (errno == EWOULDBLOCK) {
			printf("Another instance is running, exiting.\n");
		} else {
			perror("Failed to lock file");
		}
		close(fdlock);
		exit(EXIT_FAILURE);
	}

	printf("\nGot Lock\n\n");
}

static void clean_up(void)
{
	int rc;

	rc = flock(fdlock, LOCK_UN);
	if (rc == -1) {
		perror("Failed to unlock file");
	}

	rc = close(fdlock);
	if (rc == -1) {
		perror("Failed to close lock file");
	}

	rc = unlink(LOCK_FILE);
	if (rc == -1) {
		perror("Failed to delete lock file");
	}
}

int main(void)
{
	check_lock();
	do_stuff();
	clean_up();
	return 0;
}
