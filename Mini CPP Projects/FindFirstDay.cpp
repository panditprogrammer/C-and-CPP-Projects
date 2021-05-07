//finding first day of the month and year
#include <stdio.h>
#include <iostream>
using namespace std;

int first_day_year(int y)
{
    int d;
    d = (((y-1)*365)+((y-1)/4)-((y-1)/100)+((y)/400)+1)%7;
    return d;
}


int main()
{
    int day,month,year;
    //number of day in months
    int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    cout<<"==== Find First day of any year and month ===="<<endl;
    cout<<"\nEnter Month ";
    cin>>month;
    cout<<"Enter Year ";
    cin>>year;
    cout<<"First Day of Month "<<month<<"th and Year "<<year<<" is ";

    if((year%4 ==0 && year%100 != 0) || year%400 ==0 )
    {
        month_days[1] = 29;
    }
    day = first_day_year(year);

    //finding day of month

    for(int i=0;i<month-1;i++)
    {
        for(int j=1;j<=month_days[i];j++)
        {
            if(++day >6)
                day =0;
        }
    }


    switch(day)
    {
    case 0:
        printf("Sunday\n");
        break;
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    default:
        printf("invalid \n");

    }
    system("pause");

}
