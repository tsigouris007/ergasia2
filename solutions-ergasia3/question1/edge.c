#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "edge.h"
#include "filehandler.h"

void printEdges(Edge *edges, int edgeCount) {
    for (int i = 0; i < edgeCount; i++)
        printf("%d -> %d\n", edges[i].source, edges[i].destination);
}

Edge *getEdges(char *filename) {
    // Count number of edges and allocate space
    int edgeCount = getEdgeCount(filename);
    Edge *edges = malloc(sizeof(Edge) * edgeCount);

    FILE *fp = fopen(filename, "r");
    const char delim[2] = "-";
    char *token;
    char buff[LINESIZE];
    int source, destination;

    fgets(buff, sizeof(buff), fp); // Skip the first line

    int position = 0;
    while (fgets(buff, sizeof(buff), fp)) {
        buff[strcspn(buff, "\n")] = 0; // Remove newline char
        token = strtok(buff, delim);
        source = atoi(token);
        token = strtok(NULL, delim);
        destination = atoi(token);
        
        Edge edge;
        edge.source = source;
        edge.destination = destination;

        edges[position] = edge;

        position++;
    }
    fclose(fp);

    return edges;
}
