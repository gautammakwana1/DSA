#include<stdio.h>
#define n 5
int a[n];
int i,top=-1;
int display()
{
    if(top<0)
    {
        printf("Array is empty...");
    }
    else
    {
        for(i=0;i<=top;i++)
        {
            printf("%d ",a[i]);
        }
    }
}
int insertEnd(int val)
{
    if(top>=n-1)
    {
        printf("Array is full \n");
    }
    else{
        top++;
        a[top]=val;
    }
}
int delete()
{
    if(top<0)
    {
        printf("Array is already empty");
    }
    else{
        top--;
        //a[top]=val;
    }
}
int main()
{
    insertEnd(100);
    insertEnd(200);
    insertEnd(300);
    insertEnd(400);
    insertEnd(500);
    delete();
    delete();
    display();
}