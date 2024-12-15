#pragma once
#include <iostream>
#include <string>

using namespace std;

class Worker{
public:
  virtual void ShowInfo() = 0;
  virtual string getDeptName() = 0;

  int m_id;
  string m_name;
  int m_deptId;
};
