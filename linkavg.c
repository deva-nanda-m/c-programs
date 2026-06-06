#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*link;
}node;
int item;
node*head=NULL,*ptr,*prev,*temp;
void insertnode()
{
    node*new=(node*)malloc(sizeof(node));
    new->data=item;
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
        ptr=head;
    }
    else
    {
        ptr->link=new;
        ptr=ptr->link;
    }
}
void display()
{
    ptr=head;
    if(head==NULL)
    {
        printf("list empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void deletenode(int n)
{
    //mid in terms of index
    int mid=n/2;
    temp=head;
    for(int i=0;i<mid;i++)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=temp->link;
    free(temp);
}
void main()
{
    int n;
    printf("enter size of array\n");
    scanf("%d",&n);
    if(n%2!=0)
    {
        printf("Enter elements\n");
        for(int i=0;i<n;i++)
        {
            printf("Enter %d element\n",i+1);
            scanf("%d",&item);
            insertnode();
        }
        printf("entered array\n");
        display();
        printf("new array\n");
        deletenode(n);
        display();
    }
    else
    {
        printf("Enter an odd no of elements\n");
    }
}