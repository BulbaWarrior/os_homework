#include  <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("size of ... int: %lu, float: %lu, double: %lu\n", sizeof(a), sizeof(b), sizeof(c));
    printf("max value of ... int: %d, float: %f, double: %lf\n", a, b, c);

    return 0;
}
