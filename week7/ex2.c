#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("input a positive integer: ");
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr[i] = i;
        /* printf("%d\n", arr[i]); */
    }
    free(arr);
    return 0;
}
