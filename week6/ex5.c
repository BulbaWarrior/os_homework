#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main(){
    int pid = fork();
    if(pid){
        sleep(10);
        kill(pid, SIGTERM);
    }

    else{
        while(1){
            printf("I'm alive!\n");
            sleep(1);
        }
    }
    return 0;
}
