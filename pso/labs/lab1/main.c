#include <stdlib.h>

int main() {
  
    char* p1 = (char*)malloc(10);
    char* p2 = (char*)malloc(20);

    free(p1);
    free(p2);

    return 0;
}
