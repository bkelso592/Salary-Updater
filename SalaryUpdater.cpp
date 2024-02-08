#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Employee {
    string lastName;
    string firstName;
    double currentSalary;
    double percentPayIncrease;
};

int main() {
    // Define data for three employees
    Employee employees[3] = {
        {"Miller", "Andrew", 65789.87, 5},
        {"Green", "Sheila", 75892.56, 6},
        {"Sethi", "Amit", 74900.50, 6.1}
    };

    // Open output file
    ofstream outputFile("SalaryOut.txt");
    if (!outputFile) {
        cerr << "Error creating output file SalaryOut.txt";
        return 1;
    }

    // Process data and write to output file
    for (int i = 0; i < 3; ++i) {
        // Calculate updated salary
        double updatedSalary = employees[i].currentSalary * (1 + employees[i].percentPayIncrease / 100);

        // Write output to output file
        outputFile << fixed << setprecision(2);
        outputFile << employees[i].firstName << " " << employees[i].lastName << " " << updatedSalary << endl;
    }

    // Close output file
    outputFile.close();

    cout << "Data processed and stored in SalaryOut.txt successfully." << endl;

    return 0;
}\
