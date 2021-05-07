//calculate age
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    int day, month, year, cday, cmonth, cyear;
    int Rday, Rmonth, Ryear;
    //system time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    system("cls");
    printf("\n\t ========== AGE CALCULATOR ==========\n\n");
    printf("\n\tEnter Date of Birth seperated by '/' : ");
    scanf("%d/%d/%d", &day, &month, &year);

    cday = tm.tm_mday ;
    cmonth = tm.tm_mon+1;
    cyear = tm.tm_year+1900;
    printf("\n\tnow: %d /%02d /%02d \n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    if (day > 31 || cday > 31 || day < 1 || cday < 1 || month > 12 || cmonth > 12 || year > cyear)
    {
        printf("\n\tPlease Enter a valid Date \n");
    }
    else
    {
        if (cyear >= year)
        {
            if (cday >= day)
            {
                Rday = cday - day;
            }
            else
            {
                cday = cday + 30;
                cmonth = cmonth - 1;
                Rday = cday - day;
            }

            if (cmonth >= month)
            {
                Rmonth = cmonth - month;
            }
            else
            {
                cmonth = cmonth + 12;
                cyear = cyear - 1;
                Rmonth = cmonth - month;
            }

            Ryear = cyear - year;
            printf("\n\tYour are %d year %d months %d days old.\n", Ryear, Rmonth, Rday);
        }
        else
        {
            printf("\n\tinvalid date !\n\t");
        }
    }

    system("pause");
    return 0;
}
