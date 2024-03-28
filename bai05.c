#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	 char name[50];
	 char phone_number[50];
	 char address[50];
} infomation;
int main(){
	int number;
	char searchname[50];
	int num=1;
	infomation* id;
	id = (infomation* )malloc(sizeof(infomation) * num);
	char name[50];
	char phone_number[50];
	infomation infomation;
	char address [50];
	FILE *f;
	if(f == NULL){
		printf("\n Loi tao hoac mo file");
		exit(1);
	} 
	do{
	printf("1. Add a new contact");
	printf("\n2. Display all contact");
	printf("\n3. search for a contact");
	printf("\n4. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&number);
	getchar();
	switch(number){
		case 1:
		printf("Enter name:");
		fgets(name, sizeof(name), stdin);
        printf("Enter your phone number: ");
		fgets(phone_number, sizeof(phone_number), stdin);
		printf("Enter address:");
		fgets(address, sizeof(address), stdin);
		getchar ();
		f = fopen("bai05.txt", "a");
		fputs(infomation.name,f);
		 fputs(infomation.phone_number,f);
		 fputs(infomation.address,f);
		 fclose (f);
		num++;		
		break;
		id[num++]=infomation;
		strcpy(infomation.name, name);
		strcpy(infomation.phone_number, phone_number);
		strcpy(infomation.address, address);
		case 2:
		f = fopen("bai05.txt", "r");
		while(!feof (f)){
			char ch= fgetc(f);
			printf("%c",ch);
		}
		break;
		case 3:
      printf("\nEnter the name research:");
	  fgets(searchname, sizeof(searchname), stdin);
      for (int i = 1; i <=num; i++)
      {
         if (strcmp(searchname, id[i].name) == 0)
         printf("Name:%s,Phone_number:%s,address:%s",id[i].name,id[i].phone_number,id[i].address);
      }
		break;
		case 4:
		printf("Goodbye!");
		break;
		default:
		printf("ban nhap vao so khong dung vui long nhap lai");
		break;
	}
	}while(number);
}