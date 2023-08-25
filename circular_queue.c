#include<stdio.h>
#define n 5
int a[n];
int f = -1, r = -1;
int display()
{
    int i =f;
    if(f<0)
    {
        printf("Queue is  Empty...");
    }
    else{
        do{
            printf("%d ",a[i]);
            i=(i+1)%n;
        }while(i != (r+1)%n);
    }
    printf("\n");
}
int insertEnd(int val)
{
    if(r<0){
        f = r = 0;
        a[r]=val;
    }
    else if((r+1)%n==f)
    {
        printf("Queue is full...\n");
    }
    else{
        r=(r+1)%n;
        a[r]=val;
    }
}
int deleteEnd()
{
    if(f==r)
    {
        f = -1, r = -1;
    }
    if(f<0 || r<0)
    {
        printf("Queue is Empty....");
    }
    else
    {
        f=(f+1)%n;
    }
    
}
int main()
{
    // insertEnd(10);
    // insertEnd(20);
    // insertEnd(30);
    // insertEnd(40);
    // insertEnd(50);
    // deleteEnd();
    // insertEnd(60);
    // display();
    int ch;
    printf("1. Display");
    printf("\n2. Insert Array ");
    printf("\n3. Delete Array ");
    printf("\n0. End Program ");
    do{
        int val;
        printf("\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    display();
                    break;
            case 2:
                    printf("Enter Your Array :");
                    scanf("%d",&val);
                    insertEnd(val);
                    break;
            case 3:
                    deleteEnd();
                    break;
            case 0:
                    printf("Program is closed.");
                    break;
            default:
                    printf("You Enterd Wrong choice .");
                    break;
        }
    }while(ch != 0);
    return 0;
}