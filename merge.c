#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head=NULL,*rear=NULL,*temp;
void enqueue()
{
    int item;
    printf("Enter element\n");
    scanf("%d",&item);
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->next=NULL;
    new->prev=NULL;
    if(head==NULL)
    {
        head=new;
        new->next=new;
        new->prev=new;
        rear=new;
    }
    else
    {
        rear->next=new;
        new->prev=rear;
        new->next=head;
        head->prev=new;
        rear=new;
    }
}
void dequeue()
{
    if(head==NULL)
    {
        printf("Queue is empty\n");
    }
    else if(head==rear)
    {
        free(head);
        head=rear=NULL;
    }
    else
    {
        temp=head;
        printf("deleted element is %d",head->data);
        head=head->next;
        head->prev=rear;
        rear->next=head;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("queue empty\n");
    }
    else
    {
        temp=head;
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        } while (temp!=head);
        printf("\n");
    }
    
}
void main()
{
    int ch;
    do
    {
        printf("Enter choice\n1:enqueue\n2:dequeue\n3:display\n4:exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        
        case 3:
            display();
            break;
        
        case 4:

            break;
        
        default:
            break;
        }
    } while (ch!=4);
    
}