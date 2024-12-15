#include "worker_manager.h"
#include <thread>
#include <chrono>

WorkerManager::WorkerManager()
{
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  if (!ifs.is_open() || ifs.peek() == ifstream::traits_type::eof()) {
    this->m_workerNum = 0;
    this->m_workerArray = NULL;
    this->m_fileIsEmpty = true;
    ifs.close();
    return;
  }
  int num = this->getWorkerNum();
  this->m_workerNum = num;
  this->m_workerArray = new Worker*[this->m_workerNum];
  this->m_fileIsEmpty = false;
  this->InitWorker();
}
WorkerManager::~WorkerManager()
{
  if (this->m_workerArray != NULL) {
    delete[] this->m_workerArray;
    this->m_workerArray = NULL;
  }
}

void PauseAndClear(int seconds) {
    // 暂停指定的秒数
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // 清屏命令
    system("clear");
}

void WorkerManager::InitWorker()
{
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  int id;
  string name;
  int deptId;
  int idx = 0;
  while ((ifs >> id) && (ifs >> name) && (ifs >> deptId)) {
    Worker *worker = NULL;
    switch (deptId) {
      case 1:
        worker = new Employee(id, name, deptId);
        break;
      case 2:
        worker = new Manager(id, name, deptId);
        break;
      case 3:
        worker = new Boss(id, name, deptId);
        break;
      default:
        break;
    }
    this->m_workerArray[idx] = worker;
    idx++;
  }
  ifs.close();
}

void WorkerManager::ShowMenu()
{
  cout << "********************************************" << endl;
  cout << "*********  欢迎使用职工管理系统！  *********" << endl;
  cout << "*************  0.退出管理程序  *************" << endl;
  cout << "*************  1.增加职工信息  *************" << endl;
  cout << "*************  2.显示职工信息  *************" << endl;
  cout << "*************  3.删除离职员工  *************" << endl;
  cout << "*************  4.修改职工信息  *************" << endl;
  cout << "*************  5.查找职工信息  *************" << endl;
  cout << "*************  6.按照编号排序  *************" << endl;
  cout << "*************  7.清空所有文档  *************" << endl;
  cout << "********************************************" << endl;
  cout << endl;
}

void WorkerManager::ExitSystem()
{
  exit(0);
}

void WorkerManager::save()
{
  if (this->m_workerNum == 0) {
    this->m_fileIsEmpty = true;
    return;
  }
  ofstream ofs;
  ofs.open(FILENAME, ios::out);

  for (int i = 0; i < this->m_workerNum; i++) {
    ofs << this->m_workerArray[i]->m_id << " "
      << this->m_workerArray[i]->m_name << " "
      << this->m_workerArray[i]->m_deptId << endl;
  }
  ofs.close();
}

void WorkerManager::AddWorker()
{
  cout << "请输入要添加职工数量：";
  int addNum = 0;
  cin >> addNum;

  if (addNum > 0) {
    // 申请空间，存放要添加的职工
    int newSize = this->m_workerNum + addNum;
    Worker **newSpace = new Worker*[newSize];
    if (this->m_workerArray != NULL) {
      for (int i = 0; i < this->m_workerNum; i++) {
        newSpace[i] = this->m_workerArray[i];
      }
    }
    // 批量添加职工
    for (int i = 0; i < addNum; i++) {
      int id;
      string name;
      int deptId;
      cout << "请输入第" << i + 1 << "个职工编号：";
      cin >> id;
      cout << "请输入第" << i + 1 << "个职工姓名：";
      cin >> name;
      cout << "请选择该职工的岗位（1：普通员工；2：经理；3：老板）：";
      cin >> deptId;

      Worker *worker = NULL;
      switch (deptId) {
        case 1:
          worker = new Employee(id, name, deptId);
          break;
        case 2:
          worker = new Manager(id, name, deptId);
          break;
        case 3:
          worker = new Boss(id, name, deptId);
          break;
        default:
          break;
      }
      newSpace[this->m_workerNum + i] = worker;
    }
    delete[] this->m_workerArray;
    this->m_workerArray = newSpace;
    this->m_workerNum = newSize;
    this->m_fileIsEmpty = false;
    cout << "成功添加了" << addNum << "名职工" << endl;
    // 保存数据到文件中
    this->save();
  } else {
    cout << "输入有误";
  }
  cin.get();
  system("clear");
}

int WorkerManager::getWorkerNum()
{
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  int id;
  string name;
  int deptId;
  int num = 0;
  while ((ifs >> id) && (ifs >> name) && (ifs >> deptId)) {
    num++;
  }
  return num;
}

void WorkerManager::ShowWorker()
{
  if (!this->m_fileIsEmpty) {
    for (int i = 0; i < this->m_workerNum; i++) {
      this->m_workerArray[i]->ShowInfo();
    }
  } else {
    cout << "当前系统中尚未添加职工！" << endl;
  }
  PauseAndClear(2);
}

int WorkerManager::IsExist(int id)
{
  for (int i = 0; i < this->m_workerNum; i++) {
    if (this->m_workerArray[i]->m_id == id) {
      return i;
    }
  }
  return -1;
}

void WorkerManager::DelWorker()
{
  if (this->m_fileIsEmpty) {
    cout << "文件不存在或记录为空" << endl;
    return;
  }
  cout << "请输入想要删除的职工编号：" << endl;
  int id;
  cin >> id;
  int idx = this->IsExist(id);
  if (idx == -1) {
    cout << "职工不存在" << endl;
    PauseAndClear(1);
    return;
  }
  for (int i = idx; i < this->m_workerNum - 1; i++) {
    this->m_workerArray[i] = this->m_workerArray[i + 1];
  }
  this->m_workerNum--;
  this->save();
  cout << "删除成功" << endl;
  PauseAndClear(2);
}

void WorkerManager::ModWorker()
{
  if (this->m_fileIsEmpty) {
    cout << "文件不存在或记录为空" << endl;
    return;
  }
  cout << "请输入想要修改的职工编号：" << endl;
  int id;
  cin >> id;
  int idx = this->IsExist(id);
  if (idx == -1) {
    cout << "职工不存在" << endl;
    PauseAndClear(1);
    return;
  }
  delete this->m_workerArray[idx];
  int newId = 0;
  string newName = "";
  int newDeptId = 0;
  cout << "已查到编号为【" << id << "】的员工" << endl;
  cout << "请输入修改后的职工编号:";
  cin >> newId;
  cout << "请输入修改后职工姓名：";
  cin >> newName;
  cout << "请选择修改后该职工的岗位（1：普通员工；2：经理；3：老板）：";
  cin >> newDeptId;

  Worker *worker = NULL;
  switch (newDeptId) {
    case 1:
      worker = new Employee(newId, newName, newDeptId);
      break;
    case 2:
      worker = new Manager(newId, newName, newDeptId);
      break;
    case 3:
      worker = new Boss(newId, newName, newDeptId);
      break;
    default:
      break;
  }
  this->m_workerArray[idx] = worker;
  this->save();
  cout << "修改成功" << endl;
  PauseAndClear(2);
}
