#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "helper.h"
#include "filehandler.h"
#include "graph.h"

int main(int argc, char *argv[]) {
    int check = checkArgs(argc, argv);

    if (check != 0)
        return check;
    
    int nodeCount = getNodeCount(argv[1]);
    int edgeCount = getEdgeCount(argv[1]);
    printf("Got %d nodes.\n", nodeCount);
    printf("Got %d edges.\n", edgeCount);

    Edge *edges = getEdges(argv[1]);
    Graph *graph = createGraph(nodeCount, edgeCount); // Initialize
    for (int i = 0; i < edgeCount; i++)
        insertEdge(graph, edges[i].source, edges[i].destination);

    showGraph(graph);

    depthFirst(graph);
    breadthFirst(graph);

    Graph *reverseGraph = graphReverse(graph);
    showGraph(reverseGraph);

    destroyGraph(graph);
    destroyGraph(reverseGraph);
    free(edges);
    return check;
}
