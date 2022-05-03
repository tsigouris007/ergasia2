#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "helpers.h"

// Generates a random positive non-zero integer
int generateInt() {
  return rand() % MAX_NUMBER + 1;
}

// Checks if the given element exists in an array
int elemInArr(int elem, int *arr) {
  int i;
  for (i=0; i<GENERATE_COUNT; i++) {
    if (elem == arr[i]) {
      return 1;
    }
  }
  return 0;
}

// Prints the given array
void printIntArr(int *arr) {
  int i;
  for (i=0; i<GENERATE_COUNT; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Generates an array with unique integers to help us create an easier-to-manage tree
int *generateIntArr() {
  // Init with 0 because we always generate positive integers
  static int arr[GENERATE_COUNT] = { };

  int i;
  for (i=0; i<GENERATE_COUNT; i++) {
    // Keep only unique numbers or re-generate a new number
    while(1) {
      int data = generateInt();
      if (elemInArr(data, arr) == 0) {
        arr[i] = data;
        break;
      }
    }
  }
  return arr;
}

// Prints the Menu
void printMenu() {
  printf("\n+----------------------------+\n");
  printf("|  0. Print available Trees  |\n");
  printf("|  1. Change working Tree    |\n");
  printf("|  2. Generate Tree          |\n");
  printf("|  3. Print 2D Tree          |\n");
  printf("|  4. Print Tree InOrder     |\n");
  printf("|  5. Print Tree PostOrder   |\n");
  printf("|  6. Print Tree LevelOrder  |\n");
  printf("|  7. Get Tree Root          |\n");
  printf("|  8. Get Node Parent        |\n");
  printf("|  9. Get Node Sibling       |\n");
  printf("| 10. Check Node Internal    |\n");
  printf("| 11. Check Node External    |\n");
  printf("| 12. Insert Node Left       |\n");
  printf("| 13. Insert Node Right      |\n");
  printf("| 14. Attach Trees           |\n");
  printf("| 15. Remove Node            |\n");
  printf("| 16. Print Tree Height      |\n");
  printf("| 17. Print Tree Size        |\n");
  printf("| 18. Destroy Tree           |\n");
  printf("| 19. Exit                   |\n");
  printf("+----------------------------+\n\n");
}

// Runs the basic program until exit.
// This program can perform all actions.
// You can generate random trees via choice 2.
// You have to always pick a working tree via choice 1.
// If you have a working tree you can perform all other actions.
// You can create up to MAX_TREES. Modify accordingly.
void run() {
  Node *trees[MAX_TREES];
  int workingTree = -1;
  int choice;
  int size = 0;
  while (1) {
    printMenu();
    printf("Input > ");
    scanf("%d", &choice);
    putchar('\n');
    if (choice < 0 || choice > 19)
      continue;

    if (choice == 0) {
      printAvailableTrees(trees, size);
    }
    else if (choice == 1) {
      if (size == 0) {
        printf("You have to create at least one tree via choice 2.\n");
        continue;
      }
      while (1) {
        printAvailableTrees(trees, size);
        putchar('\n');
        printf("Choose your tree > ");
        scanf("%d", &workingTree);
        if (workingTree < 0 || workingTree >= size)
          continue;
        break;
      }
      printf("\nWorking with tree: %d\n", workingTree);
    }
    else if (choice == 2) {
      // Limit check
      if (size >= MAX_TREES) {
        printf("\nCannot generate any more trees.\n");
        continue;
      }
      Node *root, *left, *right;
      root = makeTree(root, left, right);
      printf("Generated tree.\n");
      trees[size] = root;
      size++;
    }
    else if (choice == 3) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      putchar('\n');
      printTree(trees[workingTree]);
      putchar('\n');
    }
    else if (choice == 4) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      putchar('\n');
    }
    else if (choice == 5) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      postOrder(trees[workingTree]);
      putchar('\n');
    }
    else if (choice == 6) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      levelOrder(trees[workingTree]);
      putchar('\n');
    }
    else if (choice == 7) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      printf("%d) Root: %d", workingTree, getRoot(trees[workingTree])->data);
      putchar('\n');
    }
    else if (choice == 8) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      int data = -1;
      printf("\n\nPick a node > ");
      scanf("%d", &data);
      // Prefered to work with nodes instead of integers so we have to perform a search first
      Node *searchNode = searchTree(trees[workingTree], data);
      if (searchNode == NULL) {
        printf("\nNo such node.\n");
        continue;
      }

      Node *parentNode = getParent(trees[workingTree], searchNode);
      if (parentNode == NULL) {
        printf("\nThe node has no parent.\n");
        continue;
      }

      printf("\nNode %d has parent %d\n", searchNode->data, parentNode->data);
    }
    else if (choice == 9) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      int data = -1;
      printf("\n\nPick a node > ");
      scanf("%d", &data);
      // Same logic, search for the node
      Node *searchNode = searchTree(trees[workingTree], data);
      if (searchNode == NULL) {
        printf("\nNo such node.\n");
        continue;
      }

      Node *siblingNode = getSibling(trees[workingTree], searchNode);
      if (siblingNode == NULL) {
        printf("\nThe node has no sibling.\n");
        continue;
      }

      printf("\nNode %d has sibling %d\n", searchNode->data, siblingNode->data);
    }
    else if (choice == 10) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      int data = -1;
      printf("\n\nPick a node > ");
      scanf("%d", &data);
      // Same logic, search for the node
      Node *searchNode = searchTree(trees[workingTree], data);
      if (searchNode == NULL) {
        printf("\nNo such node.\n");
        continue;
      }

      int result = isInternal(searchNode);
      if (result == 1)
        printf("\nNode %d: Internal\n", searchNode->data);
      else
        printf("\nNode %d: External\n", searchNode->data);
    }
    else if (choice == 11) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      int data = -1;
      printf("\n\nPick a node > ");
      scanf("%d", &data);
      // Same logic, search for the node
      Node *searchNode = searchTree(trees[workingTree], data);
      if (searchNode == NULL) {
        printf("\nNo such node.\n");
        continue;
      }

      int result = isExternal(searchNode);
      if (result == 1)
        printf("\nNode %d: External\n", searchNode->data);
      else
        printf("\nNode %d: Internal\n", searchNode->data);
    }
    else if (choice == 12) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      int data = -1;
      printf("\n\nPick a node > ");
      scanf("%d", &data);
      // Same logic, search for the node
      Node *searchNode = searchTree(trees[workingTree], data);
      if (searchNode == NULL) {
        printf("\nNo such node.\n");
        continue;
      }

      int newdata = -1;
      printf("\nInput new value > ");
      scanf("%d", &newdata);
      int result = insertLeft(searchNode, newdata);
      if (result == 1) {
        printf("\nNode %d is not external.\n");
        continue;
      }
      else if (result == 2) {
        printf("\nCannot insert this value on the left side. Try inserting on the right one.\n");
        continue;
      }
      printf("\nInserted node %d successfully on the left of node %d.\n", newdata, searchNode->data);
    }
    else if (choice == 13) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      int data = -1;
      printf("\n\nPick a node > ");
      scanf("%d", &data);
      // Same logic, search for the node
      Node *searchNode = searchTree(trees[workingTree], data);
      if (searchNode == NULL) {
        printf("\nNo such node.\n");
        continue;
      }

      int newdata = -1;
      printf("\nInput new value > ");
      scanf("%d", &newdata);
      int result = insertRight(searchNode, newdata);
      if (result == 1) {
        printf("\nNode %d is not external.\n");
        continue;
      }
      else if (result == 2) {
        printf("\nCannot insert this value on the right side. Try inserting on the left one.\n");
        continue;
      }
      printf("\nInserted node %d successfully on the right of node %d.\n", newdata, searchNode->data);
    }
    else if (choice == 14) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      int data = -1;
      printf("\n\nPick a node on the working tree > ");
      scanf("%d", &data);
      // Same logic, search for the node
      Node *searchNode = searchTree(trees[workingTree], data);
      if (searchNode == NULL) {
        printf("\nNo such node.\n");
        continue;
      }
      int firstTree = -1;
      int secondTree = -1;

      while (1) {
        printAvailableTrees(trees, size);
        putchar('\n');
        printf("Pick your first tree > ");
        scanf("%d", &firstTree);
        if (firstTree < 0 || firstTree >= size)
          continue;
        break;
      }

      while (1) {
        printAvailableTrees(trees, size);
        putchar('\n');
        printf("Pick your second tree > ");
        scanf("%d", &secondTree);
        if (secondTree < 0 || secondTree >= size)
          continue;
        break;
      }

      printf("\nMerging tree %d under node %d with tree %d and tree %d.\n", workingTree, data, firstTree, secondTree);
      int result = attachTrees(searchNode, trees[firstTree], trees[secondTree]);
      if (result == 1)
        printf("\nSuccessfully attached all trees.\n");
      else if (result == 0)
        printf("\nCannot attach trees to empty node.\n");
      else if (result == 2)
        printf("\nCannot attach trees to internal node.\n");
      else
        printf("\nPartially attached tree to node.\n");
    }
    else if (choice == 15) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      inOrder(trees[workingTree]);
      int data = -1;
      printf("\n\nPick a node > ");
      scanf("%d", &data);
      // Same logic, search for the node
      Node *searchNode = searchTree(trees[workingTree], data);
      if (searchNode == NULL) {
        printf("\nNo such node.\n");
        continue;
      }

      int result = removeNode(trees[workingTree], searchNode);
      if (result == 1)
        printf("\nSuccessfully removed %d.\n", data);
      else if (result == 2)
        printf("\nCannot remove an internal node.\n");
      else
        printf("\nCannot remove this node.\n");
    }
    else if (choice == 16) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      putchar('\n');
      printf("Tree %d is of height %d.\n", workingTree, treeHeight(trees[workingTree]));
    }
    else if (choice == 17) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      putchar('\n');
      printf("Tree %d is of size %d.\n", workingTree, treeSize(trees[workingTree]));
    }
    else if (choice == 18) {
      if (workingTree == -1) {
        printf("You have to choose a working tree first via choice 1.\n");
        continue;
      }
      removeTree(trees, workingTree, size, trees[workingTree]);
      size--;
      workingTree = -1;
      printf("\nRemoved tree. Please select another working tree.\n\n");
      printAvailableTrees(trees, size);
    }
    else if (choice == 19) {
      // Cleanup upon exit
      int i;
      for (i=0; i<size; i++) {
        removeTree(trees, i, size, trees[i]);
        size--;
      }
      break;
    }
  }
  
  printf("Exited.\n");
}
