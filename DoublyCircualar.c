// Double Circular LinkedList
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *addToEmpty(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct node *addAtBeg(struct node *tail, int data)
{
    struct node *newp = addToEmpty(data); // for creation of new node we are calling the function.
    if (tail == NULL)
    {
        return newp;
    }
    else
    {
        struct node *temp = tail->next;

        newp->prev = tail;
        newp->next = temp;
        temp->prev = newp;
        temp->next = newp;
        return tail;
    }
}
struct node *addAtEnd(struct node *tail, int data)
{
    struct node *newp = addToEmpty(data);
    if (tail == NULL)
    {
        return newp;
    }
    else
    {
        struct node *temp = tail->next;
        newp->next = temp;
        newp->prev = tail;
        tail->next = newp;
        temp->prev = newp;
        tail = newp;
        return tail;
    }
}
struct node *addAtPos(struct node *tail, int data, int Pos)
{
    struct node *temp = tail->next;
    struct node *newp = addToEmpty(data);

    if (tail == NULL)
        return newp;
    if (Pos == 1)
    {
        tail = addAtBeg(tail, data);
        return tail;
    }

    while (Pos > 2)
    {
        temp = temp->next;
        Pos--;
    }
    newp->prev = temp;
    newp->next = temp->next;
    temp->next->prev = newp;
    temp->next = newp;
    if (temp == tail)
        tail = tail->next;
    return tail;
}
struct node *createList(struct node *tail)
{
    int i, n, data;
    printf("Enter the number of nodes of the linked list: ");
    scanf("%d", &n);

    if (n == 0)
        return tail;
    printf("Enter the element 1: ");
    scanf("%d", &data);
    tail = addToEmpty(data);

    for (i = 1; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }
    return tail;
}
struct node *delFirst(struct node *tail)
{
    if (tail == NULL)
        return tail;
    struct node *temp = tail->next;
    if (temp == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
    return tail;
}
struct node *delLast(struct node *tail)
{
    struct node *temp;
    if (tail == NULL)
        return tail;
    if (temp == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    temp = tail->prev;
    temp->next = tail->next;
    tail->next->prev = temp;
    free(tail);
    tail = temp;
    return tail;
}
struct node *delInter(struct node *tail, int pos)
{
    struct node *temp = tail->next;
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    struct node *temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    if (temp == tail)
        tail = temp2;
    return tail;
}
void Traversal(struct node *tail)
{
    if (tail == NULL)
        printf("no element in this list");
    else
    {
        struct node *temp = tail->next;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
    printf("\n");
}
int main()
{
    while (1)
    {
        struct node *tail;
        printf("press:\n 1 To create the list \n 2 To insert the node \n 3 To delete the node \n 4 To traversal the list");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            tail = createList(tail);
            Traversal(tail);
        case 2:
            tail = createList(tail);
            Traversal(tail);
            printf("\n");
            int a, b;
            printf("enter the position to insert the node:");
            scanf("%d", &a);
            printf("enter the data to insert:");
            scanf("%d", &b);
            tail = addAtPos(tail, b, a);
            Traversal(tail);
            break;
        case 3:
            tail = createList(tail);
            Traversal(tail);
            printf("\n");
            int c;
            printf("enter the position to delet the node:");
            scanf("%d", &c);
            tail = delInter(tail, c);
            Traversal(tail);
            break;
        case 4:
            tail = createList(tail);
            Traversal(tail);
            printf("\n");
            break;
        default:
            printf("wronng choice:");
            printf("\n");
        }
    }
    return 0;
}