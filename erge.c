#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1; // Size of left subarray
  int n2 = right - mid;    // Size of right subarray

  // Create temporary arrays
  int L[n1], R[n2];

  // Copy data to temporary arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Merge the temporary arrays back into arr[left..right]
  i = 0;    // Initial index of first subarray
  j = 0;    // Initial index of second subarray
  k = left; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements of L[] if any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy remaining elements of R[] if any
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function that implements merge sort
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    // Find the middle point
    int mid = left + (right - left) / 2;

    // Recursively sort the first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

// Function to print an array
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Main function to test the merge sort
int main()
{
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int arrSize = sizeof(arr) / sizeof(arr[0]);

  printf("Given array is: \n");
  printArray(arr, arrSize);

  mergeSort(arr, 0, arrSize - 1);

  printf("Sorted array is: \n");
  printArray(arr, arrSize);
  return 0;
}
