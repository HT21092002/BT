#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void xoa_xuong_dong(char x[])
{
   size_t len = strlen(x);
   if (x[len - 1] = '\n')
   {
      x[len - 1] = '\0';
   }
}
typedef enum
{
   CLOTHING,
   FOOTWEAR,
   ELECTRONICS,
} ProductType;
typedef union
{
   float weight;
   float size;
} ProductData;
typedef struct
{
   char name[20];
   float price;
   ProductType type;
   ProductData data;
} Product_t;
int main()
{
   int num_products;
   char name[20];
   float price;
   ProductType type;
   Product_t product_item;
   float size;
   float weight;
   Product_t* product_array;
   product_array = (Product_t* )malloc(sizeof(Product_t) * num_products);
   // nhap so luong
   printf("Enter the number of products: ");
   scanf("%d", &num_products);
   getchar();
   // nhap thong tin
   for (int i = 0; i < num_products; i++)
   {
      printf("\nenter the name product %d: ", i);
      printf("\nName: ");
      fgets(name, sizeof(name), stdin);
      printf("Price: ");
      scanf("%f", &price);
      do
      {
         printf("Type: ");
         scanf("%d", &type);
      } while (type < 0 || type > 2);
      // tuy theo type nhap ma in ra size hay weight
      if (type == ELECTRONICS)
      {
         printf("input weight:");
         scanf("%f", &weight);
      }
      else
      {
         printf("input size:");
         scanf("%f", &size);
      }
      // gom thong tin lai dua va struct
      ProductData data;
      if (type == ELECTRONICS)
      {
         data.weight = weight;
      }
      else
      {
         data.size = size;
      }
      strcpy(product_item.name, name);
      product_item.price = price;
      product_item.type = type;
      product_item.data = data;
      getchar();
      product_array[i] = product_item;
   }
   // nhap ten san pham can tra cuu
   char searchname[30];
     for(int i=0;;i++){
      printf("\nEnter the name of the product to retrieve information:");
      fgets(searchname, sizeof(searchname), stdin);
      for (int i = 0; i < num_products; i++)
      {
         if (strcmp(searchname, product_array[i].name) == 0)
         {
            if((product_array[i].type)==ELECTRONICS){
            printf("Name:%s, Price:%f, type:%d, Weight:%f", product_array[i].name, product_array[i].price, product_array[i].type, product_array[i].data.weight);}
            else{
               printf("Name:%s, Price:%f, type:%d, size:%f", product_array[i].name, product_array[i].price, product_array[i].type, product_array[i].data.size);
            }
         }
      }}
   //  xuat ra thong tin can tim
   return 0;
}

   
