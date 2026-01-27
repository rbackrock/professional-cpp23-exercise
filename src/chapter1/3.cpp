#include <iostream>
#include <array>
#include <format>

namespace hr {
  enum class Employee_title {
    ProjectManager,
    SeniorEngineer,
    SoftwareEngineer
  };

  struct Employee {
    char firstInitial;
    char lastInitial;
    int employeeNumber;
    int salary;
    Employee_title title;
    std::string showTitle() const {
      switch (this->title) {
        case hr::Employee_title::SoftwareEngineer:
          return "软件工程师";
        case hr::Employee_title::SeniorEngineer:
          return "高级工程师";
        case hr::Employee_title::ProjectManager:
          return "项目经理";
      }

      return "暂无";
    }
    void showMe() const {
      std::cout << std::format("我的名字是{},员工编号为{},薪水为{},头衔为{}", this->firstInitial + this->lastInitial, this->employeeNumber, this->salary, this->showTitle()) << std::endl;
    }
  };
}

int main() {
  hr::Employee e1 {
    .firstInitial { 'A' },
    .lastInitial { 'B' },
    .employeeNumber { 41 },
    .salary { 80001 },
    .title { hr::Employee_title::SoftwareEngineer }
  };

  hr::Employee e2 {
    .firstInitial { 'C' },
    .lastInitial { 'D' },
    .employeeNumber { 42 },
    .salary { 80002 },
    .title { hr::Employee_title::SeniorEngineer }
  };

  hr::Employee e3 {
    .firstInitial { 'E' },
    .lastInitial { 'F' },
    .employeeNumber { 43 },
    .salary { 80003 },
    .title { hr::Employee_title::ProjectManager }
  };

  std::array eleArr { e1, e2, e3 };
  for (const auto & ele : eleArr) {
    // 通过const引用只能调用const成员函数
    ele.showMe();
  }

  return 0;
} 
