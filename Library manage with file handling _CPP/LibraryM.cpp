//Library management system 1
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;


class Book
{
private:
    char title[20];
    int price ;
    int bookid;
public:
    void setData()
    {
        cout<<"Enter Book id ,Title and Price";
        cin>>bookid;
        cin.ignore();
        cin.getline(title,19);  //taking input string in title
        cin>>price;
    }
    void showData()
    {
        cout<<"\nBook id = "<<bookid<<", Title = "<<title<<", Price = "<<price<<endl;
    }

    //constructor
    Book()
    {
        bookid = 0;
        strcpy(title,"no title");
        price = 0;
    }
    int saveData(); //i will define outside of the class

    //read data from file
    void showLibrary()
    {
        ifstream fileIn;
        fileIn.open("Library.dat",ios::in | ios::binary);
        if(!fileIn)
        {
            cout<<"\nFile not fount"<<endl;
        }
        else
        {
            fileIn.read((char*)this,sizeof(*this));  //reading all data from file
            while(!fileIn.eof())
            {
                showData();
                fileIn.read((char*)this,sizeof(*this));
            }
            fileIn.close();

        }

    }
};

//saving data in file
int Book::saveData()
{
    if(bookid == 0)
    {
        cout<<"Unable to save"<<endl;
        return 0;
    }
    else
    {
    ofstream fileout; //create an object
    fileout.open("Library.dat",ios::app |ios::binary);
    fileout.write((char*)this,sizeof(*this));  //writing data to the file
    fileout.close();
    return 1;
    }
}



int main()
{
    system("cls");
    Book b1,b2;
    b1.showData();
    b1.showLibrary();

    system("pause");
}
