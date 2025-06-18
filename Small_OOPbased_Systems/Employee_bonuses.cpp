#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>

class Employee {
protected:
    std::string name;
    double baseSalary;
    static int employeeCount;

public:
    Employee(const std::string& name, double baseSalary) : name(name) {
        if (baseSalary < 0) {
            throw std::invalid_argument("Base salary cannot be negative.");
        }
        this->baseSalary = baseSalary;
        employeeCount++;
    }

    virtual double computeBonus() const = 0;

    virtual ~Employee() {
    }

    static int getEmployeeCount() {
        return employeeCount;
    }

    std::string getName() const {
        return name;
    }

    double getBaseSalary() const {
        return baseSalary;
    }

    void setName(const std::string& newName) {
        if (newName.empty()) {
            throw std::invalid_argument("Name cannot be empty.");
        }
        name = newName;
    }

    void setBaseSalary(double newSalary) {
        if (newSalary < 0) {
            throw std::invalid_argument("Base salary cannot be negative.");
        }
        baseSalary = newSalary;
    }
};

int Employee::employeeCount = 0;

class Developer : public Employee {
private:
    int bugsFixed;
    double bonusPerBug;

public:
    Developer(const std::string& name, double baseSalary, int bugsFixed, double bonusPerBug)
        : Employee(name, baseSalary), bugsFixed(bugsFixed), bonusPerBug(bonusPerBug) {
        if (bugsFixed < 0) {
            throw std::invalid_argument("Bugs fixed cannot be negative.");
        }
        if (bonusPerBug < 0) {
            throw std::invalid_argument("Bonus per bug cannot be negative.");
        }
    }

    double computeBonus() const override {
        return bugsFixed * bonusPerBug;
    }

    void setBugsFixed(int newBugsFixed) {
        if (newBugsFixed < 0) {
            throw std::invalid_argument("Bugs fixed cannot be negative.");
        }
        bugsFixed = newBugsFixed;
    }

    void setBonusPerBug(double newBonusPerBug) {
        if (newBonusPerBug < 0) {
            throw std::invalid_argument("Bonus per bug cannot be negative.");
        }
        bonusPerBug = newBonusPerBug;
    }
};

class Manager : public Employee {
private:
    int teamSize;
    double bonusPerMember;

public:
    Manager(const std::string& name, double baseSalary, int teamSize, double bonusPerMember)
        : Employee(name, baseSalary), teamSize(teamSize), bonusPerMember(bonusPerMember) {
        if (teamSize < 0) {
            throw std::invalid_argument("Team size cannot be negative.");
        }
        if (bonusPerMember < 0) {
            throw std::invalid_argument("Bonus per member cannot be negative.");
        }
    }

    double computeBonus() const override {
        return teamSize * bonusPerMember;
    }

    void setTeamSize(int newTeamSize) {
        if (newTeamSize < 0) {
            throw std::invalid_argument("Team size cannot be negative.");
        }
        teamSize = newTeamSize;
    }

    void setBonusPerMember(double newBonusPerMember) {
        if (newBonusPerMember < 0) {
            throw std::invalid_argument("Bonus per member cannot be negative.");
        }
        bonusPerMember = newBonusPerMember;
    }
};

template <typename T>
T* getTopPerformer(Employee* employees[], int count) {
    T* topPerformer = nullptr;
    double maxBonus = -1.0;

    for (int i = 0; i < count; ++i) {
        T* current = dynamic_cast<T*>(employees[i]);
        if (current != nullptr) {
            double currentBonus = current->computeBonus();
            if (currentBonus > maxBonus) {
                maxBonus = currentBonus;
                topPerformer = current;
            }
        }
    }
    return topPerformer;
}

void displayEmployeeSummary(const Employee& emp) {
    std::cout << "Name: " << emp.getName()
              << ", Base Salary: $" << emp.getBaseSalary()
              << ", Bonus: $" << emp.computeBonus() << std::endl;
}

int main() {
    std::vector<Employee*> employees;

    try {
        employees.push_back(new Developer("Alice", 50000, 10, 50));
        employees.push_back(new Manager("Charlie", 70000, 5, 100));
        employees.push_back(new Manager("David", 75000, 3, 120));

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating employee: " << e.what() << std::endl;
    }

    std::cout << "--- Employee Details ---" << std::endl;
    for (const auto& emp : employees) {
        if (emp) {
            displayEmployeeSummary(*emp);
        }
    }
    std::cout << "Total employees: " << Employee::getEmployeeCount() << std::endl;
    std::cout << std::endl;

    Employee** employeeArray = new Employee*[employees.size()];
    for(size_t i = 0; i < employees.size(); ++i) {
        employeeArray[i] = employees[i];
    }

    Developer* topDeveloper = getTopPerformer<Developer>(employeeArray, employees.size());
    if (topDeveloper) {
        std::cout << "Top Performing Developer: " << topDeveloper->getName()
                  << " with bonus: $" << topDeveloper->computeBonus() << std::endl;
    } else {
        std::cout << "No developers found." << std::endl;
    }

    Manager* topManager = getTopPerformer<Manager>(employeeArray, employees.size());
    if (topManager) {
        std::cout << "Top Performing Manager: " << topManager->getName()
                  << " with bonus: $" << topManager->computeBonus() << std::endl;
    } else {
        std::cout << "No managers found." << std::endl;
    }

    for (auto& emp : employees) {
        delete emp;
        emp = nullptr;
    }
    delete[] employeeArray;
    employeeArray = nullptr;

    return 0;
}