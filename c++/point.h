#ifndef POINT_H
#define POINT_H

class Point {
public:
  void setX(int x);
  int getX();
  void setY(int y);
  int getY();
private:
  int m_X;
  int m_Y;
};

#endif
