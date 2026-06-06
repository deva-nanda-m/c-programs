#include<stdio.h>
#include<ctype.h>
char st[25],infix[25];
int top=-1;
void push(char item)
{
    if(top==24)
    {
        printf("STack full\n");
    }
    else
    {
        top++;
        st[top]=item;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack empty\n");
        return -1;
    }
    else
    {
        return st[top--];
    }
}
int priority(char ch)
{
    if(ch=='(')
        return 1;
    else if(ch=='+'||ch=='-')
        return 2;
    else if(ch=='*'||ch=='/')
        return 3;
    else if(ch=='^')
        return 4;
}
void main()
{
    printf("Enter infix expression\n");
    scanf("%s",infix);
    int i=0;
    char ch;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {
            printf("%c",infix[i]);
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while((ch=pop())!='(')
            {
                printf("%c",ch);
            }                                                                                                                                               
        }
        else
        {
            while(priority(infix[i])<=priority(st[top]))
            {
                if(st[top]=='^'&&infix[i]=='^')
                {
                    break;
                }
                printf("%c",pop());
            }
            push(infix[i]);
        }
        i++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
}