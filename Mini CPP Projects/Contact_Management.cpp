//contact management system using file handling
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

//global variable
string fname,lname,phone_num;

//printing menu
int menu()
{
    int sel;
    cout<<"\t\t======= Contact Management  ======="<<endl;
    cout<<"\t\t1. Add "<<endl;
    cout<<"\t\t2. Search"<<endl;
    cout<<"\t\t3. help"<<endl;
    cout<<"\t\t4. Exit"<<endl;
    cout<<"\n\t\tEnter ";
    cin>>sel;
    return sel;
}

bool check_phone(string s)
{
    if(s.length() == 10)
        return true;
    else
        return false;
}


bool check_num(string s)
{
    bool check= true;
    for(int i=0;i<s.length();i++)
    {
        if(!(int(s[i]) >= 48 && int(s[i]) <=57))
        {
            check = false;
        }
    }
    if(check == true)
        return true;
    else
        return false;

}


//add to contact list
void add()
{
    ofstream phone("numbers.txt",ios::app);

    system("cls");
    cout<<"\t====== Add New Contact ======="<<endl;
    cout<<"Enter first name ";
    cin>>fname;
    cout<<"Enter last name ";
    cin>>lname;
    cout<<"Enter phone number ";
    cin>>phone_num;

    if(check_phone(phone_num)==true)
    {
        if(check_num(phone_num)== true)
        {
            if(phone.is_open())
            {
                phone <<fname <<" " <<lname <<" "<<phone_num <<endl;
                cout<<"contact saved";
            }
            else
            {
                cout<<"Can't open file ";
            }
        }
        else
        {
            cout<<"Phone number must contain digit only!";
        }
    }
    else
    {
        cout<<"\nPhone number must be 10 digits ";
    }

    phone.close();

}

void search_con()
{
    bool found = false;
    ifstream myfile("numbers.txt");
    string user_input;
    cout<<"Enter Name to search : ";
    cin>>user_input;
    while(myfile>>fname >>lname >>phone_num)
    {
        if(user_input== fname || user_input == lname)
        {
            cout<<"\ncontact details \n\n ";
            cout<<"\nFirst name : "<<fname;
            cout<<"\nLast name : "<< lname;
            cout<<"\nPhone number is "<<phone_num;
            found = true;
        }
    }
    if(found == false)
        cout<<"No such contact "<<endl;
}

void help()
{
    cout<<"You can't get help "<<endl;
}

int main()
{
    while(1)
    {
    system("cls");
        switch(menu())
        {
        case 1:
            add();
            break;
        case 2:
            search_con();
            break;
        case 3:
            help();
            break;
        case 4:
            exit(0);
        default:
            cout<<"\t\tInvalid input!\n\t\t";
        }
cout<<"\n";
    system("pause");
    }

}
