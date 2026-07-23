#include <stdio.h>
extern int count;
int my_sum(int a, int b){
    printf("%d\n",count);
    return a+b;
}