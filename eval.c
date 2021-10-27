#include<stdio.h>
#include<ctype.h>
# define size 100
int top = -1;
int stack[100];
void push(int ele)
{
    stack[++top] = ele;
}
int pop()
{
    return stack[top--];
}
int main(int argc,char **argv)
{
    char exp[100];
    int n1,n2,n3,num;
    printf("ENTER EXPRESSION\n");
    scanf("%s",exp);
    int i = 0;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            num = exp[i] - 48;
            push(num);
        }
        else
        {
            n2 = pop();
            n1 = pop();
            switch(exp[i])
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n1 - n2;
                break;
            case '/':
                n3 = n1 / n2;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            }
            push(n3);
        }
        i++;
    }
    printf("THE RESULT OF EXPRESSION =%d\n",pop());
    return 0;
}
