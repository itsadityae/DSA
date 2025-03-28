#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createS(struct node *head, int n)
{
    struct node *ptr;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    p = head;
    for (int i = 0; i < n; i++)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &ptr->data);
        ptr->next = head;
        if (head == head)
        {
            head = ptr;
        }
        else
        {
            p = head;
            do
            {
                p = p->next;
            } while (p != head);
            p->next = ptr;
        }
    }
    return head;
}
void TraversalLinkedList(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    do
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head=NULL;
    int n, opS, ins, pos, del, optionS;
    printf("\n\nWELCOME TO CIRCULAR LINKED LIST\n");
    printf("\nAt First lets create A List\nEnter the Number of Elements in the List: ");
    scanf("%d", &n);
    head = createS(head, n);
    TraversalLinkedList(head);
    /*do
    {
        printf("\nIf you want to perform any Operations 1->Yes 2->NO\nYour Choice:");
        scanf("%d", &opS);
        if (opS == 1)
        {
            printf("Operations: 1)Insert at Beginning 2)Insert at End 3)Insert at Position 4)Delete at Beginning 5)Delete at End 6)Delete at Position 7)Exit\nYour Choice:");
            scanf("%d", &optionS);

            switch (optionS)
            {
            case 1:
            {
                printf("Element to Insert: ");
                scanf("%d", &ins);
                head = InsertatbeginS(head, ins);
                traversalS(head);
                break;
            }
            case 2:
            {
                printf("Element to Insert: ");
                scanf("%d", &ins);
                head = InsertatendS(head, ins);
                traversalS(head);
                break;
            }
            case 3:
            {
                printf("Element to Insert: ");
                scanf("%d", &ins);
                printf("\nPosition to Insert: ");
                scanf("%d", &pos);
                head = InsertatpositionS(head, ins, pos);
                traversalS(head);
                break;
            }
            case 4:
            {
                head = deleteatbeginS(head);
                traversalS(head);

                break;
            }
            case 5:
            {
                head = deleteatendS(head);
                traversalS(head);
                break;
            }
            case 6:
            {
                printf("Position to Delete: ");
                scanf("%d", &del);
                deleteatIndexS(head, del);
                traversalS(head);
                break;
            }
            default:
            {
                printf("Exiting....\n");
                break;
            }
            }
        }
        else
        {
            printf("Invalid Choice\nTry again\n");
            optionS = 1;
        }

    } while (optionS < 7);*/
    return 0;
}