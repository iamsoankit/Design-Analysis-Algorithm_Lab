#include <stdio.h>

void main()
{
  int n, a[n], i, j, key;

  printf("Enter the array size: ");
  scanf("%d", &n);

  printf("Enter the array elements: ");
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
  }

  // Find the second smallest element
  for (j = 2; j < n; j++)
  {
    key = a[j];
    i = j - 1;
    while (i > 0 && a[i] > key)
    {
      a[i + 1] = a[i];
      i--;
    }
    a[i + 1] = key;
  }

  // Print the array
  for (i = 1; i <= n; i++)
  {
    printf("%d ", a[i]);
  }

  // Print the second smallest element
  printf("\nSecond smallest element: %d\n", a[2]);

  // Update the array with the second smallest and smallest elements
  int b[2];
  b[0] = a[2];
  b[1] = a[n - 1];

  // Print the updated array
  printf("Updated array: ");
  for (i = 0; i < 2; i++)
  {
    printf("%d ", b[i]);
  }
}

