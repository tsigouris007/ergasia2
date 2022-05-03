#define NODE_COUNT 20
#define BLACK 0
#define RED 1

// Based on
// https://www.programiz.com/dsa/red-black-tree
// https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
// https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
// https://www.codesdope.com/course/data-structures-red-black-trees-insertion/
// https://iq.opengenus.org/red-black-tree-search/
// https://www.programiz.com/dsa/deletion-from-a-red-black-tree
// https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
// https://www.codesdope.com/course/data-structures-red-black-trees-deletion/ INSERT + DELETE
// https://iq.opengenus.org/red-black-tree-deletion/

typedef struct node {
  int data;
  int color;
  struct node *left;
  struct node *right;
  struct node *parent;
} Node;

typedef struct rbtree {
  Node *root;
  Node *NIL;
} RBTree;

// Create and return a new tree. Question Alias: Initialize
RBTree *createTree();

// Allocate and initialize a node
Node *createNode(int data);

// Inserts a node left or right and assigns the parent pointer accordingly
void insertNode(RBTree *tree, Node *node);

// To fix the RBTree balance there are 4 cases
/* 
 * Case A: Parent of node is the left child of the Grandparent of node
 *   Case A1: Uncle of node is also red => recolor
 *   Case A2: Node is right child of its parent => rotateLeft
 *   Case A3: Node is left child of its parent => rotateRight
 * Case B: Parent of node is the right child of the Grandparent of node
 *   Case B1: Uncle of node is also red => recolor
 *   Case B2: Node is left child of its parent => rotateRight
 *   Case B3: Node is right child of its parent => rotateLeft 
 */
// Fixes the RBTree balance on insert
void fixInsert(RBTree *tree, Node *node);

// Rotates the tree left on the given node
void rotateLeft(RBTree *tree, Node *node);

// Rotates the tree right on the given node
void rotateRight(RBTree *tree, Node *node);

// Prints the tree in order. Question Alias: PrintElements
void inOrder(RBTree *tree, Node *node);

// Prints tree preorder
void preOrder(RBTree *tree, Node *node);

// Prints tree postorder
void postOrder(RBTree *tree, Node *node);

// Searches for given data and returns the matching node
Node *searchRBTree(RBTree *tree, Node *node, int data);

// Removes a given node from the tree. Question Alias: RemoveKey
void removeNode(RBTree *tree, Node *node);

/* 
 *   Case A1: Right Sibling is red => recolor + rotateLeft
 *   Case A2: Right Sibling and children are black => recolor
 *   Case A3: Right Sibling and right child are black and left child is red => recolor + rotateRight
 *   Case A4: Right Sibling is black and right child is red => recolor + rotateLeft
 *   Case B1: Left Sibling is red => recolor + rotateRight
 *   Case B2: Left Sibling and children are black => recolor
 *   Case B3: Left Sibling and right child are black and left child is red => recolor + rotateLeft
 *   Case B4: Left Sibling is black and right child is red => recolor + rotateRight
 */
// Fixes the RBTree balance on delete
void fixRemove(RBTree *tree, Node *node);

// Swaps parents between nodes
void swapParent(RBTree *tree, Node *n1, Node *n2);

// Finds the minimum left node of a given node
Node *getMin(RBTree *tree, Node *node);

// Finds the maximum right node of a given node. This was not used but it is cool.
Node *getMax(RBTree *tree, Node *node);

// Prints binary tree in 2D (90 degree rotation - tree spans from left to right)
// Taken from: https://www.daniweb.com/programming/software-development/threads/146112/printing-a-binary-tree#post692606
void printTree(RBTree *tree);
void printStructurePadding(char ch, int n);
void printTreeStructure(Node *node, int level);

// Destroys a given tree
void destroyTree(RBTree *tree ,Node *node);
