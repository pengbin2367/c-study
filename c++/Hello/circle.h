#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle {
public:
  void setRadius(int radius);
  int getRadius();
  void setCenter(Point center);
  Point getCenter();

private:
  int m_Radius;
  Point m_Center;
};

#endif
