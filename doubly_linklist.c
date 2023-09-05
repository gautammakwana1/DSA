#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void display()
{
    struct node *ptr=head;
    if(head==NULL)
        printf("List is empty");
    else
    {
        while(ptr->next!=head)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d ",ptr->data);
    }
    printf("\n");
}
void insertEnd(int val)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
        return;
    }
    while(ptr->next!=head)
        ptr=ptr->next;
    ptr->next=temp;
    temp->next=head;
    temp->prev=ptr;
    return;
}
void insertFrist(int val)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
        return;
    }
    while(ptr->next!=head)
        ptr=ptr->next;
    ptr->next=temp;
    temp->prev=ptr;
    temp->next=head;
    head=temp;
    return;
}
void insertmid(int val,int p)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->prev=NULL;
    while(ptr->data!=p)
        ptr=ptr->next;
    temp->next=ptr->next;
    ptr->next=temp;
    temp->prev=ptr;
}
void deletEnd()
{
    struct node *ptr=head;
    struct node *p;
    if(head->next==NULL)
    {
        head=NULL;
        free(ptr);
        return;
    }
    while(ptr->next!=head)
    {
        p=ptr;
        ptr=ptr->next;
    }
    
    free(ptr);
    return;
}
void deletFrist()
{
    struct node *ptr=head;
    struct node *p=head;
    while(ptr->next!=head)
        ptr=ptr->next;
    ptr->next=p->next;
    head=p->next;
    free(p);
    return;
}
void deletmid(int pos)
{
    struct node *ptr=head;
    struct node *p;
    while(ptr->data != pos){
        p = ptr;
        ptr= ptr->next;
    }
    p->next = ptr->next;
    free(ptr);
}
int main()
{
    int ch,m,n;
    printf("1.last insert\n");
    printf("2.last delet\n");
    printf("3.frist insert\n");
    printf("4.first delet\n");
    printf("5.mid insert\n");
    printf("6.mid delet\n");
    printf("7.Display\n");
    printf("8.exit\n");
    while(ch!=8)
    {
        printf("\nenter choise:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter element:");
            scanf("%d",&m);
            insertEnd(m);
            break;
        case 2:
            deletEnd();
            break;
        case 3:
            printf("enter element:");
            scanf("%d",&m);
            insertFrist(m);
            break;
        case 4:
            deletFrist();
            break;
        case 5:
            printf("enter element:");
            scanf("%d",&m);
            printf("enter position:");
            scanf("%d",&n);
            insertmid(m,n);
            break;
        case 6:
            printf("enter position:");
            scanf("%d",&m);
            deletmid(m);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("exit");
            break;
        }
    }
}
