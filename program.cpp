#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Structure for a book
struct book {
    int id;
    int score;
};

// Structure for a library
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

    // Declaring the score array
    int scores [bookTypes];

    // Reading in the scores
    for (int i = 0; i < bookTypes; i++) {
        file >> scores[i];
    }

    // Printing out the variables
    cout << "B: " << bookTypes << " L: " << libraries << " D: " << days << endl;

    // Closing the file stream
    file.close();

    // Returning success
    return 0;
}