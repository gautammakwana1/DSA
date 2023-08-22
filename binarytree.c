#include<stdio.h>
#include<stdlib.h>
#define n 10
int a[n]={10,20,30,40,50,60,70,80,90,100};
int low=0,high=n-1,mid;
int search(int key)
{
    do{
        mid=low+high/2;

        if(a[mid]==key)
        {
            return mid +1;
        }
        else if(a[mid]<key)
        {
            low=mid+1;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }

    }while(low<=high);

    return -1;
}
int main()
{
    int key;
    printf("Enter your search elements :");
    scanf("%d",&key);

    int x = search(key);

    if(x != -1)
    {
        printf("\nElement of %d is find at %d position .",key,x);
    }
    else
    {
        printf("\nElement of %d is not found in the array .",key);
    }
}
