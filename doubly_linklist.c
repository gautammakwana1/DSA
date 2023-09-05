#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev; 
};
struct node *head = NULL;

void insertEnd(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL; 

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
    temp->prev = ptr;
}


void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr->prev != NULL)
    {
        ptr->prev->next = NULL;
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
    temp->prev = NULL;

    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *ptr = head;
    head = ptr->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(ptr);
}

void midInsert(int val, int pos)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

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
        temp->prev = ptr;
        if (ptr->next != NULL)
        {
            ptr->next->prev = temp;
        }
        ptr->next = temp;
    }
    else
    {
        printf("Position %d not found in the list.\n", pos);
        free(temp);
    }
}
void deletemid(int pos)
{
    struct node *ptr = head;

    if (ptr == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (ptr->data == pos)
    {
        head = ptr->next;
        if (head != NULL)
        {
            head->prev = NULL;
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
                ptr->next->prev = ptr->prev;
            }
            ptr->prev->next = ptr->next;
            free(ptr);
            return;
        }
        ptr = ptr->next;
    }
    printf("Node with data %d not found in the list.\n", pos);
}
void display()
{
    struct node *ptr = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
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
    int choice;
    int value, pos;

    while (1)
    {
        printf("1. Insert at the end\n");
        printf("2. Delete from the end\n");
        printf("3. Insert at the beginning\n");
        printf("4. Delete from the beginning\n");
        printf("5. Insert in the middle\n");
        printf("6. Delete from the middle\n");
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
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            printf("Enter a position: ");
            scanf("%d", &pos);
            midInsert(value, pos);
            break;
        case 6:
            printf("Enter a position to delete: ");
            scanf("%d", &pos);
            deletemid(pos);
            break;
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
