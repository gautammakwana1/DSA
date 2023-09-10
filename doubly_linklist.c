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
    temp->next = NULL;
    temp->pre = NULL; 
    if (head == NULL)
    {
        head = temp;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;    
    }
    ptr->next = temp;
    temp->pre = ptr;
}
void deleteEnd()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->pre != NULL)
    {
        ptr->pre->next = NULL;
    }
    else
    {
        head = NULL;
    }
    free(ptr);
}
void insertFirst(int val)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = head;
    temp->pre = NULL;
    if (head != NULL)
    {
        head->pre = temp;
    }
    head = temp;
}
void deleteFirst()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    head = ptr->next;
    if (head != NULL)
    {
        head->pre = NULL;
    }
    free(ptr);
}
void midInsert(int val, int pos)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    temp->pre = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    while (ptr != NULL && ptr->data != pos)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        temp->next = ptr->next;
        temp->pre = ptr;
        if (ptr->next != NULL)
        {
            ptr->next->pre = temp;
        }
        ptr->next = temp;
    }
    else
    {
        printf("position is not found...\n");
        free(temp);
    }
}
void deletemid(int pos)
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    if (ptr->data == pos)
    {
        head = ptr->next;
        if (head != NULL)
        {
            head->pre = NULL;
        }
        free(ptr);
        return;
    }
    while (ptr != NULL)
    {
        if (ptr->data == pos)
        {
            if (ptr->next != NULL)
            {
                ptr->next->pre = ptr->pre;
            }
            ptr->pre->next = ptr->next;
            free(ptr);
            return;
        }
        ptr = ptr->next;
    }
    printf("position not found...\n", pos);
}
void display()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    int ch, val, pos;

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
                scanf("%d", &value);
                insertEnd(value);
                break;
        case 3:
                deleteEnd();
                break;
        case 4:
                printf("Enter a value to insert: ");
                  scanf("%d", &value);
                insertFirst(value);
                break;
        case 5:
                deleteFirst();
                break;
        case 6:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                printf("Enter a position: ");
                scanf("%d", &pos);
                midInsert(value, pos);
                break;
        case 7:
                printf("Enter a position to delete: ");
                scanf("%d", &pos);
                deletemid(pos);
                break;
        case 0:
                printf("Program is closed...");
                break;
        default:
                printf("Wrong choice..\n");
                break;
        }
    }while(ch != 0);
}
