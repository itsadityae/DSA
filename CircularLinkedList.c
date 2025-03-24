#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertBegin(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
}
struct Node *insertEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
    return head;
}
struct Node *deleteBegin(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty\n");
    }
    else
    {
        struct Node *temp = head->next;
        head->next = temp->next;
        free(temp);
    }
    return head;
}
struct Node *deleteEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty\n");
    }
    else
    {
        struct Node *temp = head->next;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp;
    }
    return head;
}
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty\n");
    }
    else
    {
        struct Node *temp = head->next;
        printf("Circular Linked List: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head->next);
        printf("\n");
    }
}

int main()
{
    struct Node *head = NULL;
    printf("\n\nCircular Linked List\n");
    int choice, data;
    do
    {
        printf("\n1. Insert at the beginning");
        printf("  2. Insert at the end");
        printf("  3. Delete from the beginning");
        printf("  4. Delete from the end");
        printf("  5. Traverse");
        printf("  6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted at the beginning: ");
            scanf("%d", &data);
            head = insertBegin(head, data);
            break;
        case 2:
            printf("Enter the data to be inserted at the end: ");
            scanf("%d", &data);
            head = insertEnd(head, data);
            break;
        case 3:
            head = deleteBegin(head);
            break;
        case 4:
            head = deleteEnd(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
