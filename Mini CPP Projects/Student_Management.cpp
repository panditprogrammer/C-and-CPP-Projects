//student management system using file handling
//create read update and delete record using file handling
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


class student
{
private:
    string name,roll,course,email,address;


public:
    int menu()
    {
        int select;
        cout<<"\t\t======================="<<endl;
        cout<<"\t\t|  Student Management |"<<endl;
        cout<<"\t\t======================="<<endl;

        cout<<"\n\t\t 1. Enter New Record "<<endl;
        cout<<"\t\t 2. Show Record "<<endl;
        cout<<"\t\t 3. Update Record "<<endl;
        cout<<"\t\t 4. Search Record "<<endl;
        cout<<"\t\t 5. Delete Record "<<endl;
        cout<<"\t\t 6. Exit "<<endl;

        cout<<"\n\t\tSelect option ";
        cin>>select;
        return select;
    }
//take user input and write into the file
    void Insert()
    {
        system("cls");

        fstream file;

        cout<<"\t\t====== Add Student ======"<<endl;
        cout<<"\n\t\tEnter Name ";
        cin>>name;
        cout<<"\t\tEnter Roll : ";
        cin>>roll;
        cout<<"\t\tEnter Course : ";
        cin>>course;
        cout<<"\t\tEnter Email Id : ";
        cin>>email;
        cout<<"\t\tEnter Address : ";
        cin>>address;

        //inserting into the file
        file.open("Student_Record.txt",ios::app | ios::out);
        file<<" "<<name<<" "<<roll<<" "<<course<<" "<<email<<" "<<address<<"\n";
        file.close();


    }

//student data showing
void showData()
{
    system("cls");
    int total_num_rec = 0;
    fstream file;

    cout<<"\t\t====== Students Records ======"<<endl;

    file.open("Student_Record.txt",ios::in);
    //checking if file is available
    if(!file)
    {
        cout<<"\n\t\tNo Records Available!\n\t\t"<<endl;
        file.close();
    }
    else
    {   //fetching all data from file
        file>>name>>roll>>course>>email>>address;
        while(!file.eof())
        {
            total_num_rec+=1;
            cout<<"\n\t\tStudent No. : "<<total_num_rec<<endl;
            cout<<"\t\tStudent Name : "<<name<<endl;
            cout<<"\t\tStudent Roll : "<<roll<<endl;
            cout<<"\t\tStudent Course : "<<course<<endl;
            cout<<"\t\tStudent Email id : "<<email<<endl;
            cout<<"\t\tStudent Address : "<<address<<endl;
            cout<<"\n\t\t";
            file>>name>>roll>>course>>email>>address;
        }

        if(total_num_rec==0)
        {
            cout<<"\n\t\tNo Record Available!\n\t\t";
        }
    }
    file.close();
}

//updating data in file
void update()
{
    int check=0;
    string r;
    system("cls");
    fstream file,file1;

    cout<<"\t\t====== Update Record ======"<<endl;
    file.open("Student_Record.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\tNo Record available \n\t\t";
        file.close();
    }
    else
    {
        cout<<"\n\t\tEnter Roll no to update : ";
        cin>>r;

        file1.open("Temp.txt",ios::app | ios::out);
        file>>name>>roll>>course>>email>>address;

        while(!file.eof())
        {
            if(r != roll)
            {
                file1<<" "<<name<<" "<<roll<<" "<<course<<" "<<email<<" "<<address<<"\n";
            }
            else
            {
                cout<<"\n\t\tEnter Name : ";
                cin>>name;
                cout<<"\t\tEnter Roll : ";
                cin>>roll;
                cout<<"\t\tEnter Course : ";
                cin>>course;
                cout<<"\t\tEnter Email Id : ";
                cin>>email;
                cout<<"\t\tEnter Address : ";
                cin>>address;
                file1<<" "<<name<<" "<<roll<<" "<<course<<" "<<email<<" "<<address<<"\n";
                check++;
            }
             file>>name>>roll>>course>>email>>address;

        }
        //checking roll no is exist or not
        if(check==0)
             {
                 cout<<"\n\t\tRoll no Not Available!\n\t\t";
             }

        file1.close();
        file.close();
        remove("Student_Record.txt");
        rename("Temp.txt","Student_Record.txt");

    }
}

//searching data
void Search()
{
    string rol;
    int check = 0;
    system("cls");
    fstream file;
    file.open("Student_Record.txt",ios::in);

    cout<<"\t\t====== Search student ======\n"<<endl;

    if(!file)
    {
        cout<<"\n\t\t No match available!\n\t\t"<<endl;
    }
    else
    {
        cout<<"\n\t\tEnter Roll no. to search : ";
        cin>>rol;
        //extracting data from file
        file>>name>>roll>>course>>email>>address;
        while(!file.eof())
        {
            if(rol == roll)
            {
                check++;
                cout<<"\b\t\tStudent Name : "<<name<<endl;
                cout<<"\t\tStudent Roll : "<<roll<<endl;
                cout<<"\t\tStudent Course : "<<course<<endl;
                cout<<"\t\tStudent Email id : "<<email<<endl;
                cout<<"\t\tStudent Address : "<<address<<endl;
            }
            //extracting data from file
            file>>name>>roll>>course>>email>>address;
        }
        //check roll is available or not
        if(check==0)
        {
            cout<<"\n\t\tStudent Roll "<<rol<<" not available!\n\t\t";
        }
        file.close();
    }
}

//void deleting student data
void Delete()
{
    system("cls");
    fstream file,file1;
    string r;
    int check =0;

    cout<<"\t\t====== Delete Student ======"<<endl;
    file.open("Student_Record.txt",ios::in);
    //checking file is exist
     if(!file)
    {
        cout<<"\n\t\tNo Records Available!\n\t\t"<<endl;
        file.close();
    }
    else
    {
        cout<<"\n\t\tEnter Roll no. to delete : ";
        cin>>r;
        //openning temp file and extracting data
        file1.open("Temp.txt",ios::app | ios::out);

        file>>name>>roll>>course>>email>>address;
        while(!file.eof())
        {
            if(roll != r)
            {
                file1<<" "<<name<<" "<<roll<<" "<<course<<" "<<email<<" "<<address<<"\n";
            }
            else
            {
                check++;
                cout<<"\n\t\tDeleted Successfully!\n\t\t";
            }
            file>>name>>roll>>course>>email>>address;
        }
        //checking roll number is exist
        if(check == 0)
        {
            cout<<"\n\t\tStudent Roll "<<r<<" not available!\n\t\t";
        }
        file1.close();
        file.close();
        //remove old file and creating new file and rename it as old
        remove("Student_Record.txt");
        rename("Temp.txt","Student_Record.txt");

    }
}

};


int main()
{
    char c;
    student s;

    while(1)
    {
        system("cls");
        switch(s.menu())
        {
        case 1:
            do
            {
                s.Insert();
                cout<<"\n\t\tAdd another student (Y/N) ";
                cin>>c;
            }while(c=='y' || c=='Y');
            break;
        case 2:
            s.showData();
            break;
        case 3:
            s.update();
            break;
        case 4:
            s.Search();
            break;
        case 5:
            s.Delete();
            break;
        case 6:
            exit(0);
            cout<<"\n\nThanks for using! \n\n";
            system("pause");
        default:
            cout<<"\n\t\tInvalid input! Try again..";
        }
        system("pause");

    }

}
