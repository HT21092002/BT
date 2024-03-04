#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Product{
   int a;
   char b[20];
   float c;
};
enum lietkesanpham{
   clothing,
   footwear,
   electronics,
};
union kichcosanpham{
 float d;
};
   int main(){
      struct Product e;
      union kichcosanpham g;
      enum lietkesanpham f;
      char h[20];
      printf("Enter the number of products:");
      scanf("%d",&e.a);
      getchar();
      for(int i=1;i<=e.a;i++){
      printf("\nEnter information for product %d:",i);
      printf("\nName:");
      fgets(e.b,sizeof(e.b),stdin);
      printf("%s",e.b);
      printf("Price:");
      scanf("%f",&e.c);
      do{
      printf("Type (0:clothing,1:foowear,2:electronics):");
      scanf("%d",&f);} while(f>2);
      if(f==0||f==1){
         printf("size:");
         scanf("%f",&g.d);
      } else{
         printf("weight:");
         scanf("%f",&g.d);
      }
      } 
      for(int i=1;;i++){
      do{
       printf("\nEnter the name of the product to retrieve information:");
       fgets(h,sizeof(h),stdin);
      scanf("%s",&h);} while(strcmp(h,e.b)==1);
      if (strcmp(h,e.b)==0){
         printf("Products infomation:");
         printf("\nName:%s",e.b);
         printf("\nPrice: %f",e.c);
         switch(f){
            case clothing:
            printf("\nType:Clothing");
            break;
            case footwear:
            printf("\nType:footwear");
            break;
            case electronics:
            printf("\nType:electronics");
            break;
         }
        if(f==0||f==1){
         printf("\nsize: %f",g.d);
      } else{
         printf("\nweight:%f",g.d);
      }
      }}
    return 0;
   }
   
