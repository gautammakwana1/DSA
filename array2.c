#include<stdio.h>
int main()
{
    int i,j,a,x[50],y[50];
    printf("Enter a array :");
    scanf("%d",&a);
    printf("Enter values :");
    for(i=0;i<a;i++)
    {
        scanf("%d",&x[i]);
    }
    j=x[0];
    for(i=0;i<(a-1);i++)
    {
        y[i]=x[i+1];
    }
    y[a-1]=j;
    for(i=0;i<a;i++)
    {
        printf("%d ",y[i]);
    }
    //printf("%d",x[0]);
    return 0;
}