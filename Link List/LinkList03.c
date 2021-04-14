//Link list  how to reverse a link list
#include <stdio.h>
#include <stdlib.h>
//create a structure for node
struct node
{
    int data;
    struct node *link;

};

//creating  start pointer of link list
struct node *start = NULL;

//create a function for creating variable dynamically
struct node* createNode()
{
    struct node *n; //variable of pointer

    n = (struct node*)malloc(sizeof(struct node)); // malloc return address of created block  we have type casting into struct type
    return(n); //return address of memory block

}

//create a function for inserting data
void insertNode()
{
    struct node *temp,*t;
    temp = createNode();
    printf("Enter a number ");
    scanf("%d",&temp->data);
    temp->link = NULL;

    //checking start pointer is empty or not
    if(start == NULL)
    {
        start = temp;
    }
    //insert node if start has a least one node
    else
    {
        t = start;
        while(t->link !=NULL)
        {
            t = t->link;
        }
        t->link= temp;
        printf("Node Element inserted at last!\n");
    }
}

//create a function for deleting node
void deleteNode()
{
    struct node *remove;
    //checking the link list empty or not
    if(start == NULL)
        {
            printf("List is empty\n");
        }
    else
    {
        remove = start;  //assigning value of start pointer into temperary remove pointer
        start = start->link; //assigning value of first node in start pointer
        free(remove);  //releasing memory of remove pointer
        printf("First Node element deleted !\n");
    }

}

//creating function for showing link list
void showList()
{
    struct node *Temp,*t;
    if(start == NULL)
        printf("Link list is Empty\n");
    else
    {
        printf("List is \n");
        t = start;

        while(t!=NULL)
        {
            printf(" %d ",t->data);
            t = t->link;
        }

    }
}
//reversing link list
struct node* reverseList()
{
    //create a node pointer
    struct node *temp1= NULL;
    struct node *temp2= NULL;

    while(start != NULL)
    {
        temp2 = start->link;
        start->link = temp1;
        temp1 = start;
        start = temp2;
    }
    return temp1;

}


int menu()
{
    int m;
    printf("\t Link list insertion deletion traversing and reversing \n");
    printf("1. Add value to the list\n");
    printf("2. Delete first value\n");
    printf("3. Show List\n");
    printf("4. Reverse List\n");
    printf("5. Exit\n");
    printf("\nEnter ");
    scanf("%d",&m);
    return m;
}

void main()
{
    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
            insertNode();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            showList();
            break;
        case 4:
            start = reverseList();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid input!\n");

        }
        printf("\n");
        system("pause");
    }

}



