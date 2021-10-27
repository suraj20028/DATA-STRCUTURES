#include<stdio.h>
#include<limits.h>
# define size 3
int top = -1;
void push(int [],int);
int pop(int []);
void display(int []);
int main(int argc,char **argv)
{
    int stack[size];
    int choice, element;
    char ch;
    do
    {
        printf("--MENU--\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3 display\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("ENTER ELEMENT TO BE PUSHED\n");
            scanf("%d",&element);
            push(stack,element);
            break;
        case 2:
            element = pop(stack);
            if(element == INT_MIN)
            {
                printf("STACK UNDERFLOW\n");
            }
            else
            {
                printf("POPPED ELEMENT = %d\n",element);
            }
            break;
        case 3:
            display(stack);
            break;
        default:
            printf("ENTER VALID CHOICE\n");
        }
        printf("ENTER Y OR y TO CONTINUE\n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y' || ch=='Y');
    return 0;
}
void push(int stack[],int ele)
{
    if(top==size-1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    else
    {
        top++;
        stack[top] = ele;
    }
}
int pop(int stack[])
{
    int popele;
    if(top==-1)
    {
        return INT_MIN;
    }
    else
    {
        popele = stack[top];
        top--;
        return(popele);
    }
}
void display(int stack[])
{
    printf("ELEMENTS ARE =\n");
    for(int i = top;i >= 0; i--)
    {
        printf("%d\t",stack[i]);
    }
}
