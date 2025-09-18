// main.cpp — driver with menu
#include <iostream>
#include <string>
#include <cstring>

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>\n";
        return 1;
    }
    int capacity = 0;
    try {
        capacity = std::stoi(argv[1]);
    } catch (...) {
        std::cout << "Invalid capacity. Usage: ./program <capacity>\n";
        return 1;
    }
    if (capacity <= 0) {
        std::cout << "Capacity must be positive.\n";
        return 1;
    }

    char** names = new char*[capacity];
    double* gpas  = new double[capacity];
    for (int i = 0; i < capacity; ++i) { names[i] = nullptr; }
    int size = 0;

    bool running = true;
    while (running) {
        std::cout << "\n=== Menu ===\n"
                  << "1) Add student\n"
                  << "2) Update GPA (by index)\n"
                  << "3) Print all students\n"
                  << "4) Print average GPA (double + rounded int)\n"
                  << "5) Quit\n"
                  << "Choice: ";
        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input.\n";
            continue;
        }
        std::cin.ignore(10000, '\n');

        switch (choice) {
            case 1: {
                std::string sname;
                std::cout << "Enter student name: ";
                std::getline(std::cin, sname);
                double g = 0.0;
                std::cout << "Enter GPA: ";
                if (!(std::cin >> g)) {
                    std::cin.clear(); std::cin.ignore(10000, '\n');
                    std::cout << "Invalid GPA.\n"; break;
                }
                std::cin.ignore(10000, '\n');
                char buffer[256];
                if (sname.size() >= sizeof(buffer)) {
                    std::cout << "Name too long (max 255 chars).\n"; break;
                }
                std::strcpy(buffer, sname.c_str());

                try {
                    addStudent(buffer, g, names, gpas, size, capacity);
                    std::cout << "Added.\n";
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                if (size == 0) { std::cout << "No students yet.\n"; break; }
                std::cout << "Enter index [0.." << (size-1) << "]: ";
                int idx = -1;
                if (!(std::cin >> idx)) {
                    std::cin.clear(); std::cin.ignore(10000, '\n');
                    std::cout << "Invalid index.\n"; break;
                }
                std::cin.ignore(10000, '\n');
                if (idx < 0 || idx >= size) { std::cout << "Out of range.\n"; break; }
                double newG = 0.0;
                std::cout << "Enter new GPA: ";
                if (!(std::cin >> newG)) {
                    std::cin.clear(); std::cin.ignore(10000, '\n');
                    std::cout << "Invalid GPA.\n"; break;
                }
                std::cin.ignore(10000, '\n');
                double* gpaPtr = &gpas[idx];
                updateGPA(gpaPtr, newG);
                std::cout << "Updated.\n";
                break;
            }
            case 3: {
                if (size == 0) { std::cout << "No students.\n"; break; }
                for (int i = 0; i < size; ++i) {
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                try {
                    double avg = averageGPA(gpas, size);
                    int rounded = static_cast<int>(avg + 0.5);
                    std::cout << "Average GPA: " << avg << " (rounded: " << rounded << ")\n";
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 5: {
                running = false;
                break;
            }
            default: {
                std::cout << "Unknown choice.\n";
                break;
            }
        }

        if (running) { std::cout << "Action complete.\n"; }
        else { std::cout << "Exiting...\n"; }
    }

    for (int i = 0; i < capacity; ++i) {
        if (names[i] != nullptr) { delete[] names[i]; names[i] = nullptr; }
    }
    delete[] names;
    delete[] gpas;
    return 0;
}
