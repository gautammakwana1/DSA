#include <stdio.h>
#define n 5

int a[n];
int rear = -1, front = -1, i;

int insertFront(int val)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        printf("Deque is full.\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = n - 1;
        }
        else
        {
            front--;
        }
        a[front] = val;
    }
}

int insertRear(int val)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        printf("Deque is full.\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == n - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        a[rear] = val;
    }
}

int deleteFront()
{
    if (front == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            if (front == n - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
    }
}

int deleteRear()
{
    if (front == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            if (rear == 0)
            {
                rear = n - 1;
            }
            else
            {
                rear--;
            }
        }
    }
}

int display()
{
    if (front == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        i = front;
        while (1)
        {
            printf("%d ", a[i]);
            if (i == rear)
            {
                break;
            }
            if (i == n - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
        }
        printf("\n");
    }
}

int main()
{
    int choice, val;

    do
    {
        printf("Deque Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at the front: ");
            scanf("%d", &val);
            insertFront(val);
            break;
        case 2:
            printf("Enter the value to insert at the rear: ");
            scanf("%d", &val);
            insertRear(val);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
