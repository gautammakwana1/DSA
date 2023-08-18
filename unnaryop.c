#include<stdio.h>
int main()
{
    int a =12; 
    // printf("a:%d,a:%d,a:%d,a:%d",a,a++,++a,++a); //  15141515
    // printf("a:%d,a:%d,a:%d",a++,++a,++a); //  141515
    // printf("a:%d,a:%d,a:%d",a++,++a,a++); // 141512
    // printf("a:%d,a:%d,a:%d",a++,a++,a++); // 141312
    // printf("a:%d,a:%d,a:%d",a,++a,++a); // 141414
    // printf("a:%d,a:%d,a:%d",a,a++,++a); // 141314
    // printf("a:%d,a:%d,a:%d",a,a++,a++); // 141312
    // printf("a:%d,a:%d",++a,a++); // 1412
    // printf("a:%d,a:%d",a,++a); // 1313
    printf("a:%d,a:%d",a,a++); // 1312
}