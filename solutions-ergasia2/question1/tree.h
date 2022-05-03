// Basic struct of a node node
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

// Creates and returns a node
Node *createNode(int data);

// Prints tree preorder. Question Alias: PreOrder
void preOrder(Node *root);

// Prints tree inorder. Question Alias: InOrder
void inOrder(Node *root);

// Prints tree postorder. Question Alias: PostOrder
void postOrder(Node *root);

// Prints tree levelorder. Question Alias: LevelOrder
void levelOrder(Node *root);

// Prints nodes at a given level
void printCurrLevel(Node *root, int level);

// Get the level of a given node
int getNodeLevel(Node *root, Node *node, int level);

// Compute the size of a given tree. Question Alias: Size
int treeSize(Node *root);

// Compute the height of a given tree. Question Alias: Height
int treeHeight(Node *root);

// Searches for an element in a given tree
Node *searchTree(Node *root, int data);

// Inserts a node
Node *insertNode(Node *node, int data);

// Inserts data to the left side of a node. Question Alias: InsertLeft
int insertLeft(Node *node, int data);

// Inserts data to the right side of a node. Question Alias: InsertRight
int insertRight(Node *node, int data);

// Creates a tre with random elements. Question Alias: MakeTree
Node *makeTree(Node *root, Node *left, Node *right);

// Returns the root element. Question Alias: Root
Node *getRoot(Node *root);

// Returns the parent of a given node. Question Alias: Parent
Node *getParent(Node *root, Node *node);

// Returns the sibling of a given node. Question Alias: Sibling
Node *getSibling(Node *root, Node *node);

// Checks if a given node is internal. Question Alias: IsInternal
int isInternal(Node *node);

// Checks if a given node is external (leaf). Question Alias: IsExternal
int isExternal(Node *node);

// Removes a node with zero or one child which is externl from a given tree. Question Alias: Remove
// If the node is external (no left or right) then remove as is
// If the node has only a child which is external point the parent to its child
int removeNode(Node *root, Node *node);

// Destroys a given tree. Question Alias: Destroy
void destroyTree(Node *root);

// Function to print binary tree in 2D (90 degree rotation - tree spans from left to right)
// Taken from: https://www.daniweb.com/programming/software-development/threads/146112/printing-a-binary-tree#post692606
void printTree(Node *root);
void printStructurePadding(char ch, int n);
void printTreeStructure(Node *root, int level);

// Print data of a given node
void printNode(Node *node);

// Prints all available trees
void printAvailableTrees(Node *trees[], int size);

// Removes a tree from the trees array
void removeTree(Node *trees[], int workingTree, int size, Node *tree);

// Attaches two trees to be subtrees of an external node on tree. Question Alias: Attach
int attachTrees(Node *child, Node *tree1, Node *tree2);
