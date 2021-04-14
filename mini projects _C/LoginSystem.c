//creating a login system using file handling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void signup();
void login();
int menu();
struct user
{
    char name[20];
    char password[20];
};

    struct user u1;

void signup()
{
    printf("\tWelcome to SignUp page\n");
    printf("Enter user name ");
    fflush(stdin);
    gets(u1.name);
    printf("Enter password ");
    fflush(stdin);
    gets(u1.password);

    FILE *fp;
    fp = fopen("file1.bin","ab");
    if(fp==NULL)
        printf("file not found!\n");
    fwrite(&u1,sizeof(struct user),1,fp);

    fclose(fp);

}
void login()
{
    int c=0;
    struct user u;
    printf("\tWelcome to Login page\n");
    printf("Enter user name ");
    fflush(stdin);
    gets(u1.name);

    printf("Enter password ");
    fflush(stdin);
    gets(u1.password);

    FILE *fp;

    fp = fopen("file1.bin","rb");
    if(fp==NULL)
        printf("file not found!\n");
    while(fread(&u,sizeof(struct user),1,fp))
    {

    int x = strcmp(u1.name,u.name);
    int y = strcmp(u1.password,u.password);

    if(x == 0 && y== 0)
    {
        printf("login Success \n");
        printf("your name is %s \n",u.name);
        c++;
    }
    }
    if(c>1)
        printf("Multiple Account found!\n");
    fclose(fp);

}


int menu()
{
    int x;
    printf("\tWelcome to Login System\n");
    printf(" 1. SignUp\n");
    printf(" 2. LogIn\n");
    printf(" 3. Exit\n");
    printf("\n Enter your choice ");
    fflush(stdin);
    scanf("%d",&x);
    return x;
}
void main()
{
    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    system("pause");
    }
}
