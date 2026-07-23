#include<stdio.h>
#include <stdlib.h>
int main(){
    int a[3];
    int min;
    for (int i=0;i<3;i++){
        printf("Nhap vao so thu %d:",i+1);
        scanf("%d",&a[i]);
    }
    
    for (int i=0;i<3;i++){
        min=a[0];
        if (a[i]<min){ min=a[i];}
    }
    printf("gia tri nho nhat la:%d",min);
}