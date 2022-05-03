typedef struct edge {
    int source;
    int destination;
} Edge;

void printEdges(Edge *edges, int edgeCount);
Edge *getEdges(char *filename);
