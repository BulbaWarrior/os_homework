#include <stdio.h>

int main(){

    int n;
    printf("enter number: \n");
    scanf("%d", &n);
    int spc = n;
    int star = 1;

    while(star <= 2*n + 1){
        for(int i = 0; i < spc; i++){
            putchar(' ');
        }

        for(int i = 0; i < star; i++){
            putchar('*');
        }
        putchar('\n');
        star += 2;
        spc--;
    }

    return 0;
}
