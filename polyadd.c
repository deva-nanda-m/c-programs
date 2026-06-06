#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node*link;   
};
struct node*phead=NULL,*qhead=NULL,*ptr,*rhead;

struct node*readpoly(struct node*head)
{
    int t;
    printf("Enter no of terms of pol\n");
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        struct node*new=(struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        printf("enter coeff and exp of term %d",i+1);
        scanf("%d%d",&new->coeff,&new->exp);
        if(head==NULL)
        {
            head=new;
        }
        else
        {
            ptr=head;
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=new;
        }
    }
    return head;
}
void addpol()
{
    struct node*pptr=phead;
    struct node*qptr=qhead;
    struct node*rptr=rhead;
    while(qptr!=NULL&&pptr!=NULL)
    {
        struct node*new=(struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        if(qptr->exp==pptr->exp)
        {
            new->coeff=pptr->coeff+qptr->coeff;
            new->exp=pptr->exp;
            qptr=qptr->link;
            pptr=pptr->link;
        }
        else if(qptr->exp>pptr->exp)
        {
            new->coeff=qptr->coeff;
            new->exp=qptr->exp;
            qptr=qptr->link;
        }
        else
        {
            new->coeff=pptr->coeff;
            new->exp=pptr->exp;
            pptr=pptr->link;
        }
        if(rhead==NULL)
        {
            rhead=new;
            rptr=new;
        }
        else
        {
            rptr->link=new;
            rptr=new;
        }
    }
    while(pptr!=NULL)
    {
        struct node*new=(struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        new->coeff=pptr->coeff;
        new->exp=pptr->exp;
        if(rhead==NULL)
        {
            rhead=new;
            rptr=new;
        }
        else
        {
            rptr->link=new;
            rptr=new;
        }
        pptr=pptr->link;

    }
    while(qptr!=NULL)
    {
        struct node*new=(struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        new->coeff=qptr->coeff;
        new->exp=qptr->exp;
        if(rhead==NULL)
        {
            rhead=new;
            rptr=new;
        }
        else
        {
            rptr->link=new;
            rptr=new;
        }
        qptr=qptr->link;
    }
}
void display(struct node*head)
{
    ptr=head;
    while(ptr->link!=NULL)
    {
        printf("%dx^%d+",ptr->coeff,ptr->exp);
        ptr=ptr->link;
    }
    printf("%dx^%d\n",ptr->coeff,ptr->exp);
}
void main()
{
    printf("enter first polynomial\n");
    phead=readpoly(phead);
    display(phead);
    printf("enter first polynomial\n");
    qhead=readpoly(qhead);
    display(qhead);
    printf("sum\n");
    addpol();
    display(rhead);
}








