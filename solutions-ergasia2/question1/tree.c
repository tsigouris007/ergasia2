#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "tree.h"

// Creates and returns a node
Node *createNode(int data) {
  Node *node = (Node*)malloc(sizeof(Node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

// Prints tree preorder.
void preOrder(Node *root) {
  if (root == NULL)
    return;

  printf("%d ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

// Prints tree inorder
void inOrder(Node *root) {
  if (root == NULL)
    return;

  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
}

// Prints tree postorder
void postOrder(Node *root) {
  if (root == NULL)
    return;

  postOrder(root->left);
  postOrder(root->right);
  printf("%d ", root->data);
}

// Prints tree levelorder
void levelOrder(Node *root) {
  int h = treeSize(root);
  int i;
  for (i=1; i<=h; i++)
    printCurrLevel(root, i);
}

// Prints nodes at a given level
void printCurrLevel(Node *root, int level) {
  if (root == NULL)
    return;

  if (level == 1)
    printf("%d ", root->data);
  else {
    level--;
    printCurrLevel(root->left, level);
    printCurrLevel(root->right, level);
  }
}

// Get the level of a given node
int getNodeLevel(Node *root, Node *node, int level) {
  if (root == NULL || node == NULL)
    return 0;

  if (root->data == node->data)
    return level;

  if (root->data > node->data)
    return getNodeLevel(root->left, node, level + 1);
  else
    return getNodeLevel(root->right, node, level + 1);
}

// Compute the size of a given tree
int treeSize(Node *root) {
  if (root == NULL)
    return 0;

  return 1 + treeSize(root->left) + treeSize(root->right);
}

// Compute the height of a given tree
int treeHeight(Node *root) {
  if (root == NULL)
    return 0;

  int leftHeight = treeHeight(root->left);
  int rightHeight = treeHeight(root->right);

  if (leftHeight > rightHeight)
    return leftHeight + 1;
  else
    return rightHeight + 1;
}

// Searches for an element in a given tree
Node *searchTree(Node *root, int data) {
  if (root == NULL)
    return NULL;

  if (root->data == data)
    return root;
  
  if (root->data < data)
    return searchTree(root->right, data);
  
  return searchTree(root->left, data);
}

// Inserts a node
Node *insertNode(Node *node, int data) {
  if (node == NULL)
    return createNode(data);

  // Do not allow duplicate nodes
  if (data == node->data)
    return NULL;

  if (data < node->data)
    node->left = insertNode(node->left, data);

  if (data > node->data)
    node->right = insertNode(node->right, data);

  return node;
}

// Inserts data to the left side of a node
int insertLeft(Node *node, int data) {
  int external = isExternal(node);
  if (external == 1) {
    if (data > node->data)
      return 2;
    node->left = createNode(data);
    return 0;
  }
  return 1;
}

// Inserts data to the right side of a node
int insertRight(Node *node, int data) {
  int external = isExternal(node);
  if (external == 1) {
    if (data < node->data)
      return 2;
    node->right = createNode(data);
    return 0;
  }
  return 1;
}

// Creates a tre with random elements
Node *makeTree(Node *root, Node *left, Node *right) {
  // Generate a random array of integers to populate a tree
  // This is just an assertion. We could populate a tree with user input, file or any other
  // way we can think of.
  int *generatedArr;
  generatedArr = generateIntArr();

  // Create the root node and insert nodes accordingly
  root = createNode(generatedArr[0]);
  int i;
  for (i=1; i<GENERATE_COUNT; i++)
    insertNode(root, generatedArr[i]);

  return root;
}

// Returns the root element
Node *getRoot(Node *root) {
  return root;
}

// Returns the parent of a given node
Node *getParent(Node *root, Node *node) {
  if (root == NULL)
    return NULL;

  if (root->data == node->data)
    return NULL;

  if ((root->left != NULL && root->left->data == node->data) ||
    (root->right != NULL && root->right->data == node->data))
    return root;
  else {
    if (root->data > node->data)
      return getParent(root->left, node);
    else
      return getParent(root->right, node);
  }
}

// Returns the sibling of a given node
Node *getSibling(Node *root, Node *node) {
  if (root == NULL || node == NULL)
    return NULL;

  if (root->left != NULL && root->left->data == node->data)
    return root->right;

  if (root->right != NULL && root->right->data == node->data)
    return root->left;

  Node *tempNode = getSibling(root->left, node);
  if (tempNode != NULL)
    return tempNode;

  tempNode = getSibling(root->right, node);
  return tempNode;
}

// Checks if a given node is internal
int isInternal(Node *node) {
  if (isExternal(node) == 1)
    return 0;
  return 1;
}

// Checks if a given node is external (leaf)
int isExternal(Node *node) {
  if (node->left == NULL && node->right == NULL)
    return 1;
  return 0;
}

// Removes a node from a given tree
// If the node is external (no left or right) then remove as is
// If the node has only a child which is external point the parent to its child
int removeNode(Node *root, Node *node) {
  if (node == NULL || root == NULL)
    return 0;
  
  Node *parentNode = getParent(root, node);

  if (node->left == NULL && node->right == NULL) {
    if(node->data < parentNode->data)
      parentNode->left = NULL;
    else
      parentNode->right = NULL;
    free(node);
    return 1;
  }
  if (node->left == NULL && node->right != NULL) {
    if (isExternal(node->right) == 1) {
      parentNode->right = node->right;
      free(node);
      return 1;
    }
    return 2;
  }
  if (node->left != NULL && node->right == NULL) {
    if (isExternal(node->left) == 1) {
      parentNode->left = node->left;
      free(node);
      return 1;
    }
    return 2;
  }
}

// Destroys a given tree
void destroyTree(Node *root) {
  if (root == NULL)
    return;

  destroyTree(root->right);
  destroyTree(root->left);
  free(root);
}

void printStructurePadding(char ch, int n) {
  int i;
  for (i = 0; i<n; i++)
    putchar(ch);
}

void printTreeStructure(Node *root, int level) {
  int i;
  if (root == NULL) {
    printStructurePadding('\t', level);
    puts("-");
  }
  else {
    printTreeStructure(root->right, level + 1);
    printStructurePadding('\t', level);
    printf("%d\n", root->data);
    printTreeStructure(root->left, level + 1);
  }
}

// Function to print binary tree in 2D (90 degree rotation - tree spans from left to right)
void printTree(Node *root) {
  printTreeStructure(root, 0);
}

// Print data of a given node
void printNode(Node *node) {
  if (node == NULL)
    printf("NULL\n");
  
  printf("%d\n", node->data);
}

// Prints all available trees
void printAvailableTrees(Node *trees[], int size) {
  int i;
  if (size == 0) {
    printf("You have to create at least one tree via choice 2.\n");
    return;
  }

  for (i=0; i<size; i++) {
    printf("%d) ", i);
    inOrder(trees[i]);
    putchar('\n');
  }
}

// Removes a tree from the trees array
void removeTree(Node *trees[], int workingTree, int size, Node *tree) {
  destroyTree(tree);
  int i;
  for (i=workingTree; i<size; i++)
    trees[i] = trees[i+1];
}

// Attaches two trees to be subtrees of an external node on tree. Question Alias: Attach
int attachTrees(Node *child, Node *tree1, Node *tree2) {
  if (child == NULL || tree1 == NULL || tree2 == NULL)
    return 0;

  if (isExternal(child) == 0)
    return 2;

  // Merge first tree accordingly
  if (tree1->data < child->data)
    child->left = tree1;
  else
    child->right = tree1;
  
  // Merge second tree if the node was not populated with the first one
  if (tree2->data < child->data && child->left == NULL)
    child->left = tree2;
  else if (tree2->data > child->data && child->right == NULL)
    child->right = tree2;
  else
    return 3;

  return 1;
}
