#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    double salary;
    string designation;
    string emp_id;

    static int employee_count; // Static data member to keep track of the number of employees

public:
    // Constructor
    Employee(string n, int a, double s, string d, string id) 
        : name(n), age(a), salary(s), designation(d), emp_id(id) {
        employee_count++; // Increment count when an employee is created
    }

    // Destructor
    ~Employee() {
        employee_count--; // Decrement count when an employee is deleted
        cout << "Employee " << name << " has been deleted." << endl;
    }

    // Inline function to display employee details
    void displayDetails() const {
        cout << "Employee ID: " << emp_id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "Designation: " << designation << endl;
    }

    // Friend function to search for an employee by ID
    friend Employee* searchEmployee(const string& id, Employee* employees[], int size);

    // Static function to get the total number of employees
    static int getEmployeeCount() {
        return employee_count;
    }
};

// Initialize static data member
int Employee::employee_count = 0;

// Function to search for an employee by ID
Employee* searchEmployee(const string& id, Employee* employees[], int size) {
    for (int i = 0; i < size; i++) {
        if (employees[i]->emp_id == id) {
            return employees[i]; // Return the employee if found
        }
    }
    return nullptr; // Return nullptr if not found
}

int main() {
    const int MAX_EMPLOYEES = 10;
    Employee* employees[MAX_EMPLOYEES]; // Array to store employee objects

    int choice, size = 0;
    string name, designation, emp_id;
    int age;
    double salary;

    do {
        cout << "1. Accept Employee Details" << endl;
        cout << "2. Display Employee Details" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (size < MAX_EMPLOYEES) {
                    cout << "Enter Employee Name: ";
                    cin >> name;
                    cout << "Enter Employee Age: ";
                    cin >> age;
                    cout << "Enter Employee Salary: ";
                    cin >> salary;
                    cout << "Enter Employee Designation: ";
                    cin >> designation;
                    cout << "Enter Employee ID: ";
                    cin >> emp_id;

                    employees[size] = new Employee(name, age, salary, designation, emp_id);
                    size++;
                } else {
                    cout << "Maximum employees reached." << endl;
                }
                break;

            case 2:
                if (size > 0) {
                    cout << "Employee Details:" << endl;
                    for (int i = 0; i < size; i++) {
                        employees[i]->displayDetails();
                        cout << endl;
                    }
                } else {
                    cout << "No employees to display." << endl;
                }
                break;

            case 3:
                if (size > 0) {
                    cout << "Enter Employee ID to search: ";
                    cin >> emp_id;

                    Employee* found_emp = searchEmployee(emp_id, employees, size);
                    if (found_emp) {
                        cout << "Employee found:" << endl;
                        found_emp->displayDetails();
                    } else {
                        cout << "Employee with ID " << emp_id << " not found." << endl;
                    }
                } else {
                    cout << "No employees to search." << endl;
                }
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    // Clean up memory
    for (int i = 0; i < size; i++) {
        delete employees[i]; // Deallocate memory for each employee
    }

    return 0;
}