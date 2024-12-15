#include "boss.h"

Boss::Boss(int id, string name, int deptId)
{
  this->m_id = id;
  this->m_name = name;
  this->m_deptId = deptId;
}

void Boss::ShowInfo()
{
  cout << "职工编号：" << this->m_id
    << "\t职工姓名：" << this->m_name
    << "\t岗位：" << this->getDeptName()
    << "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName()
{
  return string("老板");
}
