#define MAX_BSF_QUEUE 100

typedef struct node {
    int destination;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
} List;

typedef struct graph {
    List *list;
    int *visited;
    int edgeCount;
    int nodeCount;
    int *startCount;
    int *endCount;
} Graph;

typedef struct bfsQueue {
  int items[MAX_BSF_QUEUE];
  int front;
  int rear;
} BFSQueue;

Graph *createGraph(int nodeCount, int edgeCount);
void destroyGraph(Graph *graph);
void showGraph(Graph *graph);

Node *createNode(int destination);
void insertEdge(Graph *graph, int source, int destination);

void depthFirst(Graph *graph);
void clearVisited(Graph *graph);
void depthFirstSearchSimple(Graph *graph, int start);
void depthFirstSearchTopological(Graph *graph, int start);

Graph *graphReverse(Graph *graph);

void breadthFirst(Graph *graph);
void breadthFirstSearch(Graph *graph, int start);
BFSQueue *createQueue();
int isEmpty(BFSQueue *q);
void enQueue(BFSQueue *q, int value);
int deQueue(BFSQueue *q);
BFSQueue *resetQueue(BFSQueue *q);
void printQueue(BFSQueue *q);

// TODO
void strongComponents(Graph *graph);

// https://www.programiz.com/dsa/graph-dfs
// https://www.geeksforgeeks.org/tree-back-edge-and-cross-edges-in-dfs-of-graph/
// https://www.csd.uoc.gr/~hy583/papers/ch3_4.pdf
// https://www.programiz.com/dsa/strongly-connected-components
// https://www.geeksforgeeks.org/strongly-connected-components/