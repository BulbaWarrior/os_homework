#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sigint_handler(int signal){
    if(signal == SIGINT){
        printf("you pressed Ctrl+C\n");
    }
    else{
        printf("error\n");
        exit(1);
    }
}

int main(){
    struct sigaction* sigint_action = malloc(sizeof(struct sigaction));
    sigint_action->sa_handler = &sigint_handler;
    sigaction(SIGINT, sigint_action, NULL);

    char str[100];
    while(1){
        scanf("%s", str);
        if(strcmp(str, "q") == 0){
            break;
        }
    }



    return 0;
}
