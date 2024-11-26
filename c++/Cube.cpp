#include <iostream>

using namespace std;

class Cube {
public: 
  void setL(int l)
  {
    m_L = l;
  }

  int getL()
  {
    return m_L;
  }

  void setW(int w)
  {
    m_W = w;
  }

  int getW()
  {
    return m_W;
  }

  void setH(int h)
  {
    m_H = h;
  }

  int getH() 
  {
    return m_H;
  }
  
  int calculateS()
  {
    return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_H * m_W;
  }

  int calculateV() {
    return m_L * m_W * m_H;
  }

private:
  int m_L;
  int m_W;
  int m_H;
};

bool isSame(Cube &c1, Cube &c2)
{
  return (c1.getL() == c2.getL()) && (c1.getW() == c2.getW()) && (c1.getH() == c2.getH());
}

int main() {
  Cube c1;
  c1.setL(10);
  c1.setW(10);
  c1.setH(10);
  cout << "c1 sea = " << c1.calculateS() << endl;
  cout << "c1 area = " << c1.calculateV() << endl; 

  Cube c2;
  c2.setL(10);
  c2.setW(10);
  c2.setH(10);
  cout << "c2 sea = " << c2.calculateS() << endl;
  cout << "c2 area = " << c2.calculateV() << endl;

  cout << "c1 == c2 ? " << isSame(c1, c2) << endl;

  return 0;
}
