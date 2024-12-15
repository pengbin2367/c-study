cmake_minimum_required(VERSION 3.31.2)
project(WorkerManagerSystem VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(wm
  src/boss.cpp
  src/employee.cpp
  src/manager.cpp
  src/worker_manager.cpp
  src/worker_manager_system.cpp
)

target_include_directories(wm PRIVATE ${PROJECT_SOURCE_DIR}/inc)

if (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -flto")
endif()
