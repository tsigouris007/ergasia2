#include <stdio.h>
#include <unistd.h>

int checkArgs(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <filepath>\n", argv[0]);
        return 1;
    }

    if (access(argv[1], F_OK) != 0) {
        printf("No such file: %s\n", argv[1]);
        return 2;
    }

    return 0;
}
