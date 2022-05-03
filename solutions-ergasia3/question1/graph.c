#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "graph.h"

// Initializes an empty graph
Graph *createGraph(int nodeCount, int edgeCount) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->list = (List *)malloc(nodeCount * sizeof(List));
    graph->visited = (int *)malloc(edgeCount * sizeof(int));
    graph->startCount = (int *)malloc(nodeCount * sizeof(int));
    graph->endCount = (int *)malloc(nodeCount * sizeof(int));
    for (int i = 0; i < nodeCount; i++) {
        graph->list[i].head = NULL;
        graph->visited[i] = 0;
    }
    graph->nodeCount = nodeCount;
    graph->edgeCount = edgeCount;
    return graph;
}

// Destroys a graph
// This has some residuals on nodes atm
void destroyGraph(Graph *graph) {
    for (int i = 0; i < graph->nodeCount; i++)
        free(graph->list[i].head);
    free(graph->list);
    free(graph->visited);
    free(graph->startCount);
    free(graph->endCount);
    free(graph);
}

// Initializes a node
Node *createNode(int destination) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->destination = destination;
    node->next = NULL;
    return node;
}

// Inserts an edge to a directed graph
void insertEdge(Graph *graph, int source, int destination) {
    printf("Inserting edge: %d - %d\n", source, destination);
    Node *newNode = createNode(destination);
    Node *node = NULL;

    // We are at the head of the list
    if (graph->list[source].head == NULL) {
        // Insert node at head
        newNode->next = graph->list[source].head;
        graph->list[source].head = newNode;
    }
    else {
        node = graph->list[source].head;
        // Reach the end of the chain
        while(node->next != NULL)
            node = node->next;
        node->next = newNode;
    }
}

// Prints a graph
void showGraph(Graph *graph) {
    printf("Printing graph.\n");
    for (int i = 0; i < graph->nodeCount; i++) {
        Node *node = graph->list[i].head;
        if (node == NULL) continue;
        printf("%d", i);
        while (node != NULL) {
            printf(" -> %d", node->destination);
            node = node->next;
        }
        putchar('\n');
    }
}

// Depth First Search with Topological Details
void depthFirstSearchTopological(Graph *graph, int start) {
    Node *list = graph->list[start].head;
    Node *node = list;
    
    graph->visited[start] = 1;
    printf(" %d ", start);

    if (list != NULL)
        graph->startCount[list->destination]++;

    while (node != NULL) {
        int conDest = node->destination;

        if (graph->visited[conDest] == 0) {
            // Tree edge
            printf("-(T)->");
            depthFirstSearchTopological(graph, conDest);
        }
        else {
            if (list != NULL)
                // Back edge: the parent node is traversed after the next node
                if (
                    graph->startCount[list->destination] > graph->startCount[node->destination] &&
                    graph->endCount[list->destination] < graph->endCount[node->destination]
                )
                    printf("-(B)->");
                // Forward edge: the next node is a descendant but not a part of tree
                else if (
                    graph->startCount[list->destination] < graph->startCount[node->destination] &&
                    graph->endCount[list->destination] > graph->endCount[node->destination]
                )
                    printf("-(F)->");
                // Cross edge: parent and next node do not have any ancestor and a descendant
                else if (
                    graph->startCount[list->destination] > graph->startCount[node->destination] &&
                    graph->endCount[list->destination] > graph->endCount[node->destination]
                )
                    printf("-(C)->");
        }
        node = node->next;

        if (list != NULL)
            graph->endCount[list->destination] = graph->startCount[list->destination];
    }
}

// Depth First Search without Topological Details
void depthFirstSearchSimple(Graph *graph, int start) {
    Node *list = graph->list[start].head;
    Node *node = list;
    
    graph->visited[start] = 1;
    printf(" %d ->", start);

    while (node != NULL) {
        int conDest = node->destination;

        if (graph->visited[conDest] == 0)
            depthFirstSearchSimple(graph, conDest);
        node = node->next;
    }
}

// Creates a queue for BFS
BFSQueue *createQueue() {
    BFSQueue* q = malloc(sizeof(BFSQueue));
    // q->items = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Checks if the queue is empty
int isEmpty(BFSQueue *q) {
    if (q->rear == -1)
        return 1;
    return 0;
}

// Adds elements to queue
void enQueue(BFSQueue *q, int value) {
    if (q->rear == MAX_BSF_QUEUE - 1)
        printf("Full queue.\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removes elements from queue
int deQueue(BFSQueue *q) {
    int item;
    
    if (isEmpty(q)) {
        printf("Empty queue.\n");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        
        if (q->front > q->rear)
            q->front = q->rear = -1;
    }
    return item;
}

// Resets the queue
BFSQueue *resetQueue(BFSQueue *q) {
    q->front = -1;
    q->rear = -1;
    return q;
}

// Prints the queue
void printQueue(BFSQueue *q) {
    int i = q->front;

    if (isEmpty(q))
        printf("Empty queue.\n");
    else {
        printf("Queue: ");
        for (i = q->front; i < q->rear + 1; i++)
            printf("%d -> ", q->items[i]);
    }
    putchar('\n');
}

// Breadth First Search
void breadthFirstSearch(Graph *graph, int start) {
    BFSQueue *q = createQueue();

    graph->visited[start] = 1;
    enQueue(q, start);

    while (!isEmpty(q)) {
        printQueue(q);

        int currentNode = deQueue(q);
        printf(" %d -> ", currentNode);

        Node *node = graph->list[currentNode].head;

        while (node) {
            int conDst = node->destination;

            if (graph->visited[conDst] == 0) {
                graph->visited[conDst] = 1;
                enQueue(q, conDst);
            }
            node = node->next;
        }
    }
}

// Clears visited nodes
void clearVisited(Graph *graph) {
    for (int i = 0; i < graph->nodeCount; i++) {
        graph->visited[i] = 0;
        graph->startCount[i] = 0;
        graph->endCount[i] = 0;
    }
}

// BFS loop for each head
void breadthFirst(Graph *graph) {
    for (int i = 0; i < graph->nodeCount; i++) {
        printf("Printing BFS for %i.\n", i);
        breadthFirstSearch(graph, i);
        putchar('\n');
        clearVisited(graph);
    }
}

// DFS loop for each head
void depthFirst(Graph *graph) {
    for (int i = 0; i < graph->nodeCount; i++) {
        printf("Printing DFS for %i.\n", i);
        depthFirstSearchSimple(graph, i);
        putchar('\n');
        clearVisited(graph);
    }
}

// Returns a graph in reverse order
Graph *graphReverse(Graph *graph) {
    Graph *newGraph = createGraph(graph->nodeCount, graph->edgeCount);
    Edge *newEdges = malloc(sizeof(Edge) * graph->edgeCount);

    printf("Reversing graph.\n");
    int count = 0;
    // Get the current edges
    for (int i = 0; i < graph->nodeCount; i++) {
        Node *node = graph->list[i].head;
        Edge edge;
        edge.destination = i;
        while (node != NULL) {
            edge.source = node->destination;
            newEdges[count] = edge;
            count++;
            node = node->next;
        }
    }

    // Insert them in reverse order
    for (int i = 0; i < newGraph->edgeCount; i++)
        insertEdge(newGraph, newEdges[i].source, newEdges[i].destination);

    return newGraph;
}
