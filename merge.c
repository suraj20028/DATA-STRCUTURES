#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
void create(struct node **);
void merge(struct node *, struct node *);
void display(struct node *);
struct node *third=NULL;
int main(int argc, char **argv)
{
    struct node *head1=NULL, *head2=NULL;
    
    printf("Create two list\n");
    printf("Creating List one\n");
    create(&head1);
    printf("Creating List two\n");
    create(&head2);
    printf("\nList one data:\n");
    display(head1);
    printf("\nList two data:\n");
    display(head2);
    printf("\nMerged List\n");
    merge(head1,head2);
    display(third);
}


void create(struct node **hptr)
{
   struct node *newnode,*temp;
    int item;
   char  choice;
    
    do
    {
        newnode =(struct node *) malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=NULL;
        printf("Do u want add element in the list:\n");
        fflush(stdin);
        scanf("%c", &choice);
        
       
        
        if (*hptr==NULL)
         { 
           
          *hptr=newnode; 
         
         }
         else 
        {
            temp=*hptr;
            while(temp->next!=NULL)
            {
                    temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=NULL;
        }  
    }while (choice=='y' || choice =='Y');
}


void merge (struct node *temp1, struct node *temp2)
{
    struct node *newnode, *current;
    
    //temp1=head1;
    //temp2=head2;
    
    while(temp1!=NULL && temp2!=NULL)
    {
        newnode =(struct node *) malloc (sizeof(struct node));
        newnode->next =NULL;
        
        if(temp1->data < temp2->data)
        {
            newnode->data = temp1->data;
            temp1=temp1->next;
        }
        else
        {
             newnode->data =temp2->data;
            temp2 =temp2->next;
        }
        
        if(third ==NULL)
        {
            third=newnode;
            current=newnode;
       }
       else
       {
           current->next=newnode;
           current=newnode;
       }
    }

    if(temp1==NULL)
    {
        while(temp2!=NULL)
        {
            newnode=(struct node *) malloc(sizeof(struct node));
            newnode->data=temp2->data;
            newnode->next=NULL;
        if(third==NULL)
        {
            third=newnode;
            current =newnode;
        }
        else
        {
            current->next =newnode;
            current=newnode;
        }
        temp2=temp2->next;
      }
  }

  else
  {
    while(temp1!=NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=temp1->data;
        newnode->next=NULL;
        if(third==NULL)
        {
            third=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
        temp1=temp1->next;
    }
    
    
}

}
void display(struct node *ptr)
{
    
       
    if(ptr==NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        while(ptr!=NULL)
       {
        printf("%d ",ptr->data);
        ptr=ptr->next;
       }
    }
    
}
