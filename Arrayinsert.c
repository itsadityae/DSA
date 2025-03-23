#include <stdio.h>
void insert(int arr[], int n, int pos, int val)
{if (pos < 0 || pos > n)
    {
        printf("Invalid position\n");
        return;
    }
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    printf("Value inserted successfully\n");
}
void delete(int arr[], int n, int pos)
{
    if (pos < 0 || pos >= n)
    {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("Value deleted successfully\n");
}
void update(int arr[], int n, int pos, int val)
{
    if (pos < 0 || pos >= n)
    {
        printf("Invalid position\n");
        return;
    }
    arr[pos] = val;
    printf("Value updated successfully\n");
}
int search(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}
void traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[100], n, choice, pos, val, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {   printf("\nOperations on Array\n");
        printf("1. Insert  ");
        printf("2. Delete  ");
        printf("3. Update  ");
        printf("4. Search  ");
        printf("5. Traverse  ");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the position to insert the value: ");
            scanf("%d", &pos);
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            insert(arr, n, pos, val);
            n++;
            break;
        case 2:
            printf("Enter the position to delete the value: ");
            scanf("%d", &pos);
            delete (arr, n, pos);
            n--;
            break;
        case 3:
            printf("Enter the position to update the value: ");
            scanf("%d", &pos);
            printf("Enter the new value: ");
            scanf("%d", &val);
            update(arr, n, pos, val);
            break;
        case 4:
            printf("Enter the value to search: ");
            scanf("%d", &val);
            result = search(arr, n, val);
            if (result == -1)
            {
                printf("Value not found\n");
            }
            else
            {
                printf("Value found at position %d\n", result);
            }
            break;
        case 5:
            traverse(arr, n);
            break;
        case 6:
            printf("Exiting program\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}