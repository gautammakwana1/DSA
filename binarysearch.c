#include<stdio.h>
#include<stdlib.h>
#define n 10

int a[n]={10,20,30,40,50,60,70,80,90,100};
int mid;

int search(int key,int low,int high)
{
    do
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            return mid + 1;
        }
        if(a[mid] < key)
        {
            return search(key, mid + 1, high); //low = mid + 1;
        }
        if(a[mid]>key)
        {
            return search(key, low, mid - 1); //high = mid - 1;
        }
        // else{
        //     return -1;
        // }
    }while(high>=low);
    return -1;
}
int main()
{
    int key,x;
    printf("Enter Your Search element :");
    scanf("%d",&key);

    x = search(key, 0, n-1);

    if(x == -1)
    {
        printf("Element of %d is not found in array.",key);
    }
    else
    {
        printf("Element of %d is found at : %d position.",key,x);
    }
}