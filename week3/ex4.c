#include <stdio.h>

void quicksort(int* a, int l, int r, int (*compare)(int, int)){

    if(l >= r){
        return;
    }
    int pivot = a[l];
    int less = 0;
    int greater = 0;
    int length = r-l + 1;
    int arr[length];
    for(int i = l + 1; i <= r; i++){
        if(compare(a[i], pivot)){
            arr[r-l - greater] = a[i];
            greater++;
        }
        else{
            arr[less] = a[i];
            less++;
        }
    }
    arr[less] = pivot;

    for(int i = l; i <= r; i++){
        a[i] = arr[i-l];
    }
    quicksort(a, l, l + less - 1, compare);
    quicksort(a, l + less + 1, r, compare);
}

int greater(int a, int b){
    return a > b ? 1 : 0;
}

int main(){
    int (*foo)(int, int) = greater;
    int a[] = {12, 34, 67, 39, 22, 5, 15, 7, 31};
    quicksort(a, 0, 8, foo);
    for(int i = 0; i < 9; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

}
