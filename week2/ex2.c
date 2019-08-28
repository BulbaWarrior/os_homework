#include <stdio.h>
#include <string.h>
int main(){

    char str[128];
    printf("input your string:\n");
    scanf("%s", str);
    printf("reverse of the string: ");
    for(int i = strlen(str) - 1; i >= 0; --i){
        putchar(str[i]);
    }

    printf("\n");
    return 0;
}
