#include<stdio.h>
#include<stdlib.h>

struct node
{
 int coff;
 int pow;
 struct node *next;
 struct node *prev;
};
struct node *head=NULL,*head1=NULL,*head2=NULL,*last1=NULL,*last2=NULL;
struct node *list=NULL;
struct node *current=NULL;
void createlist1()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Coff and power\n");
	scanf("%d%d",&newnode->coff,&newnode->pow);

	newnode->next=NULL;
    newnode->prev=NULL;
	if(head1==NULL)
	{
		head1=newnode;
		last1=newnode;
	}
	else
	{
		 last1->next=newnode;
         newnode->prev=last1;
		 last1=newnode;
	}

}
void createlist2()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the coff and power\n");
	scanf("%d%d",&newnode->coff,&newnode->pow);
	newnode->next=NULL;
    newnode->prev=NULL;
	if(head2==NULL)
	{
		head2=newnode;
		last2=newnode;
	}
	else
	{
		 last2->next=newnode;
         newnode->prev=last2;
         last2=newnode;
	}
}
void display()
{
	struct node *temp;
	temp=list;
	while(temp!=NULL)
	{
		printf("%s%dx^%d",(temp->coff>0?"+":""),temp->coff,temp->pow);
		temp=temp->next;
	}
}

void poly()
{
	struct node *temp1,*temp2;
	struct node *newnode;
	int sum=0;
	temp1 = head1;
	temp2 = head2;

	while (temp1!=NULL && temp2!=NULL)
	{
		newnode = (struct node *) malloc (sizeof(struct node));
		newnode->next = NULL;
        newnode->prev=NULL;
		if (list == NULL)
		{
			list = newnode;
			current = newnode;
		}
		else
		{
			current->next = newnode;
            newnode->prev=current;
			current = newnode;
		}

		if (temp1->pow==temp2->pow)
		{
				sum=temp1->coff+temp2->coff;
				newnode->coff=sum;
				newnode->pow=temp1->pow;
				temp1 = temp1->next;
				temp2=temp2->next;
		}
		else if(temp1->pow >temp2->pow)
		{
			 newnode->coff=temp1->coff;
			 newnode->pow=temp1->pow;
			 temp1=temp1->next;
		}
		else
		{
			newnode->coff=temp2->coff;
			newnode->pow=temp2->pow;
			temp2=temp2->next;
		}
	}
	if (temp1 == NULL)
	{
		while (temp2!=NULL)
		{
			newnode = (struct node *) malloc (sizeof(struct node));
			newnode->coff = temp2->coff;
			newnode->pow =temp2->pow;
			newnode->next = NULL;
            newnode->prev=NULL;
			if(list==NULL)
				list=newnode;
			else
			{
				current->next = newnode;
                newnode->prev=current;
			  current = newnode;
			}
			temp2=temp2->next;
		}
	}
	else
	{
		while (temp1!=NULL)
		{
			newnode = (struct node *) malloc (sizeof(struct node));
			newnode->coff = temp1->coff;
			newnode->pow =temp1->pow;

			newnode->next = NULL;
            newnode->prev=NULL;

			if(list==NULL)
				 list=newnode;
			else
			{
				current->next = newnode;
                newnode->prev=current;
			current = newnode;
			}
			temp1=temp1->next;
		}
	}
}

int main()
{
	int choice;
	
	while(1)
	{
		printf("1.create Polynomial expression1 \n");
		printf("2.create Polynomial expression 2 \n");
		printf("3.Polynomial Addition\n");
		printf("4.display\n");
		printf("5. exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : createlist1(); break;
			case 2: createlist2();break;
			case 3: poly();break;
			case 4:display(); break;
			case 5 : exit(0);
		}
		}
}