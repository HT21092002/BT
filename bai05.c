#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	 char name[50];
	 char phone_number[50];
	 char address[50];
} infomation;
void enter_infomation(){
    FILE*f =fopen("bai05.txt","a");
	if (f == NULL) {
        printf("Cannot open file.\n");
        return ;
    }
	//nhapthong tin
	 infomation contact;
   printf("Enter name:");
   fgets(contact.name,sizeof(contact.name),stdin);
   printf("Enter phone number:");
   fgets(contact.phone_number,sizeof(contact.phone_number),stdin);
   printf("Enter address:");
   fgets(contact.address,sizeof(contact.address),stdin);
   //ghi vao file
   fprintf(f,"%s%s%s",contact.name,contact.phone_number,contact.address);
   //in ra hoàn thành
   printf("Contact has been added successfully.\n");
   fclose(f);
}
void DISPLAY_ALL(){
	infomation contact;
	FILE *f = fopen("bai05.txt", "r");
        if (f == NULL) {
        printf("Cannot open file.\n");
        return ;
    }
	int num=1;
	while (fgets (contact.name, sizeof(contact.name), f) != NULL) {
        fgets (contact.phone_number, sizeof(contact.phone_number), f);
        fgets (contact.address, sizeof(contact.address), f);
		printf("%dName: %s\n", num, contact.name); // in ra số thứ tự của contact
        printf("Phone: %s\n", contact.phone_number);
        printf("Address: %s\n", contact.address);
        printf ("\n");
		num++;
		}
    fclose(f);
}
void FIND_CONTACT ()
{   
    //mở file dưới mode đọc file
    FILE *f = fopen("bai05.txt", "r");
    if (f == NULL) {
        printf("Cannot open file.\n");
        return ;
    }

     infomation contact;
    char find_contact [50];

    printf ("Enter name to search for: ");

    fgets(find_contact, sizeof (find_contact), stdin); // nhập tên để tìm kiếm contact
	getchar();
    // tìm kiếm bằng cách duyệt file CONTACT_DATA.txt con trỏ file lúc này chạy theo fgets.
    while (fgets (contact.name, sizeof(contact.name), f) != NULL) {
        fgets (contact.phone_number, sizeof(contact.phone_number), f);
        fgets (contact.address, sizeof(contact.address), f);
        //tìm tên contact
        if (strcmp (find_contact, contact.name ) == 0 )
        {
            printf ("Contact found:\n");
            printf ("Name: %s\n",contact.name);
            printf ("Phone: %s\n", contact.phone_number);
            printf ("Address: %s\n", contact.address);
        }
    }
    fclose(f);
}
int main ()
{   
    int menu_select; 
    int a = 0;
    //in ra menu sử dụng while (a) : lặp vô tận
    while (a==0)
    {
        printf ("\nWelcome to the Contact Manager!\n1. Add a new contact\n2. Display all contacts\n3. Search for a contact\n4. Exit\n\n");
        printf ("Enter your choice: ");
        scanf ("%d", &menu_select);
        while ( getchar() != '\n' ); // xóa bộ đệm
        switch (menu_select)
        {

            case 1:
                enter_infomation ();
                break;
            case 2:
                DISPLAY_ALL ();
                break;
            case 3:
                FIND_CONTACT ();
                break;
            case 4:
                printf ("Goodbye!\n");
                return 0;
            default:
                printf ("Invalid selection! Please enter a valid choice.");
                break;
        }
    }

return 0;

}
