#include <stdio.h>

struct database {
  char *name;
  int id;
  int age;
  float salary;
};

int main() {
  struct database employee;

  employee.name = "Peter";
  employee.age = 22;
  employee.id = 1;
  employee.salary = 12000.21;

  printf("%s: Employee ID: %d Age: %d Salary: %0.2f\n", employee.name, employee.id, employee.age, employee.salary);
}
