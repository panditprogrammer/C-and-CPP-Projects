//delete record from file
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

class Book
{
private:
    int bookid;
    char title[20];
    float price;
public:
    Book()
    {
        bookid= 0;
        strcpy(title,"no title"); //assingin data in title
        price = 0;
    }

    //getting input
    void setBookData()
    {
        cout<<"Enter bookid, title and price of a book";
        cin>>bookid;
        cin.ignore(); //for buffer
        cin.getline(title,12); //taking input in char array
        cin>>price;
    }

    //display book
    void showBookData()
    {
        cout<<"\nBookid = "<<bookid<<", Title = "<<title<<", Price = "<<price<<endl;
    }

    //store book into file
    int saveBook()
    {
        if(bookid == 0)
        {
            //cout<<"Empty Book record cannot save "<<endl;
            return 0;
        }
        else
        {
            ofstream fileOut;
            fileOut.open("Library.dat",ios::app | ios::binary);
            fileOut.write((char*)this,sizeof(*this));
            fileOut.close();
            return 1;
        }

    }

    //showing all book information
    void showAllBooks()
    {
        ifstream fileIn;
        fileIn.open("Library.dat",ios::in | ios::binary); //opening file
        if(!fileIn)
        {
            cout<<"File not found!";
        }
        else
        {
            //reading file content
            fileIn.read((char*)this,sizeof(*this));
            while(!fileIn.eof())
            {
                showBookData();
                fileIn.read((char*)this,sizeof(*this));
            }
            fileIn.close();
        }

    }

    //searching book data
    void searchBook(char *t)
    {
        int x=0;
        ifstream fileIn;
        fileIn.open("Library.dat",ios::in | ios::binary);

        //checking file exist or not
        if(!fileIn)
        {
            cout<<"\nFile not found"<<endl;
        }
        else
        {
            fileIn.read((char*)this,sizeof(*this));

            while(!fileIn.eof())
            {
                if(!strcmp(t,title))
                {
                    showBookData();
                    x++;
                }
                    fileIn.read((char*)this,sizeof(*this));
            }
            //checking record found or not
            if(x==0)
            {
                cout<<"\nNo record found"<<endl;
            }

            fileIn.close();
        }

    }

    //delete book record
    void deleteBook(char *t)
    {
        ifstream fileIn;
        ofstream fileOut;

        fileIn.open("Library.dat",ios::in | ios::binary);
        if(!fileIn)
        {
            cout<<"\nFile not Found!"<<endl;
        }
        else
        {
            fileOut.open("temp.dat",ios::out | ios::binary);
            fileIn.read((char*)this,sizeof(*this));
            while(!fileIn.eof())
            {
                //checking title with provide by user to delete
                if(strcmp(title,t))
                {
                    fileOut.write((char*)this,sizeof(*this));

                }
                fileIn.read((char *)this,sizeof(*this));
            }
            fileIn.close();
            fileOut.close();
            //remove old file and rename file
            remove("Library.dat");
            rename("temp.dat","Library.dat");
        }
    }

};


int main()
{
    Book b1;

    cout<<"Searching book... "<<endl;
    b1.searchBook("python");

    cout<<"\n showing all books"<<endl;
    b1.showAllBooks();

    cout<<"\n delete a book"<<endl;
    b1.deleteBook("php");

    cout<<"\n After deleting book "<<endl;
    b1.showAllBooks();

    b1.setBookData();
    b1.saveBook();









}
