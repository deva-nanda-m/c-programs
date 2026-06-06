#include<stdio.h>
#include<string.h>
int top=-1;
char st[20];
void pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%c",st[top]);
        top--;
    }
}
void push(char item)
{
    if(top==19)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        st[top]=item;
    }
}
void main()
{
    char str[20];
    printf("Enter a string\n");
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    for(int i=0;i<strlen(str);i++)
    {
        pop();
    }
}