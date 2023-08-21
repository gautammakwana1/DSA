#include<stdio.h>
#include<stdlib.h>
#define n 100
int linearSearch(int a [], int x)
{
    for (int i=0;i<n;i++)
    {
        if(a[i]==x){
        return i+1;
        }
    }    
    return -1;
}
int main()
{
    int a[n],i,ele;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%50+1;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n Enter Search element :");
    scanf("%d",&ele);
    int m= linearSearch(a,ele);
    if(m==-1)
    {
        printf("elemetn is not found :");

    }
    else
    {
        printf("search element if found at %d position ",m);
    }
}