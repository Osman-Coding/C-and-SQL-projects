#include <iostream>
#include <map>
using namespace std;

class Employee {
    public:
        string name;
        double salary;
        int hoursWorked;
};

double calculatePay(const Employee& employee) {
    return employee.salary * employee.hoursWorked;
}

int main() {
    map<string, Employee> employees;

    // Adding employees
    Employee e1;
    e1.name = "John Doe";
    e1.salary = 15.50;
    e1.hoursWorked = 40;
    employees["johnd"] = e1;

    Employee e2;
    e2.name = "Jane Smith";
    e2.salary = 12.75;
    e2.hoursWorked = 35;
    employees["janes"] = e2;

    // Calculating pay for each employee
    for (auto const& [id, employee] : employees) {
        double pay = calculatePay(employee);
        cout << "Employee: " << employee.name << endl;
        cout << "Pay: $" << pay << endl;
    }

    return 0;
}
