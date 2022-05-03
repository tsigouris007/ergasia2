#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Create and return a new tree
RBTree *createTree() {
  RBTree *tree = (RBTree *)malloc(sizeof(RBTree));
  Node *emptyNode = (Node *)malloc(sizeof(Node));
  emptyNode->left = NULL;
  emptyNode->right = NULL;
  emptyNode->parent = NULL;
  emptyNode->color = BLACK;
  // We define a nil node with 0 data as our stopping point
  emptyNode->data = 0;
  tree->NIL = emptyNode;
  tree->root = tree->NIL;

  return tree;
}

// Allocates and initializes a node
Node *createNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  node->color = RED;
  node->data = data;

  return node;
}

// Rotates the tree left on the given node
void rotateLeft(RBTree *tree, Node *node) {
  Node *tmpNode = node->right;
  node->right = tmpNode->left;

  if(tmpNode->left != tree->NIL)
    tmpNode->left->parent = node;

  tmpNode->parent = node->parent;
  // Node is Root
  if(node->parent == tree->NIL)
    tree->root = tmpNode;
  // Node is left
  else if(node == node->parent->left)
    node->parent->left = tmpNode;
  // Node is right
  else
    node->parent->right = tmpNode;

  tmpNode->left = node;
  node->parent = tmpNode;
}

// Rotates the tree right on the given node
void rotateRight(RBTree *tree, Node *node) {
  Node *tmpNode = node->left;
  node->left = tmpNode->right;

  if(tmpNode->right != tree->NIL)
    tmpNode->right->parent = node;

  tmpNode->parent = node->parent;
  // Node is Root
  if(node->parent == tree->NIL)
    tree->root = tmpNode;
  // Node is left
  else if(node == node->parent->right)
    node->parent->right = tmpNode;
  // Node is right
  else
    node->parent->left = tmpNode;

  tmpNode->right = node;
  node->parent = tmpNode;
}

// Fixes the RBTree balance on insert
void fixInsert(RBTree *tree, Node *node) {
  while(node->parent->color == RED) {
    Node *parentNode = node->parent;
    Node *grandparentNode = node->parent->parent;

    if(parentNode == grandparentNode->left) {
      Node *uncleNode = grandparentNode->right;

      // Case A1
      if(uncleNode->color == RED) {
        parentNode->color = BLACK;
        uncleNode->color = BLACK;
        grandparentNode->color = RED;
        node = grandparentNode;
      }
      else {
        // Case A2
        if(node == parentNode->right) {
          node = parentNode;
          rotateLeft(tree, node);
        }
        // Case A3
        parentNode->color = BLACK;
        grandparentNode->color = RED;
        rotateRight(tree, grandparentNode);
      }
    }
    else {
      Node *uncleNode = grandparentNode->left;

      // Case B1
      if(uncleNode->color == RED) {
        parentNode->color = BLACK;
        uncleNode->color = BLACK;
        grandparentNode->color = RED;
        node = grandparentNode;
      }
      else {
        // Case B2
        if(node == parentNode->left) {
          node = parentNode;
          rotateRight(tree, node);
        }
        // Case B3
        parentNode->color = BLACK;
        grandparentNode->color = RED;
        rotateLeft(tree, grandparentNode);
      }
    }
  }
  tree->root->color = BLACK;
}

// Inserts a node left or right and assigns the parent pointer accordingly
void insertNode(RBTree *tree, Node *node) {
  Node *tmpParent = tree->NIL;
  Node *tmpRoot = tree->root;

  while(tmpRoot != tree->NIL) {
    tmpParent = tmpRoot;
    if(node->data < tmpRoot->data)
      tmpRoot = tmpRoot->left;
    else
      tmpRoot = tmpRoot->right;
  }

  node->parent = tmpParent;

  // New Node is Root
  if(tmpParent == tree->NIL)
    tree->root = node;
  // Left child
  else if(node->data < tmpParent->data)
    tmpParent->left = node;
  // Right child
  else
    tmpParent->right = node;

  node->right = tree->NIL;
  node->left = tree->NIL;

  fixInsert(tree, node);
}

// Prints the tree in order
void inOrder(RBTree *tree, Node *node) {
  if (node == tree->NIL)
  return;

  inOrder(tree, node->left);
  printf("%d ", node->data);
  inOrder(tree, node->right);
}

// Prints tree preorder
void preOrder(RBTree *tree, Node *node) {
  if (node == tree->NIL)
    return;

  printf("%d ", node->data);
  preOrder(tree, node->left);
  preOrder(tree, node->right);
}

// Prints tree postorder
void postOrder(RBTree *tree, Node *node) {
  if (node == tree->NIL)
    return;

  postOrder(tree, node->left);
  postOrder(tree, node->right);
  printf("%d ", node->data);
}

// Searches for given data and returns the matching node
Node *searchRBTree(RBTree *tree, Node *node, int data) {
  if (node == tree->NIL)
    return NULL;

  if (node->data == data)
    return node;
  
  if (node->data < data)
    return searchRBTree(tree, node->right, data);
  
  return searchRBTree(tree, node->left, data);
}

