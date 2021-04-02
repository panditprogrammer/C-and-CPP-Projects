//creating clock
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    int hour,min,sec,delay = 1000;
    printf("Enter Time Hour,min,sec seperated by comma ");
    scanf("%d,%d,%d",&hour,&min,&sec);
    if(hour>12 || min>60 || sec>60)
    {
        printf("Invalid Time ");
        exit(0);
    }
    else
    {
        while(1)
        {
            sec++;
            if(sec>59)
            {
                min++;
                sec = 0;
            }
            if(min>59)
            {
                hour++;
                min = 0;
            }
            if(hour>12)
            {
                hour=1;
            }
            printf("\n Time ");
            printf(" %02d:%02d:%02d",hour,min,sec);  //printing time desire format
            Sleep(delay);  //delay for second
            system("cls"); //clear the screen
            system("color 4a"); //changing color of console

        }
    }
    return 0;
}
