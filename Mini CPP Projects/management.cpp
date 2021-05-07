//Management system

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//main structure
struct student
{
    string roll,name,section;
    float total,marks,percent;
};

//create array for student structure
struct student s[5];
int i=0;

//create insert function
void insert_rec(struct student s[])
{
    system("cls");
    cout<<"\n\t ======== Insert student records =======\n"<<endl;
    cout<<"\nName : ";
    cin>>s[i].name;

    cout<<"\nRoll No. : ";
    cin>>s[i].roll;


    cout<<"\nSection : ";
    cin>>s[i].section;

    cout<<"\nTotal marks : ";
    cin>>s[i].total;

    cout<<"\nStudent Marks : ";
    cin>>s[i].marks;

//    percentage of marks

    s[i].percent = (s[i].marks /s[i].total) *100;
}

//showing the inserted records
void show_rec(struct student s[])
{
    int Count = 1;
    system("cls");
    cout<<"\n\t========= Student Details =========\n"<<endl;

    for(int st=0;st<i;st++)
    {
        cout<<"\nStudent S.N. "<<Count<<endl;
        cout<<"Name : "<<s[st].name<<endl;
        cout<<"Roll : "<<s[st].roll<<endl;
        cout<<"section : "<<s[st].section<<endl;
        cout<<"Total Marks : "<<s[st].total<<endl;
        cout<<"Student Marks : "<<s[st].marks<<endl;
        cout<<"Final Percentage : "<<s[st].percent<<"%"<<endl;
        Count++;
    }
}

//search record
void search_rec(student s[])
{
    string roll;
    int check=0;
    system("cls");
    cout<<"\n\t ========== Search Records =========\n"<<endl;
    if(i>0)
    {
        cout<<"Enter Roll no. for search : ";
        cin>>roll;
        //search one by one
        for(int j=0;j<=i;j++)
        {
            if(roll == s[j].roll)
            {
                check++;
                cout<<"Name : "<<s[j].name<<endl;
                cout<<"Roll : "<<s[j].roll<<endl;
                cout<<"section : "<<s[j].section<<endl;
                cout<<"Total Marks : "<<s[j].total<<endl;
                cout<<"Student Marks : "<<s[j].marks<<endl;
                cout<<"Final Percentage : "<<s[j].percent<<"%"<<endl;
            }
        }
            if(check==0)
            {
                cout<<"\nRecord not found!"<<endl;

            }
    }
}

//update record
void update_rec(student s[])
{
    string roll;
    int check=0;
    system("cls");
    cout<<"\n\t =========== Update Record ========="<<endl;
    //check if data available
    if(i>0)
    {
        cout<<"\nEnter Roll no. for update : ";
        cin>>roll;

        for(int j=0;j<i;j++)
        {
            if(roll == s[j].roll)
            {
                check++;
                system("cls");
                cout<<"\n\t ======== Insert student records =======\n"<<endl;
                cout<<"\nName : ";
                cin>>s[j].name;

                cout<<"\nRoll No. : ";
                cin>>s[j].roll;


                cout<<"\nSection : ";
                cin>>s[j].section;

                cout<<"\nTotal marks : ";
                cin>>s[j].total;

                cout<<"\nStudent Marks : ";
                cin>>s[j].marks;

                s[j].percent = (s[j].marks /s[j].total) *100;
            }
        }
        if(check == 0)
        {
            cout<<"\nRecord not found ";
        }

    }
}

//delete record
void delete_rec(student s[])
{
    string roll;
    string temp_roll,temp_name,temp_section;
    float temp_total,temp_marks,temp_percent;
    int count=0;
    system("cls");
    cout<<"\n\t============ Delete Record ============="<<endl;

    //data is available ?
    if(i>0)
    {
        cout<<"\nEnter Roll no. to delete record : ";
        cin>>roll;
        for(int j=0;j<i;j++)
        {
            if(roll == s[j].roll)
            {
                count++;
                for(int k=j;k<i;k++)
                {
                    //swapping data for deletion
                    temp_name = s[j+1].name;
                    temp_roll = s[j+1].roll;
                    temp_section = s[j+1].section;
                    temp_total = s[j+1].total;
                    temp_marks = s[j+1].marks;
                    temp_percent = s[j+1].percent;

                    s[j].name = temp_name;
                    s[j].roll = temp_roll;
                    s[j].section = temp_section;
                    s[j].total = temp_total;
                    s[j].marks = temp_marks;
                    s[j].percent = temp_percent;


                }
                i--;
                cout<<"\nRecord Deleted Successfully !"<<endl;

            }
        }
        if(count==0)
        {
            cout<<"\nRecord not found!"<<endl;
        }
    }

}


int menu()
{
    int choice;
    cout<<"\n\t ======== Main Menu ========"<<endl;
    cout<<"\n1. Insert "<<endl;
    cout<<"\n2. Show"<<endl;
    cout<<"\n3. Search"<<endl;
    cout<<"\n4. Update"<<endl;
    cout<<"\n5. Delete"<<endl;
    cout<<"\n6. Exit "<<endl;
    cout<<"\n\nEnter Your choice : ";
    cin>>choice;
    return choice;

}

//main program

main()
{
    int n = 0;
    char check;

    while(!n)
    {
        system("cls");
             switch(menu())
        {
        case 1:
            do
            {
                insert_rec(s);
                i++;  //this is for index of student array
                cout<<"\n\n Add More (Y/N)? ";
                cin>>check;
            }while(check=='Y' || check == 'y');
            break;
        case 2:
            show_rec(s);
            break;
        case 3:
            search_rec(s);
            break;
        case 4:
            update_rec(s);
            break;
        case 5:
            delete_rec(s);
            break;
        case 6:
            exit(0);
        default:
            cout<<"Invalid input ! \n";
        }
        system("pause");
    }

}
