#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int val)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = val;

    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head;
    }
}

void deleteEnd()
{
    struct node *ptr = head;
    struct node *p;
    if (ptr->next == head)
    {
        head = NULL;
        free(ptr);
        return;
    }
    while (ptr->next != head)
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
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    temp->next = head;
    head = temp;
    ptr->next = head;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *p = head;
    struct node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    if (ptr == head)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        ptr->next = head;
    }
    free(p);
}
void midinsert(int val , int pos)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;
     if (head == NULL)
    {
        head = temp;
        return;
    }

    while (ptr->data != pos)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    
}

void deletemid(int pos)
{
    struct node *ptr = head;
    struct node *p ;

    
    while (ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    free(ptr);
    
}

void display()
{
    struct node *ptr = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("\n");
}

int main()
{
    int choice;
    int value, pos;

    while (1)
    {
        printf("1. Insert at the end\n");
        printf("2. Delete from the end\n");
        printf("3. Insert at the first\n");
        printf("4. Delete at the first\n");
        printf("5. insert mid \n");
        printf("6. Delete at the middle \n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            insertEnd(value);
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            insertFirst(value);
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
        printf("Enter a value to insert : ");
        scanf("%d",&value);
        printf("enter a position : ");
        scanf("%d",&pos);
        midinsert(value,pos);
        break;
        case 6:
        printf("enter a position : ");
        scanf("%d",&pos);
        deletemid(pos);
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}