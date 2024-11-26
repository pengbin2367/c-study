#include <stdio.h>
#include <string.h>

int main() {
  int arr[10] = {1};
  int nums[10];
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  memcpy(nums, arr, 10 * sizeof(int));
  return 0;
}
