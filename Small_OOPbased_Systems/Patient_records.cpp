#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdexcept>

using namespace std;

class Patient {
private:
    int id;
    string name;
    int age;
    double temperature;
    string disease;

public:
    Patient() : id(0), name(""), age(0), temperature(98.6), disease("") {}

    Patient(int id, const string& name, int age, double temperature, const string& disease)
        : id(id), name(name), disease(disease) {
        setAge(age);
        setTemperature(temperature);
    }

    Patient(const Patient& other)
        : id(other.id), name(other.name), age(other.age), temperature(other.temperature), disease(other.disease) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    double getTemperature() const { return temperature; }
    string getDisease() const { return disease; }

    void setId(int newId) { id = newId; }
    void setName(const string& newName) { name = newName; }
    void setDisease(const string& newDisease) { disease = newDisease; }

    void setAge(int newAge) {
        if (newAge < 0) {
            throw invalid_argument("Age cannot be negative.");
        }
        age = newAge;
    }

    void setTemperature(double newTemperature) {
        if (newTemperature < 0) {
            throw invalid_argument("Temperature cannot be negative.");
        }
        temperature = newTemperature;
    }

    void display() const {
        cout << "ID: " << id
                  << ", Name: " << name
                  << ", Age: " << age
                  << ", Temp: " << temperature << "F"
                  << ", Disease: " << disease << endl;
    }
};

class PatientRegistry {
public:
    vector<Patient> patients;

    void addNewPatient(const Patient& p) {
        patients.push_back(p);
    }

    void removePatientById(int id) {
        patients.erase(remove_if(patients.begin(), patients.end(),
                                       [id](const Patient& p) { return p.getId() == id; }),
                        patients.end());
    }

    Patient* findPatientByDisease(const string& disease) {
        auto it = find_if(patients.begin(), patients.end(),
                               [disease](const Patient& p) { return p.getDisease() == disease; });
        if (it != patients.end()) {
            return &(*it);
        }
        return nullptr;
    }

    void sortPatientsByAge() {
        sort(patients.begin(), patients.end(),
                  [](const Patient& a, const Patient& b) { return a.getAge() < b.getAge(); });
    }

    void displayAllPatients() const {
        if (patients.empty()) {
            cout << "No patients in the registry." << endl;
            return;
        }
        for (const auto& p : patients) {
            p.display();
        }
    }

    void displayPatientsWithFever(double feverThreshold = 100.0) const {
        bool found = false;
        for (const auto& p : patients) {
            if (p.getTemperature() > feverThreshold) {
                p.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No patients with fever above " << feverThreshold << "F." << endl;
        }
    }

    double calculateAverageAge() const {
        if (patients.empty()) {
            return 0.0;
        }
        double totalAge = 0;
        for (const auto& p : patients) {
            totalAge += p.getAge();
        }
        return totalAge / patients.size();
    }
};

int main() {
    PatientRegistry registry;

    try {
        registry.addNewPatient(Patient(101, "Alice Smith", 30, 99.5, "Flu"));
        registry.addNewPatient(Patient(102, "Bob Johnson", 45, 101.2, "Fever"));
        registry.addNewPatient(Patient(103, "Charlie Brown", 22, 98.0, "Cold"));
        registry.addNewPatient(Patient(104, "Diana Prince", 50, 100.1, "Migraine"));
        registry.addNewPatient(Patient(105, "Eve Adams", 15, 98.6, "Check-up"));
    } catch (const invalid_argument& e) {
        cerr << "Error adding patient: " << e.what() << endl;
    }

    cout << "--- All Patients ---" << endl;
    registry.displayAllPatients();
    cout << endl;

    cout << "--- Removing Patient 103 ---" << endl;
    registry.removePatientById(103);
    registry.displayAllPatients();
    cout << endl;

    cout << "--- Searching for 'Fever' patient ---" << endl;
    Patient* foundPatient = registry.findPatientByDisease("Fever");
    if (foundPatient) {
        foundPatient->display();
    } else {
        cout << "Patient with 'Fever' not found." << endl;
    }
    cout << endl;

    cout << "--- Patients with Fever (>100F) ---" << endl;
    registry.displayPatientsWithFever();
    cout << endl;

    cout << "--- Patients Sorted by Age ---" << endl;
    registry.sortPatientsByAge();
    registry.displayAllPatients();
    cout << endl;

    cout << "--- Average Age of Patients ---" << endl;
    cout << "Average Age: " << registry.calculateAverageAge() << endl;
    cout << endl;

    return 0;
}