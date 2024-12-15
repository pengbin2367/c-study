#include "worker_manager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test1()
{
  Worker *worker = NULL;
  worker = new Employee(1, "张三", 1);
  worker->ShowInfo();
  delete worker;

  worker = new Manager(2, "李四", 2);
  worker->ShowInfo();
  delete worker;

  worker = new Boss(3, "王五", 3);
  worker->ShowInfo();
  delete worker;
}

int main() {
  WorkerManager wm;
  int choice = 0;
  while (true) {
    wm.ShowMenu();

    cout << "请输入您的选择：";
    cin >> choice;
    switch (choice) {
      case 0: wm.ExitSystem();  break;
      case 1: wm.AddWorker();   break;
      case 2: wm.ShowWorker();  break;
      case 3: wm.DelWorker();   break;
      case 4: wm.ModWorker();   break;
      case 5: break;
      case 6: break;
      case 7: break;
      default: 
        system("clear");
        break;
    }
  }
  return 0;
}
