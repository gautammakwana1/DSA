#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertEnd(int val)
{
    struct node *ptr =head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        return;
    }
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return;
}
void deleteEnd()
{
    struct node *ptr =head;
    struct node *p;
    if(ptr->next == NULL)
    {
        head = NULL;
        free(ptr);
        return;
    }
    while(ptr->next != NULL)
    {
        p=ptr;
        ptr=ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return;
}
void display()
{
    struct node *ptr = head;
    if(head == NULL)
    {
        printf("List is Empty...");
    }
    else{
        while(ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}
int main()
{
    int ch;
    printf("\n1. InsertEnd ");
    printf("\n2. DeleteEnd ");
    printf("\n3. Display ");
    printf("\n0. End Program ");
    do{
        int x;
        printf("\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter Your Value :");
                    scanf("%d",&x);
                    insertEnd(x);
                    break;
            case 2:
                    deleteEnd();
                    break;
            case 3:
                    display();
                    break;
            case 0:
                    printf("Program is closed.");
                    break;
            default:
                    printf("You Enter Wrong Choice.");
                    break;
        }
    }while(ch!=0);
    return 0;
}
