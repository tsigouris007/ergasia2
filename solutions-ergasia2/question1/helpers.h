#define GENERATE_COUNT 10
#define MAX_NUMBER 100
#define MAX_TREES 100

// This might help somewhere somehow
typedef enum { false, true } boolean;

// Generates a random positive non-zero integer
int generateInt();

// Checks if the given element exists in an array
int elemInArr(int elem, int *arr);

// Prints the given array
void printIntArr(int *arr);

// Generates an array with unique integers to help us create an easier-to-manage tree
int *generateIntArr();

// Prints the Menu
void printMenu();

// Runs the basic program until exit.
// This program can perform all actions.
// You can generate random trees via choice 2.
// You have to always pick a working tree via choice 1.
// If you have a working tree you can perform all other actions.
// You can create up to MAX_TREES. Modify accordingly.
void run();