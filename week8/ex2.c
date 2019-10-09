#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MB (1024*1024)

int main(int argc, char** argv){
    void* ptr[10];
    size_t size = atoi(argv[1])*MB;
    for(int i = 0; i < 10; i++){
        ptr[i] = malloc(size);
        memset(ptr[i], i, size);
        sleep(1);
    }

    return 0;
}
