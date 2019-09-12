#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    while(1){
        char* input = calloc(sizeof(char), 128);

        fgets(input, 128, stdin);
        if(strcmp(input, "q") == 0)
            break;
        system(input);
    }
    return 0;
}
