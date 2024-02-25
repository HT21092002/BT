
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int songuyento (int n){
    if (n < 2)    
        return 0;

    for (int i = 2; i <= sqrt((float)n); i ++)
    {
        if (n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char *argv[]) {
    int num1, num2;
    int i;
    if (argc !=3) {
        printf("Usage: %s <number1> <number2> \n", argv[0]);
        return 1;
    }
    num1 = atoi(argv[1]);
     num2 =atoi(argv[2]);
     if((num1>num2)||(num1<0|num2<0)||num2>=(10^9)){
        printf("khoang so ban nhap khong dung vui long nhap lai");
     }else{
    for(i=num1; i<= num2; i++){
        if (songuyento(i)){
            printf("cac so nguyen to la %d\n",i);
        }
    }}
    return 0;
    }



  



