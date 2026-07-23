#include<stdio.h>
#include<stdlib.h>
int main (){
   int n;
   printf("nhap vao so luong phan tu n:");
   scanf("%d",&n);

   int *ptr= (int*)malloc(n*sizeof(int));
   if (ptr==NULL){
    printf("khong the cap phat bo nho");
    return 1;
   }
       for (int i=0;i<n;i++){
        printf ("\nNhap a[%d]=",i);
        scanf("%d",ptr+i);
       }
       for (int i=0;i<n;i++){
        printf ("\nNhap a[%d]= %d",i,ptr[i]);
       }
       
       free (ptr);
       return 0;
}
