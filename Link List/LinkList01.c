//link list
//insertion in link list
#include <stdio.h>
#include <stdlib.h>

//creating structure for node
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

    }
}

void main()
{
    //main function

}
