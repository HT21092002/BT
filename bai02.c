
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
union Detail {
    int size;
    float weight;
};
enum Type {
    CLOTHING = 0,
    FOOTWEAR = 1,
    ELECTRONICS = 2
};
struct Product {
    char name[50];
    float price;
    enum Type type;
    union Detail detail;
};
 int main(){
   int number;
   // Nhập số lượng sản phẩm
    do{
   printf("Enter number product:");
   scanf("%d",&number);
   getchar(); //xóa kí tự \n 
}while (number<=0);
  // Cấp phát bộ nhớ động cho mảng các struct Product
    struct Product* products = (struct Product*)malloc(number * sizeof(struct Product));
  for (int i=0;i<number;i++){
   printf("\nEnter information for product %d:\n",i+1);
   printf("Name: ");
   fgets(products[i].name, sizeof(products[i].name), stdin);
   products[i].name[strcspn(products[i].name, "\n")] = 0; // Cắt bỏ ký tự \n ở cuối chuỗi
   printf("Price: ");
        scanf("%f", &products[i].price);
 printf("Type (0: Clothing, 1: Footwear, 2: Electronics): ");
        int type_input;
        scanf("%d", &type_input);
        products[i].type = (enum Type)type_input;
        // Xử lý thông tin riêng dựa theo loại sản phẩm
        if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) {
            printf("Size: ");
            scanf("%d", &products[i].detail.size);
        } else if (products[i].type == ELECTRONICS) {
            printf("Weight: ");
            scanf("%f", &products[i].detail.weight);
        }
        
        getchar(); // Xóa ký tự \n còn thừa để hàm fgets của vòng lặp sau hoạt động đúng
   } 
   // Phần Tra cứu thông tin sản phẩm
   printf("\nEnter the name of the product to retrieve information: ");
    char searchName[50];
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    int found = 0; // Cờ kiểm tra xem có tìm thấy sản phẩm không
    // Vòng lặp duyệt mảng và dùng strcmp để so sánh tên
    for (int i = 0; i < number; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("\nProduct Information:\n");
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            
            if (products[i].type == CLOTHING) {
                printf("Type: Clothing\n");
                printf("Size: %d\n", products[i].detail.size);
            } else if (products[i].type == FOOTWEAR) {
                printf("Type: Footwear\n");
                printf("Size: %d\n", products[i].detail.size);
            } else if (products[i].type == ELECTRONICS) {
                printf("Type: Electronics\n");
                printf("Weight: %.2f\n", products[i].detail.weight);
            }
            
            found = 1;
            break; // Tìm thấy thì in ra và thoát vòng lặp tra cứu
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }

    // Giải phóng bộ nhớ động sau khi sử dụng xong
    free(products);
       return 0;
 }

 



  



