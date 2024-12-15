#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "fstream"

#define FILENAME "../docs/workerFile.txt"

using namespace std;

class WorkerManager {
public:
  WorkerManager();
  ~WorkerManager();
  void ShowMenu();
  void ExitSystem();
  void AddWorker();
  void save();
  int getWorkerNum();
  void InitWorker();
  void ShowWorker();
  int IsExist(int id);
  void DelWorker();
  void ModWorker();

  int m_workerNum;
  bool m_fileIsEmpty;
  Worker **m_workerArray;
};
