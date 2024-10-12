#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/file.h>

#define LOCK_FILE "locked.txt"

void wait()
{
    sleep(10);
}

void lock(int file_descriptor)
{
    int locked = flock(file_descriptor, LOCK_SH);
    
    if (locked < 0)
    {
        write(2, "error locking the file\n", 24);
    }

    write (1, "file locked succesfully\n", 24);
}

void unlock(int file_descriptor)
{
    int unlocked = flock(file_descriptor, LOCK_UN);
    
    if (unlocked < 0)
    {
        write(2, "error unlocking the file\n", 26);
    }

    write (1, "file unlocked succesfully\n", 26);
}


int open_file()
{
    int fd = open(LOCK_FILE, O_RDWR | O_CREAT, 0666);

    if (fd < 0)
    {
        write(2, "error opening the file\n",22);
    }

    write (1, "file opened succesfully\n", 23);
    return fd;
}

void close_file(int file_descriptor)
{
    int closed = close(file_descriptor);

    if (closed < 0)
    {
        write(2, "error closing the file\n", 23);
    }

    write (1, "file closed succesfully\n", 23);
}

void write_to_file(int file_descriptor, char* message, size_t message_length)
{
    int writer = write(file_descriptor, message, message_length);

    if (writer < 0)
    {
        write(2, "error writing to file\n", 22);
    }

    write(1,"file written succesfully\n",24);
}

void move_in_file(int file_descriptor, int offset)
{
    lseek(file_descriptor, offset, SEEK_SET);
}

void truncate_file(int file_descriptor, int length)
{
    int truncated = ftruncate(file_descriptor, length);
}

int duplicate(int file_descriptor)
{
    int new_fd = dup(file_descriptor);
    if (new_fd < 0)
        write(2, "error duplicating the file descriptor\n", 39);
    write(1, "file descriptor succesfully duplicated\n", 40);
    return new_fd;    
}

void write_in_parralel(int file_descriptor)
{
        write(STDOUT_FILENO, "I am STDOUT\n", 13);
        write(file_descriptor, "I am the new file descriptor\n", 30);
}

void unlink_file(int file_descriptor)
{
    int unlinked = unlink(LOCK_FILE);
}



int main()
{
    char* test="this is a test message\n";
    
    int file_descriptor = open_file();
    write_to_file(file_descriptor, test, 24);
    move_in_file(file_descriptor, 5);
    lock(file_descriptor);
    wait();
    unlock(file_descriptor);
    int new_fd = duplicate(STDOUT_FILENO);
    write_in_parralel(new_fd);
    close(file_descriptor);
    unlink_file(file_descriptor);
    
    close(new_fd);

    return 0;
}
