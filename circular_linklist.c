#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertEnd(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    if(head == NULL)
    {
        head = temp;
        temp->next = temp;
        return;
    }
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = head;
    return;
}
void deleteEnd()
{
    struct node *ptr = head;
    struct node *p;
    if(head == NULL)
    {
        printf("List is empty..");
        return;
    }
    if(ptr->next == head)
    {
        head = NULL;
        free(ptr);
        return;
    }
    while(ptr->next != head)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = head;
    free(ptr);
    return;
}
void insertFirst(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    // temp->next = ptr;
    if(head == NULL)
    {
        head = temp;
        temp->next = temp;
        return; 
    }
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    // if(ptr->next == NULL)
    // {
    //     ptr->next = head; 
    // }
    temp->next = head;
    ptr->next = temp; 
    head = temp;
    return;
}
void deleteFirst()
{
    struct node *ptr = head; 
    struct node *p = head;
    if(head == NULL)
    {
        printf("List is empty...");
        return;
    }
    if(head->next == head)
    {
        head = NULL;
    }else{
    while(p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    head = head->next;
    free(ptr);
    }
}
void insertMid(int val,int pos)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;
    // if(head == NULL)
    // {
    //     return;
    // }
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        printf("List is Empty...\n");
        head = temp;
        return;
    }
    while (ptr->data != pos)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return;
}
void deleteMid(int pos)
{
    struct node *ptr = head;
    struct node *p;
    if(head == NULL)
    {
        printf("List is Empty...");
        return;
    }

    while(ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    free(ptr);
    // while(ptr->data != pos)
    // {
    //     ptr = ptr->next;
    //     if(ptr->data != pos)
    //     {
    //         printf("Position is not found...");
    //     }
    // }
    return;
}
void display()
{
    struct node *ptr = head;
    if(head  == NULL)
    {
        printf("list is empty...");
        return;
    }
    else{
        do{
            printf("%d ",ptr->data);
            ptr = ptr->next;
            
        }while(ptr != head);
    }
    printf("\n");
}
int main()
{
    int val,pos,ch;
    printf("\n1. Display ");
    printf("\n2. Insert End ");
    printf("\n3. Delete End ");
    printf("\n4. Insert First ");
    printf("\n5. Delete First ");
    printf("\n6. Insert Mid ");
    printf("\n7. Delete Mid ");
    printf("\n0. End Program ");
    do{
        printf("\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    display();
                    break;
            case 2:
                    printf("Enter your value :");
                    scanf("%d",&val);
                    insertEnd(val);
                    break;
            case 3:
                    deleteEnd();
                    break;
            case 4:
                    printf("Enter your value :");
                    scanf("%d",&val);
                    insertFirst(val);
                    break;
            case 5:
                    deleteFirst();
                    break;
            case 6:
                    printf("Enter your value :");
                    scanf("%d",&val);
                    printf("Enter your position :");
                    scanf("%d",&pos);
                    insertMid(val,pos);
                    break;
            case 7:
                    printf("Enter your position :");
                    scanf("%d",&pos);
                    deleteMid(pos);
                    break;
            case 0:
                    printf("Program is closed.");
                    break;
            default:
                    printf("You Enter Wrong Choice .");
                    break;
        }
    }while(ch != 0);
}
