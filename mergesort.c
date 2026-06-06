#include<stdio.h>
void merge(int arr[],int beg,int mid,int end)
{
    int n1,n2,l[10],r[10],j,i;
    n1=mid-beg;
    n2=end-mid+1;

    j=beg;
    for(i=0;i<n1;i++)
    {
        l[i]=arr[j];
        j++;
    }
    j=mid;
    for(i=0;i<n2;i++)
    {
        r[i]=arr[j];
        j++;
    }

    i=0,j=0;
    int k=beg;//i for l and j forr
    while(i<n1&&j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(arr,beg,mid);
        mergesort(arr,mid+1,end);
        merge(arr,beg,mid+1,end);
    }
}
void main()
{
    int arr[7],n,i;
    printf("Enter size\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("Merge Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}