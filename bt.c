#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

// Function to create a new node and build the tree recursively
struct node *create()
{
  int val;
  struct node *newnode = (struct node *)malloc(sizeof(struct node)); // allocate memory for the node

  // Taking input for the current node value
  printf("Enter value of node (-1 for no node): ");
  scanf("%d", &val);

  // If the value is -1, no node is created
  if (val == -1)
  {
    // Free the allocated memory as no node is created
    return NULL;
  }

  newnode->data = val;  // Set the node's data
  newnode->left = NULL; // Initially set left and right child to NULL
  newnode->right = NULL;

  // Recursively create left child
  printf("Enter left child of %d:\n", val);
  newnode->left = create();

  // Recursively create right child
  printf("Enter right child of %d:\n", val);
  newnode->right = create();

  return newnode; // Return the created node
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorderTraversal(root->left);  // Traverse left subtree
  printf("%d -> ", root->data);  // Print the current node
  inorderTraversal(root->right); // Traverse right subtree
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(struct node *root)
{
  if (root == NULL)
  {
    return;
  }
  printf("%d -> ", root->data);   // Print the current node
  preorderTraversal(root->left);  // Traverse left subtree
  preorderTraversal(root->right); // Traverse right subtree
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct node *root)
{
  if (root == NULL)
  {
    return;
  }
  postorderTraversal(root->left);  // Traverse left subtree
  postorderTraversal(root->right); // Traverse right subtree
  printf("%d -> ", root->data);    // Print the current node
}

int main()
{
  struct node *root = NULL;

  // Create the binary tree
  printf("Create the binary tree:\n");
  root = create();

  // Display the tree using different traversals
  printf("\nInorder Traversal:\n");
  inorderTraversal(root);
  printf("\n");

  printf("\nPreorder Traversal:\n");
  preorderTraversal(root);
  printf("\n");

  printf("\nPostorder Traversal:\n");
  postorderTraversal(root);
  printf("\n");

  return 0;
}


