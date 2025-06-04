#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}
int countNodes(struct Node *root)
{
  if (root == NULL)
    return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}
struct Node *copyTree(struct Node *root)
{
  if (root == NULL)
    return NULL;
  struct Node *newRoot = createNode(root->data);
  newRoot->left = copyTree(root->left);
  newRoot->right = copyTree(root->right);

  return newRoot;
}
struct Node *mirrorTree(struct Node *root)
{
  if (root == NULL)
    return NULL;
  struct Node *mirror = createNode(root->data);
  mirror->left = mirrorTree(root->right);
  mirror->right = mirrorTree(root->left);
  return mirror;
}
void inorderTraversal(struct Node *root)
{
  if (root == NULL)
    Return;
  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
}
int main()
{
  struct Node *root = createNode(9);
  root->left = createNode(56);
  root->right = createNode(67);
  root->left->left = createNode(40);
  root->left->right = createNode(45);
  printf("Original Tree (Inorder): ");
  inorderTraversal(root);
  printf("\n");
  printf("Number of nodes: %d\n", countNodes(root));
  struct Node *copiedTree = copyTree(root);
  printf("Copied Tree (Inorder): ");
  inorderTraversal(copiedTree);
  printf("\n");
  struct Node *mirroredTree = mirrorTree(root);
  printf("Mirrored Tree (Inorder): ");
  inorderTraversal(mirroredTree);
  printf("\n");
  return 0;
}
