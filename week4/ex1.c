#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    if(fork()){
        int pid = getpid();
        printf("Hello from parent %d\n", pid - n);
    }

    else{
        int pid = getpid();
        printf("Hello from child %d\n", pid - n);
    }
    return 0;
}
