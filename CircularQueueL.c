#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;
int count = 0;
void enqueue(int d)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if ((r == NULL) && (f == NULL))
    {
        f = r = n;
        r->next = f;
    }
    else
    {
        r->next = n;
        r = n;
        n->next = f;
    }
    count++;
}

void dequeue()
{
    struct node *t;
    t = f;
    if ((f == NULL) && (r == NULL))
        printf("\nQueue is Empty");
    else if (f == r)
    {
        f = r = NULL;
        free(t);
    }
    else
    {
        f = f->next;
        r->next = f;
        free(t);
    }

    count--;
}

void display()
{ // Print the elements of Queue
    struct node *t;
    t = f;
    if ((f == NULL) && (r == NULL))
        printf("\nQueue is Empty");
    else
    {
        do
        {
            printf(" %d\n", t->data);
            t = t->next;
        } while (t != f);
    }
}

int main()
{
    int ch, no;
    printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n5.size\n");
    while (1)
    {
        printf("enter choice:-");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the data to be inserted :-");
            scanf("%d", &no);
            enqueue(no);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        case 5:
            printf("size is %d\n", count);
        }
    }
    return 0;
}