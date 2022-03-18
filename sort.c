#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}n;
n *head = NULL;
void insert()
{
    n *newnode,*temp = NULL;
    newnode = (n *)malloc(sizeof(n));
    printf("ENTER DATA = ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display()
{
    n *ptr = head;
    if(head == NULL)
    {
        printf("\nLIST EMPTY");
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
void sort()
{
    n *cur,*t = head;
    int temp;
    while(t!=NULL)
    {
        cur = t->next;
        while(cur!=NULL)
        {
            if(t->data > cur->data)
            {
                temp = t->data;
                t->data = cur->data;
                cur->data = temp;
            }
            cur = cur->next;
        }
        t = t->next;
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf(" 1.INSERT\n 2.SORT\n 3.DISPLAY\n 4.EXIT\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            sort();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}