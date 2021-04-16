//circular link list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;

};

//declaration of functions
void display(struct node *last);
struct node* addAtBegin(struct node *last,int value);
struct node* createList(struct node *last);
struct node* addToEmptyList(struct node *last,int value);
struct node* addToEnd(struct node *last,int value);
struct node* addAfter(struct node *last,int value,int d);
//struct node* Delete(struct *last,int value);

//display list
void dispaly(struct node *last)
{
    struct node *temp;
    if(last == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp = last->link;
        do
        {
            printf(" %d",temp->data);
            temp = temp->link;
        }
        while(temp !=last->link);
    }
}

//add to begining element
struct node* addAtBegin(struct node *last,int value)
{
    struct node *n;
    if(last != NULL)
    {
        n = malloc(sizeof(struct node));
        n->data= value;
        n->link = last->link;
        last->link = n;
        return last;

    }
    else
    {
        printf("List is empty");
        return NULL;
    }

}


//adding first element in empty list
struct node* addToEmptyList(struct node *last,int value)
{
    struct node *n;

    n = malloc(sizeof(struct node));
    n->data = value;
    last = n;
    last->link = last;
    return last;

}

//adding element at the end of list
struct node* addAtEnd(struct node *last,int value)
{
    struct node *New;
    if(last != NULL)
    {
        New = malloc(sizeof(struct node));
        New->data = value;
        New->link = last->link;
        last->link = New;
        last = New;
        return last;

    }
    else
    {
        printf("List is Empty");
        return NULL;
    }

}


//adding element after given value
struct node* addAfter(struct node *last,int value, int d)
{
    struct node *temp,*nnew;

    if(last != NULL)
    {
        temp = last->link;

        do
        {
            if(temp->data == d)
            {
                nnew = malloc(sizeof(struct node));
                nnew->data = value;
                nnew->link = temp->link;
                temp->link = nnew;
                if(temp==last)
                    last = nnew;
                return last;
            }
            temp = temp->link;
        }while(temp != last->link);
        printf(" %d is not available in list",d);
    }
    else
    {
        printf("List is Empty");
        return NULL;
    }

}


//deleting element from list
struct node* Delete(struct node *last,int value)
{
    struct node *temp,*p;
    if(last == NULL)
    {
        printf("List is empty");
        return last;
    }

    if(last == last->link && last->data== value)
    {
        temp = last;
        last = NULL;
        free(temp); //realloc(t,0);
        return last;
    }

    if(last->link->data == value)
    {
        temp = last->link;
        last->link = temp->link;
        free(temp);
        return last;
    }

    p = last->link;
    while(p->link != last)
    {
        if(p->link->data = value)
        {
            temp = p->link;
            p->link = temp->link;
            free(temp); //realloc(temp,0);
            return last;
        }
        p = p->link;
    }

    if(last->data == value)
    {
        temp = last;
        p->link = last->link;
        last = p;
        free(temp);
        return last;
    }
    printf(" %d is not in list");
    return last;
}


//create list
struct node* createList(struct node *last)
{
    int n,value;
    printf("Number of Elements ");
    fflush(stdin);
    scanf("%d",&n);
    printf("Enter Element for the list ");
    scanf("%d",&value);
    last = addToEmptyList(last,value);
    for(int i=2;i<=n;i++)
    {
        printf("Enter Element for the list ");
        fflush(stdin);
        scanf("%d",&value);
        last = addAtEnd(last,value);
    }
    return last;

}



//menu

int menu()
{
    int select;
    printf("\t Circular link list\n");
    printf(" 1. Create List\n");
    printf(" 2. Display List\n");
    printf(" 3. Create new list\n");
    printf(" 4. Add At beginning\n");
    printf(" 5. Add At End\n");
    printf(" 6. Add After an Element\n");
    printf(" 7. Delete Element\n");
    printf(" 8. Quit\n");
    printf(" \nEnter Your choice");
    scanf("%d",&select);
    return select;
}
void main()
{
    int value,pos;
    struct node *last =NULL;

    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
            last = createList(last);
            break;
        case 2:
            dispaly(last);
            break;
        case 3:
            printf("Enter an Element for List ");
            scanf("%d",&value);
            last = addToEmptyList(last,value);
            break;
        case 4:
            printf("Enter an Element for list ");
            scanf("%d",&value);
            last = addAtBegin(last,value);
            break;
        case 5:
            printf("Enter an Element for List ");
            scanf("%d",&value);
            last = addAtEnd(last,value);
            break;
        case 6:
            printf("Enter an Element for List ");
            scanf("%d",&value);
            printf("Element inserted after ");
            scanf("%d",&pos);
            last = addAfter(last,value,pos);
            break;
        case 7:
            printf("Enter Element to Delete ");
            scanf("%d",&value);
            last = Delete(last,value);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid Choice");
        }

        system("pause");
    }


}
