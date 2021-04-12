//currency converter
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float input, rate, result;
    int select;
    while (1)
    {
        system("cls");
        printf("\tCurrency Converter\n1. Dollor \n2. Euro \n3. Riyal \n4. Dinar \n5. Quit");
        printf("\n\nSelect ");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            printf("\n Enter Rupees ");
            scanf("%f", &input);
            result = input / 73.32;
            printf("%.2f Equal %.2f in Dollors\n", input, result);
            system("pause");
            break;
        case 2:
            printf("\n Enter Rupees ");
            scanf("%f", &input);
            result = input / 86.36;
            printf("%.2f Equal %.2f in Euros\n", input, result);
            system("pause");
            break;
        case 3:
            printf("\n Enter Rupees ");
            scanf("%f", &input);
            result = input / 0.0017;
            printf("%.2f Equal %.2f in Riyals \n", input, result);
            system("pause");
            break;
        case 4:
            printf("\n Enter Rupees ");
            scanf("%f", &input);
            result = input / 0.05;
            printf("%.2f Equal %.2f in Dianrs\n", input, result);
            system("pause");
            break;
        case 5:

            exit(0);
        default:
            printf("Invalid input!\n");
            system("pause");
            break;
        }
    }

    system("pause");
    return 0;
}
