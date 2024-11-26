#include <cmath>
#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;

void isInCircle(Circle &circle, Point &point)
{
  double distance = pow(circle.getCenter().getX() - point.getX(), 2) + 
                pow(circle.getCenter().getY() - point.getY(), 2);
  double rDistance = pow(circle.getRadius(), 2);
  
  if (distance == rDistance) {
    cout << "点在圆上" << endl;
  } else if (distance < rDistance) {
    cout << "点在圆内" << endl;
  } else {
    cout << "点在圆外" << endl;
  }
}

int main()
{
  Circle circle;
  circle.setRadius(10);
  Point center;
  center.setX(10);
  center.setY(0);
  circle.setCenter(center);

  Point p;
  p.setX(210);
  p.setY(10);

  isInCircle(circle, p);

  return 0;
}
