#include <stdio.h>
#include "tree.h"

int main(void) {
  int arr[NODE_COUNT] = { 7, 5, 3, 4, 6, 1, 2, 13, 17, 19, 15, 14, 11, 9, 20, 12, 10, 8, 18, 16 };
  int i;

  printf("> Creating tree.\n");
  RBTree *tree = createTree();
  printf("> Inserting nodes.\n");
  for (i=0; i<NODE_COUNT; i++) {
    Node *node = createNode(arr[i]);
    insertNode(tree, node);
  }

  printf("> Printing tree in order.\n");
  inOrder(tree, tree->root);
  putchar('\n');

  printf("> Printing tree post order.\n");
  postOrder(tree, tree->root);
  putchar('\n');

  printf("> Printing tree pre order.\n");
  preOrder(tree, tree->root);
  putchar('\n');

  printf("> Searching tree.\n");
  int data = 14;
  Node *node = searchRBTree(tree, tree->root, data);
  if (node != NULL)
    printf("Found node %d.\n", node->data);
  else
    printf("Could not find node %d.\n", data);
  
  data = 50;
  node = searchRBTree(tree, tree->root, data);
  if (node != NULL)
    printf("Found node %d.\n", node->data);
  else
    printf("Could not find node %d.\n", data);

  printf("> Printing tree structure.\n");
  printTree(tree);
  putchar('\n');

  printf("> Removing some nodes.\n");
  node = searchRBTree(tree, tree->root, 5);
  if (node != NULL) {
    printf("> Found node %d. Removing...\n", node->data);
    removeNode(tree, node);
  }

  node = searchRBTree(tree, tree->root, 15);
  if (node != NULL) {
    printf("> Found node %d. Removing...\n", node->data);
    removeNode(tree, node);
  }

  printf("> Printing tree structure.\n");
  printTree(tree);
  putchar('\n');

  printf("> Destroying the tree.\n");
  destroyTree(tree, tree->root);
  printf("> Exited.\n");
  return 0;
}
