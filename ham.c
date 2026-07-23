#include <stdio.h>
#include <math.h>
int NUMBER_OF_DAYS_OF_THE_MONTH(int a, int b){
    switch (a){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        break;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        break;
        case 2:
        if(b%400==0||(b%4==0&b%100!=0)){
            return 29;
        } else{
            return 28;
        }
    }
}
int day_of_the_year(int a, int b, int c){
    int doty=0;
    for(int i=1;i<b;i++){
        doty+= NUMBER_OF_DAYS_OF_THE_MONTH(i,c);
    } doty+=a;
    return doty;
}
void yesterday(int a, int b, int c){
    if(a==1){
        if (b==1){
            a=31;
            b=12;
            c-=1;
        } else{
            b-=1;
            a= NUMBER_OF_DAYS_OF_THE_MONTH(b,c);
        }
    } else{
        a-=1;
    }
    printf ("\nNgay %d thang %d cua nam %d la ngay truoc do ban moi nhap",a,b,c);
}
void nextday (int a,int b,int c){
    if (a==NUMBER_OF_DAYS_OF_THE_MONTH(b,c)){
        if(b=12){
        a=1;
        b=1;
        c+=1;}
        else {
            a=1;
            b+=1;
        } 
    } else {
            a+=1;
        }  printf("\nNgay %d thang %d cua nam %d la ngay tiep theo ban moi nhap",a,b,c);
}
int main()
{
    // nhap lieu
    int day, month, year;
    for (int i;;i++){
    do{
    printf("\nnhap vao ngay:");
    scanf ("%d",&day);
    printf("nhap vao thang:");
    scanf("%d",&month);
    printf("nhap vao nam:");
    scanf("%d",&year);} while (day<=0||day>31|| month<=0||month>12||year<=0);
    printf("Thang %d cua nam %d co %d ngay",month,year,NUMBER_OF_DAYS_OF_THE_MONTH(month,year));
    printf("\nNgay %d cua thang %d la ngay thu %d cua nam %d",day,month,day_of_the_year(day,month,year),year);
    yesterday(day,month,year);
    nextday(day,month,year);
    }
     return 0;
}