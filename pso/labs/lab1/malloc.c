#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static void* (*real_malloc)(size_t) = NULL;
static void (*real_free)(void*) = NULL;

void* malloc(size_t size) {
    if (!real_malloc) {
        real_malloc = dlsym(RTLD_NEXT, "malloc");
        if (!real_malloc) {
            const char *error = dlerror();
            write(STDERR_FILENO, error, strlen(error));
            _exit(EXIT_FAILURE);
        }
    }

    void* ptr = real_malloc(size);

    char buffer[256];
    int len = snprintf(buffer, sizeof(buffer), "allocated %zu bytes at %p\n", size, ptr);
    write(STDOUT_FILENO, buffer, len);

    return ptr;
}

void free(void* ptr) {
    if (!real_free) {
        real_free = dlsym(RTLD_NEXT, "free");
        if (!real_free) {
            const char *error = dlerror();
            write(STDERR_FILENO, error, strlen(error));
            _exit(EXIT_FAILURE);
        }
    }

    real_free(ptr);
    
    char buffer[256];
    int len = snprintf(buffer, sizeof(buffer), "free memory at address %p\n", ptr);
    write(STDOUT_FILENO, buffer, len);

}
