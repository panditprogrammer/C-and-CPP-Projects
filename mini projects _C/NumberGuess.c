#include <stdio.h>
#include <time.h>

void main()
{
    int number,n,c=1,lower,upper;

    printf("\n ======== Number Guessing Challenge Game ========\n\n");

    printf("\n\tInstruction : \n\t1. Enter a range of number to play\n\t2. e.g. lower = 10 ,uppper = 100");
    printf("\n\t3. System will choose a number that you have to Guess it.\n");

    printf("\n\n\tEnter lower and upper limit (10,100) : ");
    scanf("%d,%d",&lower,&upper);

    srand(time(0));
    number = (rand()%(upper-lower+1))+lower;

    while(1)
    {
        system("cls");
        printf("\n ======== Number Guessing Challenge Game ========\n\n");

        printf("\n\tInstruction : \n\t1. Enter a range of number to play\n\t2. e.g. lower = 10 ,uppper = 100");
        printf("\n\t3. System will choose a number that you have to Guess it.\n");

        printf("\n\tGuess A Number : ");
        scanf("%d",&n);

        if(n==number)
        {
            printf("\n\tCongratulations! Your Guess is correct in %d turns.\n\t",c);
            system("pause");
            break;
        }
        else if(n<number)
        {
            printf("\n\tYour guess is smaller.\n\t");
            c++;
        }
        else
        {
            printf("\n\tYour guess is greater\n\t");
            c++;
        }

        system("pause");

    }
        printf("Thanks for Playing with us...\n\t ");
}
