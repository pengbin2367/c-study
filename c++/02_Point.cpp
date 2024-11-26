#include <iostream>

using namespace std;

void swap(int* arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void bubbleSort(int* arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
  }
}

void printArray(int* arr, int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " " << endl;
  }
}

int main() {
  int a = 10;
  int b = 20;
  int c = 30;
  // 常量指针：指针指向的值不可以改，指针的指向可以更改
  const int* p = &a;
  // 指针常量：指针的指向不可以更改，所指向的值可以更改
  int* const q = &b;
  // const 同时修饰指针和常量，那么指针的指向不可以更改，所指向的值也不能更改
  const int* const r = &c;

  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int* ptr = arr;
  cout << "arr[0] = " << *ptr << endl;
  ptr++;
  cout << "arr[1] = " << *ptr << endl;

  int len = sizeof(arr) / sizeof(int);
  bubbleSort(arr, len);
  printArray(arr, len);

  return 0;
}
