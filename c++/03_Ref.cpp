#include <iostream>

using namespace std;

void mySwap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int main()
{
  int a = 10;
  int b = 20;
  mySwap(a, b);
  cout << a << " " << b << endl;
  return 0;
}
