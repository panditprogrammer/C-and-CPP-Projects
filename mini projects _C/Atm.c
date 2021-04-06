//ATM operation program
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float balance, debit, credit, amount;
    int n;
    while (1)
    {
        system("cls");
        printf("\t>>>>>>>>>ATM<<<<<<<<\n\n");
        printf("1. Open Account \n2. Credit \n3. Debit \n4. Check balance\n5. Exit\n\nEnter choice ");

        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter initial Amount ");
            scanf("%f", &balance);
            printf("Congratulations! Your Account has been opened successfully.\n");
            system("pause");
            break;
        case 2:
            printf("Enter Amount ");
            scanf("%f", &amount);
            if(amount>0)
            {
                balance = balance + amount;
                printf("You have Credited  Rs %.2f \n",amount);
            }
            else
            {
                printf("Please Enter Valid amount !\n");
            }
            system("pause");
            break;
        case 3:
            printf("Enter Amount ");
            scanf("%f", &amount);
            if (balance >= amount)
            {
                balance = balance - amount;
                printf("You have Debited Rs %.2f \n", amount);
            }
            else
            {
                printf("Insufficient Balance !\n");
            }
            system("pause");
            break;
        case 4:
            printf("Your current balance is Rs %.2f \n",balance);
            system("pause");
            break;
        case 5:
            printf("Thanks for visiting us.\n");
            system("pause");
            exit(0);
        default:
            printf("Invalid input found!\n");
            system("pause");
            break;
        }
    }

    system("pause");
    return 0;
}
