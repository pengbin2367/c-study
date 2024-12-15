#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

// 联系人结构体
struct Person {
  string m_Name;
  int m_Sex;
  int m_Age;
  string m_Phone;
  string m_Addr;
};

// 通讯录结构体
struct MailList {
  struct Person personList[MAX];
  int m_Size;
}

void Welcome() {
  cout << "*******************************" << endl;
  cout << "******** 1. 添加联系人 ********" << endl;
  cout << "******** 2. 显示联系人 ********" << endl;
  cout << "******** 3. 删除联系人 ********" << endl;
  cout << "******** 4. 查找联系人 ********" << endl;
  cout << "******** 5. 修改联系人 ********" << endl;
  cout << "******** 6. 清空联系人 ********" << endl;
  cout << "******** 0. 退出通讯录 ********" << endl;
  cout << "*******************************" << endl;
}

void Add(MailList *mailList) {
  if (mailList->m_Size == MAX) {
    cout << "通讯录已满，无法添加！" << endl;
    return;
  }
  cout << "请输入姓名：" << endl;
  cin >> mailList->personList[mailList->m_Size].m_Name;
  cout << "请输入性别：" << endl;
  cout << "1---男" << endl;
  cout << "2---女" << endl;
  int sex;
  cin >> sex;
  while (sex != 1 && sex != 2) {
    cout << "输入的性别无效，请重新输入（1 男，2 女）" << endl;
    cin >> sex;
  }
  mailList->personList[mailList->m_Size].m_Sex = sex;
  mailList->m_Size++;
}

void Show() {

}

void Delete() {

}

void Find() {

}

void Update() {

}

void Clear() {

}

int main() {

  MailList mailList;
  mailList.m_Size = 0;
  
  int op;
  while (true) { 
    Welcome();
    cin >> op;
    switch (op) {
      case 0: 
        cout << "欢迎下次使用！" << endl;
        break;
      case 1: Add(&mailList);    break;
      case 2: Show();   break;
      case 3: Delete(); break;
      case 4: Find();   break;
      case 5: Update(); break;
      case 6: Clear();  break;
      default: break;
    }
  }
}
