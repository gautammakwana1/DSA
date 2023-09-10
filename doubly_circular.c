#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre; 
};
struct node *head = NULL;
void insertEnd(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    // temp->next = NULL;
    // temp->pre = NULL;
    if(head == NULL)
    {
        temp->next = temp->pre = temp;
        head = temp;
        return;
    }
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = head;
    temp->pre = ptr;
    return;
}
void deleteEnd()
{
    struct node *ptr = head;
    struct node *p;
    if(head == NULL)
    {
        printf("List is empty...\n");
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
    if(ptr->pre != NULL)
    {
        ptr->pre->next = NULL;
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
    temp->next = head;
    if(head == NULL)
    {
        temp->next = temp;
        // head->pre = temp;
        head = temp;
        return;
    }
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    if(head != NULL)
    {
        head->pre = temp;
    }
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
        printf("List is empty...\n");
        return;
    }
    if(head->next == head)
    {
        head = NULL;
    }
    else{
        while(p->next != head)
        {
            p = p->next;
        }
        p->next = head->next;
        head = head->next;
        head->pre = p;
        free(ptr);
    }
}
void insertMid(int val,int pos)
{
    struct node *ptr = head;
    struct node *x = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    // temp->next = NULL;
    // temp->pre = NULL;
    if (head == NULL)
    {
        printf("List is Empty...\n");
        head = temp;
        return;
    }
    while(ptr != head && ptr->data != pos)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->pre = ptr;
    ptr->next = temp;
    return;
}
void deleteMid(int pos)
{
    struct node *ptr = head;
    struct node *p;
    if(head == NULL)
    {
        printf("List is empty....\n");
        return;
    }
    while(ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
        ptr->pre = p;       
    }
    p->next = ptr->next;
    ptr->next->pre = p;
    free(ptr);
    return;
}
void display()
{
    struct node *ptr = head;
    if(head == NULL)
    {
        printf("List is empty...\n");
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
        printf("1. Display \n");
        printf("2. Insert end\n");
        printf("3. Delete end\n");
        printf("4. Insert First\n");
        printf("5. Delete First\n");
        printf("6. Insert Mid\n");
        printf("7. Delete Mid\n");
        printf("0. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                display();
                break;
        case 2:
                printf("Enter a value to insert: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
        case 3:
                deleteEnd();
                break;
        case 4:
                printf("Enter a value to insert: ");
                  scanf("%d", &val);
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
                printf("Enter Your position :");
                scanf("%d",&pos);
                deleteMid(pos);
                break;
        case 0:
                printf("Program is closed .");
                break;
        default:
                printf("You Enterd Wrong choice .");
                break;
        }
    }while(ch != 0);
}