#include <stdio.h>

// Function to swap two elements
void swap(int array[], int i, int j)
{
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

// Partition function
int partition(int array[], int low, int high)
{
  int pivot = array[high]; // Choose the rightmost element as pivot
  int i = low - 1;         // Pointer for the greater element

  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    { // If element is smaller than or equal to pivot
      i++;
      swap(array, i, j); // Swap elements without pointers
    }
  }

  swap(array, i + 1, high); // Swap pivot into the right position
  return i + 1;             // Return the partition index
}

// Quick Sort function
void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high); // Find the pivot element

    // Recursively sort elements on both sides of pivot
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

// Function to print the array
void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main()
{
  int array[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(array) / sizeof(array[0]);

  printf("Unsorted Array:\n");
  printArray(array, n);

  quickSort(array, 0, n - 1);

  printf("Sorted Array in Ascending Order:\n");
  printArray(array, n);

  return 0;
}
