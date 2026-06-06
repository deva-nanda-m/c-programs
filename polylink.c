#include<stdio.h>
#include<stdlib.h>
struct pol
{
    int coeff;
    int exp;
}p1[10],p2[10],p3[10];
void readpol(int t,struct pol p[])
{
    for(int i=0;i<t;i++)
    {
        printf("ENter term %d\n",i+1);
        scanf("%d%d",&p[i].coeff,&p[i].exp);
    }    
}

void display(int t,struct pol p[])
{
    int i;
    for(i=0;i<t-1;i++)
    {
        printf("%dx^%d+",p[i].coeff,p[i].exp);
    }
    printf("%dx^%d\n",p[i].coeff,p[i].exp);
}
int subpol(struct pol p1[],struct pol p2[],struct pol p3[],int t1,int t2)
{//ifor p1jfor p2kfor p3
    int i=0,j=0,k=0;
    while(i<=t1&&j<=t2)
    {
        if(p1[i].exp==p2[j].exp)
        {
            p3[k].coeff=p1[i].coeff-p2[j].coeff;
            p3[k].exp=p1[i].exp;
            k++;
            i++;
            j++;
        }   
        else if(p1[i].exp<p2[j].exp)
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].exp=p2[j].exp;
            k++;
            j++;
        }
        else
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].exp=p1[i].exp;
            k++;
            i++;
        }
    }
    while(i<t1)
    {
        p3[k].coeff=p1[i].coeff;
            p3[k].exp=p1[i].exp;
            k++;
            i++;
    }
    while(j<t2)
    {
        p3[k].coeff=p2[j].coeff;
            p3[k].exp=p2[j].exp;
            k++;
            j++;
    }
    return k;
}
void main()
{
    int t1,t2,t3;
    printf("ENter size of first pol\n");
    scanf("%d",&t1);
    readpol(t1,p1);
    printf("pol 1\n");
    display(t1,p1);
    printf("ENter size of second pol\n");
    scanf("%d",&t2);
    readpol(t2,p2);
    printf("pol 2\n");
    display(t2,p2);
    printf("subtraction\n");
    t3=subpol(p1,p2,p3,t1,t2);
    display(t3,p3);
}