#include "circle.h"


void Circle::setRadius(int radius)
{
  m_Radius = radius;
}

int Circle::getRadius()
{
  return m_Radius;
}

void Circle::setCenter(Point center)
{
  m_Center = center;
}

Point Circle::getCenter()
{
  return m_Center;
}
