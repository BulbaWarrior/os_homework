#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sig_handler(int signal){
    switch(signal){
    case SIGKILL:
        printf("Ahh! I'm dead\n");
        break;
    case SIGSTOP:
        printf("Stopped\n");
        break;
    case SIGUSR1:
        printf("user signal 1\n");
        break;
    }
}

int main(){
    struct sigaction* sigint_action = malloc(sizeof(struct sigaction));
    sigint_action->sa_handler = &sig_handler;
    sigaction(SIGKILL, sigint_action, NULL);
    sigaction(SIGSTOP, sigint_action, NULL);
    sigaction(SIGUSR1, sigint_action, NULL);

    while(1){

    }



    return 0;
}
