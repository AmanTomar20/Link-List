#include <stdio.h>
#include <stdlib.h>

/* Link list struct Node */
struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node *temp;
    temp=(struct Node*) malloc(sizeof(struct Node));
    temp->data=new_data;
    temp->next=NULL;
    if(*head_ref == NULL)
    {
        *head_ref=temp;
    }
    else
    {
        temp->next=*head_ref;
        *head_ref=temp;
    }
}

void pairWiseSwap(struct Node *head)
{
    struct Node *temp = head;

    /* Traverse further only if there are at-least two nodes left */
    while (temp != NULL && temp->next != NULL)
    {
        /* Swap data of node with its next node's data */
        swap(&temp->data, &temp->next->data);

        /* Move temp by 2 for the next pair */
        temp = temp->next->next;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printList( struct Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{

    struct Node *start = NULL;

    int a, x, i;
    scanf("%d", &a);

    for (i = 0; i < a; i++)
    {
        scanf("%d",&x);
        push(&start, x);
    }



    pairWiseSwap(start);

    printList(start);
    return 0;
}
