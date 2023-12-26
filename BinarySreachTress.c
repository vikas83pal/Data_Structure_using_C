#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
     int data;
     struct node *left;
     struct node *right;
} BST;
BST *root = NULL;
BST *createNode();
void insert(BST *root, int key);
BST *deleteNode(BST *root, int val);
void inOrder(BST *root);
void preOrder(BST *root);
void postOrder(BST *root);
BST* searchNode(BST* root,int val);
int main()
{
     int ch, d;
     while (1)
     {
          printf("Binary Search Tree\n");
          printf("1. Insertion\n");
          printf("2. Deletion\n");
          printf("3. preoreder\n");
          printf("4. inorder\n");
          printf("5. postorder\n");
          printf("7. Exit\n");
          printf("Enter The Choice:");
          scanf("%d", &ch);
          switch (ch)
          {
          case 1:
               printf("Enter The Data:");
               scanf("%d", &d);
               insert(root, d);
               break;
          case 2:
               printf("Enter The Value to be deleted:");
               scanf("%d", &d);
               root = deleteNode(root, d);
               break;
          case 3:
               printf("PreOrder Traversal\n");
               preOrder(root);
               printf("\n");
               break;
          case 4:
               printf("InOrder Traversal\n");
               inOrder(root);
               printf("\n");
               break;
          case 5:
               printf("PostOrder Traversal\n");
               postOrder(root);
               printf("\n");
               break;
          case 6:
               exit(1);
          }
     }
     return 0;
}
BST *createNode(int data)
{
     BST *temp = (BST *)malloc(sizeof(BST));

     if (temp == NULL)
     {
          // Handle memory allocation failure
          printf("Memory allocation failed.\n");
          exit(EXIT_FAILURE);
     }

     temp->data=data;

     temp->left = NULL;
     temp->right = NULL;

     if (root == NULL)
     {
          root = temp;
     }

     return temp;
}

void insert(BST *root, int data)
{
     BST *temp = root;
     BST *prev = NULL;

     // Search for the correct position to insert the new node
     while (temp != NULL)
     {
          prev = temp;
          if (data == temp->data)
          {
               printf("Duplicate data is not allowed\n");
               return; // Exit the function if duplicate data is found
          }
          else if (data < temp->data)
          {
               temp = temp->left;
          }
          else
          {
               temp = temp->right;
          }
     }

     // Create a new node with the given data
     BST *newNode = createNode(data);

     // If the tree is empty, set the new node as the root
     if (prev == NULL)
     {
          root = newNode;
     }
     else if (data < prev->data)
     {
          prev->left = newNode;
     }
     else
     {
          prev->right = newNode;
     }
}
BST *inOrederPredecessor(BST *root)
{
     root = root->left;
     while (root->right != NULL)
     {
          root = root->right;
     }
     return root;
}
BST *deleteNode(BST *root, int val)
{
     BST *ipre;
     if (root == NULL)
     {
          return NULL;
     }
     if (root->left == NULL && root->right == NULL)
     {
          free(root);
     }
     // Search For the nOde to be Deleted
     if (val < root->data)
     {
          deleteNode(root->left, val);
     }
     else if (val > root->data)
     {
          deleteNode(root->right, val);
     }
     // Deletion strategry when Node is Found
     else
     {
          ipre = inOrederPredecessor(root);
          root->data = ipre->data;
          deleteNode(root->left, ipre->data);
     }
     return root;
}
void inOrder(BST *root)
{
     BST *temp = root;
     if (temp != NULL)
     {
          inOrder(temp->left);
          printf("%d", temp->data);
          inOrder(temp->right);
     }
}
void preOrder(BST *root)
{
     BST *temp = root;
     if (temp != NULL)
     {
          printf("%d", temp->data);
          inOrder(temp->left);

          inOrder(temp->right);
     }
}

void postOrder(BST *root)
{
     BST *temp = root;
     if (temp != NULL)
     {

          inOrder(temp->left);

          inOrder(temp->right);
          printf("%d", temp->data);
     }
}
BST* searchNode(BST* root,int val){
     BST* temp=root;
     if(temp==NULL && temp->data==val){
          return temp;
     }else if(val<temp->data){
          temp=searchNode(temp->left,val);
     }else{
           temp=searchNode(temp->right,val);
     }


}