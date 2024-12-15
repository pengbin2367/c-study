#include <iostream>

using namespace std;

class Calculator {
public:
  virtual int getResult()
  {
    return 0;
  }
  int m_Num1;
  int m_Num2;
};

class AddCalculator : public Calculator {
public:
  int getResult()
  {
    return m_Num1 + m_Num2;
  }
};

int main() {
  Calculator *ca = new AddCalculator;
  ca->m_Num1 = 10;
  ca->m_Num2 = 10;
  cout << ca->getResult() << endl;
  delete(ca);
}
