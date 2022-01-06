// WAP to implement Singly Linked List using Global ADT pointer
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *pfirst = NULL; // Global ADT Pointer

void create()
{
    int n, i;
    struct node *pnode, *p;
    printf("\nEnter the number of nodes that you wish to create: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter data of node %d: ",i);
        pnode = (struct node*)malloc(sizeof(struct node));
        if(pnode == NULL)
        {
            printf("\nMemory Full");
            return;
        }
       scanf("%d",&pnode->data);
       pnode->next = NULL;
       if(pfirst==NULL)
            pfirst = p = pnode;
        else
        {
            p->next = pnode;
            p = pnode;
        }
    }
}

void traverse()
{
    struct node *p;
    if(pfirst == NULL)
        printf("\nLinked list is empty");
    else
    {
        printf("\nLinked List Contents are as follows:\n");
        p = pfirst;
        while(p!=NULL)
        {
            printf("%4d",p->data);
            p = p->next;
        }
    }
}

void count()
{
    int count=0;
    struct node *p;
    p = pfirst;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    printf("\nThe total number of nodes in the Linked list are %d.",count);
}

void insertafter(int x, int k)
{
    struct node *pnode, *p;
    pnode = (struct node*)malloc(sizeof(struct node));
    if(pnode==NULL)
    {
        printf("\nMemory Full");
        return;
    }
    p = pfirst;
    // search for node
    while(p->data!=k && p!=NULL)
    {
        p = p->next;
        if(p==NULL)
    {
        printf("\nRequired node not found");
    }
    }
    
    
        pnode->data = x;
        pnode->next = p->next;
        p->next = pnode;
    
}

void insertbefore(int x, int k)
{
    struct node *p, *pnode, *follow;
    pnode = (struct node*)malloc(sizeof(struct node));
    if(pnode==NULL)
    {
        printf("\nMemory Full");
        return;
    }
    p = pfirst;
    follow = NULL;
    while(p->data!=k && p!=NULL)
    {
        follow = p;
        p = p->next;
    }
    if(p->next==NULL)
        printf("\nRequired node not found");
    else if(p==pfirst) // we want to insert before 1st node of the LL
    {
        pnode->data = x;
        pnode->next = p;
        pfirst = pnode;
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
    p = pfirst;
    follow = NULL;
    while(p->data!=k && p!=NULL)
    {
        follow = p;
        p = p->next;
    }
    if(p->next==NULL)
        printf("\nRequired node not found");
    else if(p==pfirst)
        pfirst = pfirst->next;
    else
        follow->next = p->next;
    free(p);
    
}

void main()
{
    int ch, x, k;
    do
    {
        printf("\nMENU\n1. Create\n2. Display\n3. Count\n4. Delete\n5. Insert After\n6. Insert Before\n7. Exit\nEnter your choice: ");
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
            case 5: printf("\nEnter the value to be inserted: ");
                    scanf("%d",&x);
                    printf("\nEnter the number after which %d is to be inserted: ",x);
                    scanf("%d",&k);
                    insertafter(x,k);
                    break;
            case 6: printf("\nEnter the value to be inserted: ");
                    scanf("%d",&x);
                    printf("\nEnter the number before which %d is to be inserted: ",x);
                    scanf("%d",&k);
                    insertbefore(x,k);
                    break;
            default: printf("\nExit");
        }
    }while(ch!=7);
}




