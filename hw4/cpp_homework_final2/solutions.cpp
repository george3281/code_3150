
#include <iostream>
#include <cstring>   // for strlen, strcpy
#include <string>    // for std::stoi

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size >= capacity) {
        throw "Error: List full.";
    }
    names[size] = new char[std::strlen(name) + 1];
    std::strcpy(names[size], name);
    gpas[size] = gpa;
    size++;
}

void updateGPA(double* gpaPtr, double newGpa) {
    if (gpaPtr == nullptr) {
        throw "Error: Invalid GPA pointer.";
    }
    *gpaPtr = newGpa;
}

void printStudent(const char* name, const double& gpa) {
    std::cout << "Name: " << name << ", GPA: " << gpa << std::endl;
}

double averageGPA(const double gpas[], int size) {
    if (size == 0) {
        throw "Error: No students to compute average.";
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += gpas[i];
    }
    return sum / static_cast<double>(size);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);

    char** names = new char*[capacity];
    double* gpas = new double[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                char nameBuf[256];
                double gpa;
                std::cin >> nameBuf >> gpa;
                try {
                    addStudent(nameBuf, gpa, names, gpas, size, capacity);
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                int idx;
                double newGpa;
                std::cin >> idx >> newGpa;
                if (idx < 0 || idx >= size) {
                    std::cout << "Error: Invalid index." << std::endl;
                } else {
                    try {
                        updateGPA(&gpas[idx], newGpa);
                    } catch (const char* msg) {
                        std::cout << msg << std::endl;
                    }
                }
                break;
            }
            case 3: {
                if (size == 0) {
                    std::cout << "No students yet." << std::endl;
                } else {
                    for (int i = 0; i < size; i++) {
                        printStudent(names[i], gpas[i]);
                    }
                }
                break;
            }
            case 4: {
                try {
                    double avg = averageGPA(gpas, size);
                    std::cout << "Average GPA: " << avg
                              << " (rounded integer: " << static_cast<int>(avg) << ")" << std::endl;
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    for (int i = 0; i < size; i++) {
        delete[] names[i];
    }
    delete[] names;
    delete[] gpas;

    return 0;
}
