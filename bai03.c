#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
int main(int argc, char *argv[]){
   if (argc!=2) {
        printf("Usage: %s Enter the data type name: \n", argv[0]);
        return 1;
   }
   char a[10]={'c','h','a','r'};
   char b[10]={'f','l','o','a','t'};
   char c[10]= {'i','n','t'};
   char d[10]={'d','o','u','b','l','e'};
   char e[10]={'a','l','l'};
    if (strcmp(c,argv[1])==0){
        printf("size of %s : %d bytes",argv[1],sizeof(int));
        printf("\nvalue range %s: %d to %d",argv[1],INT_MIN,INT_MAX);}
       else{ if (strcmp(b,argv[1])==0){
            printf(" size of %s : %d bytes",argv[1],sizeof(float));
             printf("\nvalue range %s: %.10e to %.10e",argv[1],FLT_MIN,FLT_MAX);
        }else{
            if(strcmp(a,argv[1])==0){
                printf(" size of %s : %d bytes",argv[1],sizeof(char));
                 printf("\nvalue range %s: %d to %d",argv[1],CHAR_MIN,CHAR_MAX);
            }else {
            if(strcmp(d,argv[1])==0){
               printf(" size of %s : %d bytes",argv[1],sizeof(double));
                printf("\nvalue range %s: %.10e to %.10e",argv[1],DBL_MIN,DBL_MAX);
            }else{
                if(strcmp(e,argv[1])==0){
                printf(" size of int : %d bytes",sizeof(int));
                printf("\nvalue range int: %d to %d",INT_MIN,INT_MAX);
                printf(" \n size of float : %d bytes",sizeof(float));
                printf("\nvalue range float: %.10e to %.10e",FLT_MIN,FLT_MAX);
                printf(" \n size of char : %d bytes",sizeof(char));
                 printf("\nvalue range char: %d to %d",CHAR_MIN,CHAR_MAX);
                 printf(" \n size of double : %d bytes",sizeof(double));
                printf("\nvalue range double: %.10e to %.10e",DBL_MIN,DBL_MAX);
            }else{printf("ban nhap vao ky tu khong dung vui long nhap lai");}}
        }
        }
       } 
   return 0;
}
