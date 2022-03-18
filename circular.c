#include <stdio.h>
#include <stdlib.h>
void insertAtBeg();
void insertAtEnd();
void insertAtAfter();
void deleteBeginning();
void deleteEnd();
void deleteSpecific();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int main(int argc, char **argv)
{
    int choice;
    char ch='y';
    do
    {
    printf("\n1. InsertAtEnd \n2. Display  \n3. InsertAtBeg \n4. InsertAtAfter \n5. DeleteBeginning \n6. DeleteEnd \n7. DeleteSpecific \n8. Exit\n ");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insertAtEnd(); break;
        case 2: display();break;
        case 3: insertAtBeg(); break;
        case 4: insertAtAfter(); break;
        case 5: deleteBeginning(); break;
        case 6: deleteEnd();break;
        case 7: deleteSpecific();break;
        case 8: ch='n'; break;
    }
	//printf("\nDo you want to continue (y||Y):");
    //fflush(stdin);
    //scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}

void insertAtEnd()
{
   struct node *newnode,*temp;
    int item;
    newnode =(struct node *) malloc (sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=NULL;
    if (head==NULL)
     { 
        head=newnode;
        newnode->next=newnode;
       
      printf("Node created\n");
     }
     else 
    {
    temp=head;
       while(temp->next!=head)
       {
                temp=temp->next;
        }
      temp->next=newnode;
      newnode->next=head;
       printf("Node created\n");
   }  
}
void insertAtBeg()
{
    struct node *newnode,*temp;
    int item;
    newnode =(struct node *) malloc (sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=NULL;
    if (head==NULL)
     { 
        head=newnode;
        newnode->next=newnode;
       
      printf("Node created\n");
     }
     else 
    {
    temp=head;
       while(temp->next!=head)
       {
                temp=temp->next;
        }
      newnode->next=head;
      head=newnode;
      temp->next=head;
       printf("Node created\n");
    }
}
void insertAtAfter()
{
    struct node *newnode,*temp;
    int item,ele, flag=0;
    if (head==NULL)
     { 
        printf("Empty list\n");
     }
     else 
    {
         newnode =(struct node *) malloc (sizeof(struct node));
        printf("Enter the data to be inserted: ");
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=NULL;
        printf("Enter the element after which insertion to be done\n");
        scanf("%d",&ele);

        temp=head;
       while(temp->next!=head)
       {
           if(temp->data==ele)
           {
               newnode->next=temp->next;
               temp->next=newnode;
               flag=1;break;
               
           }
          
        temp=temp->next;
      }
      if((temp->data==ele) && (flag==0))
      {
       newnode->next=temp->next;
       temp->next=newnode;
       flag=1;
      }
      
      if (flag == 0)
      {
          printf("\n Element not found\n");
      }
    }
    
}

void deleteBeginning()
{
    struct node *temp1,*temp2;
    temp1=temp2=head;
    if(head==NULL)
    {
        printf("Empty list\n"); return;
        
    }
    else
    { 
        if(temp1->next==head)
        {
            head=NULL;return;
        }
            
        else
        {
            
           while (temp1->next!=head)
            temp1=temp1->next;
            
            head=temp2->next;
            temp1->next=head;
        }
    }
        
    
}
void deleteEnd()
{
   struct node *temp1,*temp2;
    temp1=head;
    if(head==NULL)
    {
        printf("Empty list\n"); return;
        
    }
    else
    { 
        if(temp1->next==head)
        {
            head=NULL;
            return;
        }
        else
        {
           
           while (temp1->next!=head)
           {
               temp2=temp1;
               temp1=temp1->next;
            
           }
        }
        temp2->next =head;free(temp1);
    }
        
 
}
void deleteSpecific()
{
    struct node *temp1,*temp2;
    int ele,flag=0;
    if(head==NULL)
    {
        printf("Empty list\n"); return;
    }
    
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    
    temp1=head;
    if(temp1->data==ele)
    {
        if(temp1->next==head)
        {
            head=NULL; free(temp1);
        }
        else
        {
            temp2=head;
            
           while (temp1->next!=head)
            temp1=temp1->next;
            
            head=temp2->next;
            temp1->next=head;
        }
    }
    else
    {
        while(temp1->next!=head)
        {
            temp2=temp1;
            temp1=temp1->next;
            if(temp1->data==ele)
            {
                temp2->next=temp1->next;
                free(temp1);
                flag=1;break;
                
            }
        }
            
        if(flag==0)
        {
            printf("Element not found\n"); return;
        }
    }
        
    
}

void display()
{
    struct node *ptr=NULL;
    ptr=head;
     
    if(ptr==NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        do
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
        
                     
    }
    
    
}