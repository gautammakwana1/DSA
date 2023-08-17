#include<stdio.h>
int main()
{
    int a[10],b[10],c[50],i,k,n,m,x;
    printf("Enter array :");
    scanf("%d",&m);
    printf("Enter a value :");
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    printf("Enter array :");
    scanf("%d",&n);
    x=i;
    printf("Enter b value :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        c[x]=b[i];
        x++;
    }
    k=m+n;
    printf("\nMerge of array is :");
    for(i=0;i<k;i++)
    {
        printf("%d ",c[i]);
    }
}