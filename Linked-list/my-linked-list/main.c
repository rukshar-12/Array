/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL; // Global ADT Pointer

void create()
{
    int n, i;
    struct node *newnode, *temp;
    printf("\nEnter the number of nodes that you wish to create: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter data of node %d: ",i);
        newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("\nMemory Full");
            return;
        }
       scanf("%d",&newnode->data);
       newnode->next = NULL;
       if(head==NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void traverse()
{
    struct node *temp2;
    if(head == NULL)
        printf("\nLinked list is empty");
    else
    {
        printf("\nLinked List Contents are as follows:\n");

        temp2 = head;
        while(temp2!=NULL)
        {
            printf("%d",temp2->data);
            printf("\n");
            temp2 = temp2->next;
        }
    }
}

void count()
{
    int count=0;
    struct node *temp;
    temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\nThe total number of nodes in the Linked list are %d.",count);
}

void insertafter()
{
     int pos;
     int count=0;
    struct node *temp;
    temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    
    int i=1;
    struct node *newnode, *temp1;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the position\n");
    scanf("%d",&pos);
   
    if(pos>count)
    {
        printf("\nInvalid position");
        return;
    }
    else{
    temp1 = head;
    // search for node
    while(i<pos){
        temp1=temp1->next;
        i++;
    }
    printf("Enter the data");
    scanf("%d",&newnode->data);
    newnode->next=temp1->next;
    temp1->next=newnode;
    }
  }


void insertbefore(int x, int k)
{
    struct node *p, *pnode, *follow;
    pnode = (struct node*)malloc(sizeof(struct node));
    if(pnode==NULL)
    {
        printf("\nMemory Full");
        //return;
    }
    p = head;
    follow = NULL;
    while(p->data!=k && p!=NULL)
    {
        follow = p;
        p = p->next;
         if(p==NULL)
    {
        printf("\nRequired node not found\n");
    }
    }
   
    if(p==head) // we want to insert before 1st node of the LL
    {
        pnode->data = x;
        pnode->next = p;
        head = pnode;
    }
    else // we want to insert in middle
    {
        pnode->data = x;
        pnode->next = p;
        follow->next = pnode;
    }
}

void delete_node()
{
    int k;
    struct node *p, *follow;
    printf("\nEnter the node to be deleted: ");
    scanf("%d",&k);
    p = head;
    follow = NULL;
    while(p->data!=k && p!=NULL)
    {
        follow = p;
        p = p->next;
    }
    if(p->next==NULL)
        printf("\nRequired node not found");
    else if(p==head)
        head = head->next;
    else
        follow->next = p->next;
    free(p);
    
}
void reverse()
{
    struct node *temp,*ahead,*follow;
    temp=head;
    ahead=follow=NULL;
    while(temp!=NULL){
        ahead=temp->next;
        temp->next=follow;
        follow=temp;
        temp=ahead;
    }
    head=follow;
}

void main()
{
    int ch, x, k;
    do
    {
        printf("\nMENU\n1. Create\n2. Display\n3. Count\n4. Delete\n5. Insert After\n6. Insert Before\n7.Reverse\n8. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: traverse();
                    break;
            case 3: count();
                    break;
            case 4: delete_node();
                    break;
            case 5:insertafter();
                    break;
            case 6: printf("\nEnter the value to be inserted: ");
                    scanf("%d",&x);
                    printf("\nEnter the number before which %d is to be inserted: ",x);
                    scanf("%d",&k);
                    insertbefore(x,k);
                    break;
            case 7:reverse();
                    break;
            default: printf("\nExit");
        }
    }while(ch!=8);
}




