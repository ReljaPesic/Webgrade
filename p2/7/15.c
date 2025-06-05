#include <stdio.h>
#include <stdlib.h>

int find_closest(int arr[], int n, int x) {
  int low = 0, high = n - 1;
  int best_index = -1;
  int best_diff = __INT_MAX__;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int diff = abs(arr[mid] - x);

    if (diff < best_diff || (diff == best_diff && mid < best_index)) {
      best_diff = diff;
      best_index = mid;
    }

    if (arr[mid] < x) {
      low = mid + 1;
    } else if (arr[mid] > x) {
      high = mid - 1;
    } else {
      return arr[mid];
    }
  }

  return arr[best_index];
}

int main() {
  int x, n;
  if (scanf("%d %d", &x, &n) != 2 || n <= 0) {
    fprintf(stderr, "-1\n");
    return 1;
  }

  int *arr = malloc(n * sizeof(int));
  if (!arr) {
    fprintf(stderr, "-1\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      fprintf(stderr, "-1\n");
      free(arr);
      return 1;
    }
  }

  int result = find_closest(arr, n, x);
  printf("%d\n", result);
  free(arr);
  return 0;
}
