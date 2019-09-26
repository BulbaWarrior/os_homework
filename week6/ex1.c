#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(){

    int p[2];
    char* str = "some random string\n";
    char empty_str[100];
    pipe(p);
    write(p[1], str, strlen(str));
    close(p[1]);
    read(p[0], empty_str, 100);
    close(p[0]);
    printf("%s", empty_str);
    return 0;
}
