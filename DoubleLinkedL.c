#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *pre;
	int data;
	struct node *next;
};
struct node *addelement(struct node *head, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->pre = NULL;
	temp->data = data;
	temp->next = NULL;
	head = temp;
	return head; 
}
struct node *addbeg(struct node *head, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->pre = NULL;
	temp->data = data;
	temp->next = NULL;
	temp->next = head;
	head->pre = temp;
	head = temp;
	return head;
}
struct node *addend(struct node *head, int data)
{
	struct node *temp, *tp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->pre = NULL;
	temp->data = data;
	temp->next = NULL;
	tp = head;
	while (tp->next != NULL)
	{
		tp = tp->next;
	}
	tp->next = temp;
	temp->pre = tp;
	return head;
}
void print(struct node *head)
{
	struct node *ptr = head;
	if (ptr == NULL)
	{
		printf("lisrt is empty.");
	}
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}
struct node *insert_at_pos(struct node *head, int data, int pos)
{
	struct node *temp, *temp2;
	struct node *newp = NULL;
	newp = addelement(newp, data);
	temp = head;
	if (pos == 2)
	{
		temp = head->next;
		head->next = newp;
		newp->pre = head;

		temp->pre = newp;
		newp->next = temp;
		return head;
	}
	pos--;
	while (pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	if (temp->next == NULL)
	{
		temp->next = newp;
		newp->pre = temp;
	}
	else if (temp == head)
	{
		newp->next = head;
		head->pre = newp;
		head = newp;
	}

	else
	{
		temp2 = temp->next;
		temp->next = newp;
		newp->pre = temp;
		newp->next = temp2;
		temp2->pre = newp;
	}
	return head;
}

struct node *dell_first(struct node *head)
{
	head = head->next;
	free(head->pre);
	head->pre = NULL;
	return head;
}

struct node *dell_last(struct node *head)
{
	struct node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->pre->next = NULL;
	free(temp);
	temp = NULL;
	return head;
}
struct node *dell_at_pos(struct node *head, int pos)
{
	struct node *temp1, *temp2;
	temp2 = head;
	if (pos == 1)
	{
		head = dell_first(head);
		return head;
	}
	while (pos > 1)
	{
		temp2 = temp2->next;
		pos--;
	}
	temp1 = temp2->pre;
	if (temp2->next == NULL)
	{
		head = dell_last(head);
		return head;
	}
	else
	{

		temp1->next = temp2->next;
		temp2->next->pre = temp1;
		free(temp2);
		temp2 = NULL;
	}
	return head;
}
struct node *reverse(struct node *head)
{
	struct node *ptr1 = head;
	struct node *ptr2 = ptr1->next;
	ptr1->next = NULL;
	ptr1->pre = ptr2;
	while (ptr2 != NULL)
	{
		ptr2->pre = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->pre;
	}
	head = ptr1;
	return head;
}

int main()
{
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));

	printf("\n\nDoubly Linked List\n");
	while (1)
	{
		printf("Choose: 1)Create list  2)Insert an element  3)Delete an element  4)Traverse\nYour Choice: ");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter number of elements to Insert: ");
			int n, i, b;
			scanf("%d", &n);
			printf("Enter element at position 1: ");
			scanf("%d", &b);
			head = addelement(head, b);
			for (i = 1; i < n; i++)
			{
				printf("Enter element at position %d: ", i + 1);
				int a;
				scanf("%d", &a);
				head = addend(head, a);
			}
			print(head);
			printf("\n");
			break;
		case 2:
			printf("Enter the position where to Insert: ");
			int c, d;
			scanf("%d", &c);
			printf("Enter element to be Inserted: ");
			scanf("%d", &d);
			printf("List before Inserting: ");
			print(head);
			printf("\n");
			head = insert_at_pos(head, d, c);
			printf("List after Inserrting: ");
			print(head);
			printf("\n");
			break;
		case 3:
			printf("Enter the position to Delete: ");
			int e;
			scanf("%d", &e);
			printf("List before Deleting is: ");
			print(head);
			printf("\n");
			head = dell_at_pos(head, e);
			printf("List after Deleting is: ");
			print(head);
			printf("\n");
			break;
		case 4:
			printf("\nTraverse:");
			print(head);
			printf("\n\n");
		default:
			printf("wrong choice\n");
		}
	}

	return 0;
}