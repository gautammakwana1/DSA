#include<stdio.h>
#include<stdlib.h>
#define n 15
int a[n],i,j,p;
int selection(int a[])
{
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                p=a[i];
                a[i]=a[j];
                a[j]=p;
                
            }
        }
    }
}
int main()
{
    int a[n],i;
    for(i=0;i<n;i++)
    {
        a[i] = rand()%15 + 1;
        printf("%d ",a[i]);
    }
    selection(a);
    printf("\nSorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}