// Removes a given node from the tree
void removeNode(RBTree *tree, Node *node) {
  Node *copyNode = node; // Pointer to the original node
  Node *tmpNode;
  int tmpColor = copyNode->color; // Original node color

  if(node->left == tree->NIL) {
    tmpNode = node->right;
    swapParent(tree, node, node->right);
  }
  else if(node->right == tree->NIL) {
    tmpNode = node->left;
    swapParent(tree, node, node->left);
  }
  else {
    copyNode = getMin(tree, node->right);
    tmpColor = copyNode->color;
    tmpNode = copyNode->right;
    if(copyNode->parent == node) {
      tmpNode->parent = node;
    }
    else {
      swapParent(tree, copyNode, copyNode->right);
      copyNode->right = node->right;
      copyNode->right->parent = copyNode;
    }
    swapParent(tree, node, copyNode);
    copyNode->left = node->left;
    copyNode->left->parent = copyNode;
    copyNode->color = node->color;
  }
  if(tmpColor == BLACK)
    fixRemove(tree, tmpNode);
}

// Fixes the RBTree balance on delete
void fixRemove(RBTree *tree, Node *node) {
  while(node != tree->root && node->color == BLACK) {
    Node *parentNode = node->parent;

    if(node == parentNode->left) {
      Node *rightSibling = parentNode->right;
      // Case A1
      if(rightSibling->color == RED) {
        rightSibling->color = BLACK;
        parentNode->color = RED;
        rotateLeft(tree, parentNode);
        rightSibling = parentNode->right;
      }
      // Case A2
      if(rightSibling->left->color == BLACK && rightSibling->right->color == BLACK) {
        rightSibling->color = RED;
        node = parentNode;
      }
      else {
        // Case A3
        if(rightSibling->right->color == BLACK) {
          rightSibling->left->color = BLACK;
          rightSibling->color = RED;
          rotateRight(tree, rightSibling);
          rightSibling = parentNode->right;
        }
        // Case A4
        rightSibling->color = parentNode->color;
        parentNode->color = BLACK;
        rightSibling->right->color = BLACK;
        rotateLeft(tree, parentNode);
        node = tree->root;
      }
    }
    else {
      Node *leftSibling = parentNode->left;
      // Case B1
      if(leftSibling->color == RED) {
        leftSibling->color = BLACK;
        parentNode->color = RED;
        rotateRight(tree, parentNode);
        leftSibling = parentNode->left;
      }
      // Case B2
      if(leftSibling->right->color == BLACK && leftSibling->left->color == BLACK) {
        leftSibling->color = RED;
        node = parentNode;
      }
      else {
        // Case B3
        if(leftSibling->left->color == BLACK) {
          leftSibling->right->color = BLACK;
          leftSibling->color = RED;
          rotateLeft(tree, leftSibling);
          leftSibling = parentNode->left;
        }
        // Case B4
        leftSibling->color = parentNode->color;
        parentNode->color = BLACK;
        leftSibling->left->color = BLACK;
        rotateRight(tree, parentNode);
        node = tree->root;
      }
    }
  }
  node->color = BLACK;
}

// Swaps parents between nodes
void swapParent(RBTree *tree, Node *n1, Node *n2) {
  if(n1->parent == tree->NIL)
    tree->root = n2;
  else if(n1 == n1->parent->left)
    n1->parent->left = n2;
  else
    n1->parent->right = n2;
  n2->parent = n1->parent;
}

// Transplants two nodes parents
void transplant(Node *root, Node *node1, Node *node2) {
  if (node1->parent == NULL)
    root = node2;
  else if (node1 == node1->parent->left)
    node1->parent->left = node2;
  else
    node1->parent->right = node2;
  node2->parent = node1->parent;
}

// Finds the minimum left node of a given node
Node *getMin(RBTree *tree, Node *node) {
  while (node->left != tree->NIL)
    node = node->left;
  return node;
}

// Finds the maximum right node of a given node
Node *getMax(RBTree *tree, Node *node) {
  while (node->right != tree->NIL)
    node = node->right;
  return node;
}

void printStructurePadding(char ch, int n) {
  int i;
  for (i = 0; i<n; i++)
    putchar(ch);
}

void printTreeStructure(Node *node, int level) {
  int i;
  if (node == NULL) {
    printStructurePadding('\t', level);
    puts("-");
  }
  else {
    // Avoid printing 0 nil nodes
    if (node->data != 0) {
      printTreeStructure(node->right, level + 1);
      printStructurePadding('\t', level);
      printf("%d", node->data);
      putchar('\n');
    }
    printTreeStructure(node->left, level + 1);
  }
}

// Prints binary tree in 2D (90 degree rotation - tree spans from left to right)
void printTree(RBTree *tree) {
  printTreeStructure(tree->root, 0);
}

// Destroys a given tree
void destroyTree(RBTree *tree ,Node *node) {
  if (node == tree->NIL)
    return;

  destroyTree(tree, node->right);
  destroyTree(tree, node->left);
  free(node);
}
