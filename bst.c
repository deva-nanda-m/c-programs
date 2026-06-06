#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left,*right;
}*ptr,*parent,*root=NULL;
struct node* create()
{
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->right=NULL;
    new->left=NULL;
    return new;
}
void insert(int item)
{
    int flag=0;
    struct node*new=create();
    new->data=item;
    ptr=root;
    if(root==NULL)
    {
        root=new;
    }
    else
    {
        while(ptr!=NULL&&flag==0)
        {
            if(ptr->data<item)
            {
                parent=ptr;
                ptr=ptr->right;
            }
            else if(ptr->data>item)
            {
                parent=ptr;
                ptr=ptr->left;
            }
            else
            {
                flag=1;
                printf("cannot insert\n");
                return;
            }
        }
        if(parent->data<item)
            parent->right=new;
        else
            parent->left=new;
    }
}
int minNodeval(struct node*curr)
{
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr->data;
}
void delete(int item)
{
    if(root==NULL)
    {
        printf("tree empty\n");
    }
    ptr=root;
    while(ptr->data!=item&&ptr!=NULL)
    {
        if(ptr->data<item)
        {
            parent=ptr;
            ptr=ptr->right;
        }
        else if(ptr->data>item)
        {
            parent=ptr;
            ptr=ptr->left;
        }
    }
    if(ptr==NULL)
    {
        printf("KEY not present\n");
    }

    if(ptr->right==NULL&&ptr->left==NULL)
    {
        if(parent->right==ptr)
            parent->right=NULL;
        else
            parent->left=NULL;
    }
    else if(ptr->left!=NULL&&ptr->right!=NULL)
    {
        int min=minNodeval(ptr->right);
        int t=min;
        delete(min);
        ptr->data=t;
    }
    else
    {
        if(ptr->right!=NULL)
        {
            if(parent->right==ptr)
                parent->right=ptr->right;
            else
                parent->left=ptr->right;
        }
        else
        {
            if(parent->right==ptr)
                parent->right=ptr->left;
            else
                parent->left=ptr->left;
        }
    }
}
void preorder(struct node*roo)
{
    struct node*temp=roo;
    if(temp==NULL)
    {
        return;
    }
    else
    {
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct node*roo)
{
    struct node*temp=roo;
    if(temp==NULL)
    {
        return;
    }
    else
    {
    inorder(temp->left);
    printf("%d\t",temp->data);
    inorder(temp->right);
    }
}
void postorder(struct node*roo)
{
    struct node*temp=roo;
    if(temp==NULL)
    {
        return;
    }
    else
    {
    postorder(temp->left);
    postorder(temp->right);
    printf("%d\t",temp->data);
    }
}
void main()
{
    int item,ch,key;
    
    do
    {
        printf("Enter choice\n1:insert\n2:delete\n3:preorder\n4:inorder\n5:postorder\n6:exit\n");
        scanf("%d",&ch);
            switch (ch)
        {
        case 1:
            printf("Enter item\n");
        scanf("%d",&item);
        insert(item);
            break;
        case 2:
            printf("Enter key\n");
        scanf("%d",&key);
        delete(key);
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            postorder(root);
            printf("\n");
            break;
        case 6:
            break;
        
        default:
            printf("Please enter a valid choice\n");
            break;
        }
    } while (ch!=6);
    
}