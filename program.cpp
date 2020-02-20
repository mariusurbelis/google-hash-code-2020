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
    vector<book> books;
};

// Declaring the variables
int bookTypes, librariesCount, days;

int main () {
    // Declaring the ifstream
    ifstream file;
    // Opening a file
    file.open("input/a_example.txt");

    // Reading in the first line. B, L and D
    file >> bookTypes >> librariesCount >> days;

    // Declaring the score array
    int scores [bookTypes];
    library libraries [librariesCount];

    // Reading in the scores
    for (int i = 0; i < bookTypes; i++) {
        file >> scores[i];
    }

    // Reading in the library book counts
    for (int i = 0; i < librariesCount; i++) {
        file >> libraries[i].bookCount >> libraries[i].signupTime >> libraries[i].canBeScanned;
        cout << libraries[i].bookCount << " ";
    }

    cout << endl << endl;

    for (int l = 0; l < librariesCount; l++) {
        for (int b = 0; b < libraries[l].bookCount; b++) {
            book newBook;
            file >> newBook.id;
            newBook.score = scores[newBook.id];
            libraries[l].books.push_back(newBook);
        }
    }


    // Printing out the variables
    cout << "B: " << bookTypes << " L: " << librariesCount << " D: " << days << endl;

    // Closing the file stream
    file.close();

    // Returning success
    return 0;
}