#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filehandler.h"

int getEdgeCount(char *filename) {
    FILE *fp = fopen(filename, "r");
    char buff[LINESIZE];
    int count = 0;
    while (fgets(buff, sizeof(buff), fp))
        count++;
    fclose(fp);
    return count - 1;
}

int getNodeCount(char *filename) {
    FILE *fp = fopen(filename, "r");
    char buff[LINESIZE];
    fgets(buff, LINESIZE, (FILE*)fp);
    fclose(fp);
    return atoi(buff);
}