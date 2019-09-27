#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    int p[2];
    pipe(p);
    printf("creating child 1\n");
    int pid1 = fork();
    int pid2;
    if(pid1){
        printf("creating child 2\n");
        pid2 = fork();
        if(pid2){
            printf("sending second child's pid: %d\n", pid2);
            write(p[1], &pid2, sizeof(int));
            close(p[1]);
            printf("parent enters wait\n");
            int state;
            waitpid(pid2, &state, 0);
            printf("parent resumes\n");
        }
        else if(pid2 == 0){
            printf("child 2 started\n");
            close(p[1]);
            close(p[0]);
            while(1){
                printf("child 2 awake\n");
                fflush(stdout);
                sleep(1);
            }
        }
    }
    else if(pid1 == 0){
        close(p[1]);
        sleep(3);
        read(p[0], &pid2, sizeof(int));
        printf("recieved second child's pid: %d\n", pid2);
        if(kill(pid2, SIGSTOP) == 0){
            printf("stopped child 2\n");
        }

    }
    return 0;
}
