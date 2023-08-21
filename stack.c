#include<stdio.h>
#define n 10
int a[n];
int i,top=-1;
int display()
{
    if(top<0)
    {
        printf("Array is empty. ");
    }
    else{
        for(i=0;i<=top;i++)
        {
            printf("%d ",a[i]);
        }
    }
}
int insertFirst(int val)
{
    if(top>n-1)
    {
        printf("Array is already full. ");
    }
    else{
        for(i=top;i>=0;i--)
        {
            a[i+1]=a[i];
        }
        a[0]=val;
        top++;
    }
}
int deleteFirst()
{
    if(top<0)
    {
        printf("Array is already emty. ");
    }
    else{
        int p;
        for(i=0;i<top;i++)
        {
            a[i]=a[i+1];
        }
        top--;
        return p;
    }
}
int insertEnd(int val)
{
    if(top>n-1)
    {
        printf("Array is already full. ");
    }
    else{
        top++;
        a[top]=val;
    }
}
int deleteEnd()
{
    if(top<0)
    {
        printf("Array is already empty. ");
    }
    else{
        int p =a[top];
        // for(i=top;i>0;i--)
        // {
        //     a[i+1]=a[i];
        // }
        top--;
        return p;
    }
}

int main()
{
    int ch;
    printf("1. Display ");
    printf("\n2. Insert Array First ");
    printf("\n3. Delete Array First ");
    printf("\n4. Insert Array End ");
    printf("\n5. Delete Array End ");
    printf("\n0. End Program ");
    do
    {
        printf("\nEnter Your Choice :");
        scanf("%d",&ch);
        int val;
        switch(ch)
        {
            case 1:
                    display();
                    break;
            case 2:
                    printf("Enter your array :");
                    scanf("%d",&val);
                    insertFirst(val);
                    break;
            case 3:
                    deleteFirst();
                    break;
            case 4:
                    printf("Enter your array :");
                    scanf("%d",&val);
                    insertEnd(val);
                    break;
            case 5:
                    deleteEnd();
                    break;
            case 0:
                    printf("Program is closed .");
                    break;
            default:
                    printf("You Enter Wrong choice .");
                    break;
        }
    }while(ch!=0);

    return 0;
}