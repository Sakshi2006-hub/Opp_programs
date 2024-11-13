#include <iostream>
#include <cstring> // For strcpy() and strlen() functions
using namespace std;

class Employee {
    // Data members
    char name[50];
    int age;
    float salary;
    char designation[50];
    int Emp_ID;

    // Static data member to keep track of the number of employees
    static int employeeCount;

public:
    // Constructor to initialize employee details
    Employee() {
        strcpy(name, "");
        age = 0;
        salary = 0.0;
        strcpy(designation, "");
        Emp_ID = 0;
        employeeCount++;
    }

    // Destructor
    ~Employee() {
        employeeCount--;
    }

    // Friend function to display employee details
    friend void displayEmployee(const Employee &emp);

    // Static function to display the total count of employees
    static int getEmployeeCount() {
        return employeeCount;
    }

    // Inline function to accept employee details
    inline void acceptDetails() {
        cout << "Enter Name: ";
        cin >> name; // Using cin instead of gets()

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Salary: ";
        cin >> salary;

        cout << "Enter Designation: ";
        cin >> designation; // Using cin for strings here too

        cout << "Enter Employee ID: ";
        cin >> Emp_ID;
    }

    // Function to search employee by Emp_ID
    int searchEmployee(int id) {
        return Emp_ID == id;
    }
};

// Initializing static data member
int Employee::employeeCount = 0;

// Friend function to display employee details
void displayEmployee(const Employee &emp) {
    cout << "\nEmployee Details: " << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Age: " << emp.age << endl;
    cout << "Salary: " << emp.salary << endl;
    cout << "Designation: " << emp.designation << endl;
    cout << "Employee ID: " << emp.Emp_ID << endl;
}

int main() {
    int numEmployees;

    // Ask how many employees to input
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    // Array to hold multiple employee objects (you can use a dynamic array/vector if needed)
    Employee employees[100]; // Max size 100 employees

    // Use a for loop to accept multiple entries
    for (int i = 0; i < numEmployees; i++) {
        cout << "\nEntering details for employee " << i + 1 << ":" << endl;
        employees[i].acceptDetails();
    }

    // Display the details of all employees
    for (int i = 0; i < numEmployees; i++) {
        cout << "\nDetails of employee " << i + 1 << ":" << endl;
        displayEmployee(employees[i]);
    }

    // Search for employee by ID
    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].searchEmployee(searchID)) {
            cout << "Employee found!" << endl;
            displayEmployee(employees[i]);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee not found." << endl;
    }

    // Display the total count of employees
    cout << "Total number of employees: " << Employee::getEmployeeCount() << endl;

    return 0;
}