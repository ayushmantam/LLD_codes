#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;

    Employee(string n) : name(n) {}

    void show() {
        cout << "Employee: " << name << endl;
    }
};

class Department {
private:
    Employee* emp;  // Aggregation: does NOT own the Employee
public:
    Department(Employee* e) : emp(e) {}

    void showEmployee() {
        emp->show();
    }
};

int main() {
    Employee* e1 = new Employee("Ayushman");  // Created independently
    Department* d1 = new Department(e1);      // Aggregated into Department

    d1->showEmployee();  // Output: Employee: Ayushman

    // Even if we delete department, employee still exists
    delete d1;

    e1->show();  // ✅ Still works

    delete e1;   // Clean up memory

    return 0;
}
