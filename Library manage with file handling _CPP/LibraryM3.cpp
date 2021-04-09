//update record from file
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
            cout<<"No Record !"<<endl; //file not found
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
            cout<<"\nNo record found !"<<endl; //file not found
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
        cout<<"\n";

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
                else
                {
                    cout<<"Deleted Successfully !"<<endl;
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

    void updateBook(char *t)
    {
        fstream file;
        file.open("Library.dat",ios::in | ios::out | ios::ate | ios::binary);

        file.seekg(0);
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(!strcmp(t,title))
            {
                setBookData();
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
            else
            {
                cout<<"No record !"<<endl;
                return;
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();
        cout<<"Updated Successfully"<<endl;
    }

    void deleteAll()
    {
        remove("Library.dat");
        cout<<"All records Deleted !"<<endl;
    }


};

int menu()
{
    int m;
    cout<<"\t===== * Welcome to Library * ====="<<endl;
    cout<<" 1. Insert Book "<<endl;
    cout<<" 2. Show Book "<<endl;
    cout<<" 3. Search Book "<<endl;
    cout<<" 4. Update Book "<<endl;
    cout<<" 5. Show All Books "<<endl;
    cout<<" 6. Delete Book "<<endl;
    cout<<" 7. Delete All Data"<<endl;
    cout<<" 8. Exit "<<endl;
    cout<<"\n Enter Choice ";
    cin>>m;
    return m;
}


int main()
{
    Book b1;
    char Title[20];
    int a;

    while(1)
    {


        system("cls");
        switch(menu())
        {
        case 1:
            b1.setBookData();
            a = b1.saveBook();
            if(a)
            {
                cout<<"Saved Successfully "<<endl;
            }
            else
            {
                cout<<"Unable to save !"<<endl;
            }
            break;
        case 2:
            b1.showBookData();
            break;
        case 3:
            cout<<"Enter Book title to Search ";
            cin.ignore();
            cin.getline(Title,19);
            b1.searchBook(Title);
            break;
        case 4:
            cout<<"Enter Book title to update ";
            cin>>Title;
            b1.updateBook(Title);
            break;
        case 5:
            b1.showAllBooks();
            break;
        case 6:
            cout<<"Enter Book title to delete";
            cin>>Title;
            b1.deleteBook(Title);
            break;
        case 7:
            b1.deleteAll();
            break;
        case 8:
            cout<<"Thanks for Using !"<<endl;
            exit(0);
        default:
            cout<<"Invalid input !"<<endl;
            break;

        }
        system("pause");
    }



}
