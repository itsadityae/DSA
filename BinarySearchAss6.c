#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *delete(struct node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    if (value < root->data)
    {
        root->left = delete (root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete (root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

struct node *search(struct node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }
    if (value < root->data)
    {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, value, numNodes, i;
    printf("\n\nEnter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);
    for (i = 0; i < numNodes; i++)
    {
        printf("Enter the value of the node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    while (1)
    {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search for element\n");
        printf("4. Display tree in inorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            root = delete (root, value);
            break;
        case 3:
            printf("Enter the value to be searched: ");
            scanf("%d", &value);
            if (search(root, value) == NULL)
            {
                printf("%d not found in the tree\n", value);
            }
            else
            {
                printf("%d found in the tree\n", value);
            }
            break;
        case 4:
            printf("The tree in inorder traversal is: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting the program\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
