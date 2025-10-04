// solution.cpp — only function implementations
#include <iostream>
#include <cstring>

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size >= capacity) {
        throw "List full";
    }
    if (name == nullptr || std::strlen(name) == 0) {
        throw "Invalid name.";
    }
    if (gpa < 0.0 || gpa > 4.0) {
        throw "Invalid GPA.";
    }

    std::size_t n = std::strlen(name);
    names[size] = new char[n + 1];
    std::strcpy(names[size], name);
    gpas[size] = gpa;
    ++size;
}

void updateGPA(double* gpaPtr, double newGpa) {
    if (gpaPtr == nullptr) {
        std::cout << "Warning: gpaPtr is nullptr; cannot update.\n";
        return;
    }
    if (newGpa < 0.0 || newGpa > 4.0) {
        std::cout << "Warning: GPA out of range; ignoring.\n";
        return;
    }
    *gpaPtr = newGpa;
}

void printStudent(const char* name, const double& gpa) {
    std::cout << "Student{name=\"" << (name ? name : "(null)")
              << "\", gpa=" << gpa << "}\n";
}

double averageGPA(const double gpas[], int size) {
    if (size == 0) {
 
        throw "No students";
    }
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += gpas[i];
    }
    return sum / size;
}
