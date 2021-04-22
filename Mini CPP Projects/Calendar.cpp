#include <iostream>
#include <stdlib.h>
using namespace std;
int first_day(int);
int main()
{
    int year,day,week;
    int days_months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    char c ='y';
	while(c=='y'||c=='Y')
	{
	    system("cls");
	    system("color 70");
        cout<<"\n\t\t===== Calendar ===== \n\n\t\tPress CTRL+Break to Exit\n\n";

        cout<<"\n\t\tEnter Year ";
        cin>>year;


    //checking leap year
    if(year%4 == 0 && year %100 != 0 || year%400 == 0)
        days_months[1]=29;
    //getting first day of the year
    day = first_day(year);

	for(int i=0;i<=11;i++)
    {
        system("color f0");
        cout<<"\n\n\t\t"<<months[i]<<","<<year;

        cout<<"\n\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n";
        for(int j=0;j<day;j++)
        {
            cout<<"      ";
        }
        week = day;
        for(int m=1;m<=days_months[i];m++)
        {
            if(m<=10)
                cout<<"     ";
            else
                cout<<"    ";
            if(week>6)
            {
                cout<<"\n    "<<m;
                week = 0;
            }
            else
            {
                cout<<m;
            }
            week++;
        }
        day = week;
    }

    cout<<"\n";
    cout<<"Do you want to print another ? (Y/N) "<<endl;
    cin>>c;

	}

}

//finding first day of year
int first_day(int year)
{
    int day;
    day = (((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
    return day;
}
