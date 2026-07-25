#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct ALUMNUS
{
   char name [50];
   int studentID;
   float averagescore;

};
void Enter_Student_List(int n, struct ALUMNUS* ALUMNUS)
{
   getchar(); //xóa kí tự \n 
   for(int i=0;i<n;i++){
     printf("\nEnter information of sstudent %d:\n",i+1);
      printf("NAME STUDENT: ");
     fgets(ALUMNUS[i].name, sizeof(ALUMNUS[i].name), stdin);
     ALUMNUS[i].name[strcspn(ALUMNUS[i].name, "\n")] = 0;
      printf("STUDENT ID: ");
      scanf("%d",&ALUMNUS[i].studentID);
      printf("averagescore: ");
      scanf("%f",&ALUMNUS[i].averagescore);
      getchar();
   }
}
void Display_the_list_of_stdent(int n ,struct ALUMNUS* ALUMNUS){
         for(int i=0;i<n;i++){
             printf("\nPrint information of student %d:\n",i+1);
             printf("NAME STUDENT:%s\n ",ALUMNUS[i].name);
             printf("STUDENT ID:%d\n ", ALUMNUS[i].studentID);
             printf("averagescore:%f\n ", ALUMNUS[i].averagescore);
         }

}
struct ALUMNUS* Find_the_student_with_the_highest_cost(int n ,struct ALUMNUS* ALUMNUS){
   struct ALUMNUS* max_student=& ALUMNUS[0];
 for(int i=0;i<n;i++){
   // So sánh điểm trung bình (nếu averagescore là float):
        if (ALUMNUS[i].averagescore > max_student->averagescore) {
            max_student = &ALUMNUS[i]; // Cập nhật lại con trỏ trỏ đến sinh viên cao điểm hơn
        }
 }
 return max_student;
}
void print_the_student_with_highest_cost (struct ALUMNUS* max_student){
      printf("the_student_with_highest_cost:%f",max_student->averagescore);
}
int main(){
    struct ALUMNUS * ALUMNUS;
    struct ALUMNUS * max_student;
    int n;
   printf("Enter the number of students:");
   scanf("%d",&n);
    // 2. Cấp phát bộ nhớ tại main
    ALUMNUS = (struct ALUMNUS*)malloc(n * sizeof(struct ALUMNUS));
    if (ALUMNUS == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
     Enter_Student_List(n, ALUMNUS);
     Display_the_list_of_stdent(n,ALUMNUS);
     max_student=Find_the_student_with_the_highest_cost(n,ALUMNUS);
     print_the_student_with_highest_cost(max_student);
  free(ALUMNUS);
   return 0;
}