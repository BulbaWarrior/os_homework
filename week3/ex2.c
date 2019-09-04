#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, size_t size, int (*compare)(int a, int b)){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(compare(a[j], a[j+1])){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void print_arr(int* a, size_t size){
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int greater(int a, int b){
    return a > b ? 1 : 0;
}

int less(int a, int b){
    return !greater(a, b);
}


int main(){

    int (*foo) (int a, int b);
    foo = &greater;
    int a[] = {23, 12, 5, 24, 6, 9, 4, 17};
    print_arr(a, 8);
    bubble_sort(a, 8, foo);
    print_arr(a, 8);
    foo = &less;
    bubble_sort(a, 8, foo);
    print_arr(a, 8);


    return 0;
}
