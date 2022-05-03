#include <stdio.h>
void BubbleSort(int *arr, int n) {
	int i;
	int temp;
	int done;
	
	do {
		done = 0;
		for (i=0; i<n-1; i++) {
			if (arr[i] > arr[i+1]) {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				done = 1;
			}
		}
	} while (done == 1);
}

int main(void) {
  int arr[10] = { 5, 7, 1, 0, 9, 3, 2, 8, 6, 4 };
  BubbleSort(arr, 10);
  int i;
  for (i=0; i<10; i++)
    printf("%d ", arr[i]);
  putchar('\n');
  return 0;
}

// Solution:
// https://www.youtube.com/watch?v=Yffvd3pkTW4

// https://www.gatevidyalay.com/bubble-sort-algorithm-example-time-complexity/
// https://www.simplilearn.com/tutorials/data-structure-tutorial/bubble-sort-algorithm
