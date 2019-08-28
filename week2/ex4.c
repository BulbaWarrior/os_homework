#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main(int argc, char** argv){

    if(argc < 3){
        printf("use is ./ex1 <int> <int>\n");
        return 1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}
