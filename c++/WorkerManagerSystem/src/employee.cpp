#include "employee.h"

Employee::Employee(int id, string name, int deptId)
{
  this->m_id = id;
  this->m_name = name;
  this->m_deptId = deptId;
}

void Employee::ShowInfo()
{
  cout << "职工编号：" << this->m_id
    << "\t职工姓名：" << this->m_name
    << "\t岗位：" << this->getDeptName()
    << "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName()
{
  return string("员工");
}
