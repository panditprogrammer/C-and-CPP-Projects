//calculate age
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int day, month, year, cday, cmonth, cyear;
    int Rday, Rmonth, Ryear;
    system("cls");
    printf("Enter Date of Birth seperated by '/' ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("Enter current date ");
    scanf("%d/%d/%d", &cday, &cmonth, &cyear);
    if (day > 31 || cday > 31 || day < 1 || cday < 1 || month > 12 || cmonth > 12 || year > cyear)
    {
        printf("Please Enter a valid Date \n");
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
            printf("Your are %d year %d months %d days old.\n", Ryear, Rmonth, Rday);
        }
        else
        {
            printf("invalid date !\n");
        }
    }

    system("pause");
    return 0;
}
