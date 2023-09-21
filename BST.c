#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*Node creation*/
struct node
{
    int data;
    struct node *left;  // left child
    struct node *right; // right child
};
struct node *root = NULL; // global variable
int d;

/*Function to insert a data into BST*/
void insert(int d)
{
    struct node *temp, *parent;
    struct node *curr;

    temp = (struct node *)malloc(sizeof(struct node)); // Memory allocation
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return; // Exit the function if memory allocation fails
    }

    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;

    parent = NULL; // Initialize parent to NULL
    curr = root;

    if (root == NULL)
    {
        root = temp; // If the tree is empty, make the new node the root
        printf("Node is inserted as root\n");
        return;
    }
    else
    {
        while (curr)
        {
            parent = curr;
            if (temp->data > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
    }

    // Now, parent will be the node where the new node should be inserted
    if (temp->data > parent->data)
    {
        parent->right = temp;
    }
    else
    {
        parent->left = temp;
    }

    printf("Node is inserted\n");
}

/*Function to delete a data*/
void delete()
{
    struct node *temp, *parent;
    struct node *curr;
    temp = (struct node *)malloc(sizeof(struct node));

    /*Deleting the leaf Node*/
    /*deleting the node having Single Child*/
    /*deleting the node having Two Childerens*/
}

/*Function to display*/
/*recursely*/
void inOrder(struct node *temp)
{

    if (temp->left)
        inOrder(temp->left);
    printf("%d\n", temp->data);
    if (temp->right)
        inOrder(temp->right);
}

void preOrder(struct node *temp)
{

    printf("%d\n", temp->data);
    if (temp->left)
        inOrder(temp->left);

    if (temp->right)
        inOrder(temp->right);
}

void postOrder(struct node *temp)
{

    if (temp->left)
        inOrder(temp->left);
    if (temp->right)
        inOrder(temp->right);
    printf("%d\n", temp->data);
}

int main()
{
    int ch, d;
    while (1)
    {
        printf("Binary Search Tree operations...\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");

        printf("3. Inorder\n");
        printf("4. preorder\n");
        printf("5. postorder\n");
        printf("6. Quit\n");

        printf("Enter the choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &d);
            insert(d);
            break;
            /*  case 2:
                  delete ();
                  break;*/
        case 3:
            inOrder(root);
            break;
        case 4:
            preOrder(root);
            break;
        case 5:
            postOrder(root);
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    getch();
    return 0;
}