#include <iostream>

namespace hr {
  struct Employee {
    char firstInitial;
    char lastInitial;
    int employeeNumber;
    int salary;
  };
}

int main() {
  hr::Employee e1 {
    .firstInitial { 'J' },
    .lastInitial { 'D' },
    .employeeNumber { 42 },
    .salary { 80000 }
  };

  return 0;
} 
