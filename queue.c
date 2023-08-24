#include<stdio.h>
#define n 10
int a[n],i;
int r=-1,f=-1;
int insert(int val)
{
    if(f<0 || r<0)
    {
        f=0,r=0;
        a[r]=val;
    }
    if(r > n-1)
    {
        printf("Array is full.");
    }
    else{        
        r++;
        a[r]=val;
    }
}
int display()
{
    if(r<0 || f<0)
    {
        printf("Array is Empty .");
    }
    else{
        for(i=f+1;i<r+1;i++)
        {
            printf("%d ",a[i]);
        }      
    }
}
int delete()
{
    if(f==r)
    {
        f=-1,r=-1;
    }
    if(f<0 || r<0)
    {
        printf("Array is empty.");
    }
    else{
        f++;
    }
}
int main()
{
    // insert(10);
    // insert(20);
    // insert(30);
    // insert(40);
    // insert(50);
    // insert(60);
    // delete();
    // delete();
    // delete();
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
                    insert(val);
                    break;
            case 3:
                    delete();
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