#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct book {
    int id;
    int score;
};

struct library {
    int signupTime;
    int canBeScanned;
    int bookCount;
};

// Declaring the variables
int bookTypes, libraries, days;

int main () {
    // Declaring the ifstream
    ifstream file;
    // Opening a file
    file.open("input/a_example.txt");

    // Reading in the first line. B, L and D
    file >> bookTypes >> libraries >> days;

    // Printing out the variables
    cout << "B: " << bookTypes << " L: " << libraries << " D: " << days << endl;

    // Closing the file stream
    file.close();

    // Returning success
    return 0;
}