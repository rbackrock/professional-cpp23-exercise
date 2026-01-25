#include <iostream>

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
  };
}

int main() {
  hr::Employee e1 {
    .firstInitial { 'J' },
    .lastInitial { 'D' },
    .employeeNumber { 42 },
    .salary { 80000 },
    .title { hr::Employee_title::SeniorEngineer }
  };

  switch (e1.title) {
    case hr::Employee_title::SoftwareEngineer:
      std::cout << "软件工程师" << std::endl;
      break;
    case hr::Employee_title::SeniorEngineer:
      std::cout << "高级工程师" << std::endl;
      break;
    case hr::Employee_title::ProjectManager:
      std::cout << "项目经理" << std::endl;
      break;
  }

  return 0;
} 
