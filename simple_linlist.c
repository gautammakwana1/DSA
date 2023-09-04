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
void Firstinsert(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = ptr;
    head = temp;
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
void Fisrtdelete()
{
    struct node *ptr = head;
    if(ptr->next  == NULL)
    {
        printf("List is empty...");
    }
    head = ptr->next;
    free(ptr);
    return;
}
void Midinsert(int val,int pos)
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
    while(ptr->data != pos)  
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void Middelete(int pos)
{
    struct node *ptr = head;
    struct node *p;
    if(head == NULL)
    {
        printf("List is empty...");
        return;
    }
    // if(ptr == NULL)
    // {
    //     printf("Position is not found...");
    //     return;
    // }
    while(ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
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
    printf("\n4. Insert First ");
    printf("\n5. Delete First ");
    printf("\n6. Mid insert  ");
    printf("\n7. Mid Delete  ");
    printf("\n0. End Program ");
    do{
        int x,pos;
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
            case 4:
                    printf("Enter Your Value :");
                    scanf("%d",&x);
                    Firstinsert(x);
                    break;
            case 5:
                    Fisrtdelete();
                    break;
            case 6:
                    printf("Enter your Value :");
                    scanf("%d",&x);
                    printf("Enter Position :");
                    scanf("%d",&pos);
                    Midinsert(x,pos);
                    break;
            case 7:
                    printf("Enter your position :");
                    scanf("%d",&pos);
                    Middelete(pos);
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
