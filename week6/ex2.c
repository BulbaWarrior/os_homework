#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    int p[2];
    pipe(p);
    int pid;
    if((pid = fork()) < 0){
        exit(1);
    }
    else if(pid){
        close(p[0]);
        char* str = "some random string\n";
        write(p[1], str, strlen(str));
        close(p[1]);
        wait(NULL);
    }

    else{
        close(p[1]);
        char empty_str[100];
        read(p[0], empty_str, 100);
        close(p[0]);
        printf("%s", empty_str);
    }

    return 0;

}
