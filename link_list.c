#include<stdio.h>
struct node{
    int data;
    struct node *ptr;
};
// struct node{
//     int value;
//     struct node *ptr;
// };


int main()
{
    struct node a,b,c,d,e;
    a.data = 65;
    a.ptr = NULL;

    b.data = 70;
    b.ptr = NULL;
    
    c.data = 100;
    d.data = 200;
    e.data = 300;

    printf("A : data :%d\n",a.data);
    printf("B : data :%d\n",b.data);

    a.ptr = &e;
    b.ptr = &a;
    c.ptr = &b;
    d.ptr = &c;
    e.ptr = &d;
    printf("A : data : %d\n",b.ptr->data);
    printf("B : data : %d\n",c.ptr->data);
    printf("C : data : %d\n",d.ptr->data);
    printf("D : data : %d\n",e.ptr->data);
    printf("E : data : %d\n",a.ptr->data);

    // struct node x,y;
    // x.value
}