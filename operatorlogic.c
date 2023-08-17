#include<stdio.h>
int main()
{
    int a=1,b=2,c,d=1;
    c=--a && ++b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=a && ++b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=--a && b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=a && b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=++a || b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=++a || --b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=a || --b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=--a || --b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=a || ++b;
    printf("\na :%d,b :%d,c:%d ",a,b,c);
    c=a && ++b && --d;
    printf("\na :%d,b :%d,c :%d,d :%d ",a,b,c,d);
    c=a || ++b || --d;
    printf("\na :%d,b :%d,c :%d,d :%d ",a,b,c,d);
}