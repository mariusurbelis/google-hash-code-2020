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
    bool signedUp = false;
    int signupTime;
    int canBeScanned;
    int bookCount;
    vector<book> books;
};

vector<book> scannedBooks;

// Declaring the variables
int bookTypes, librariesCount, days;

int main () {
    // Declaring the ifstream
    ifstream file;
    // Opening a file
    file.open("input/a_example.txt");
    // file.open("input/b_read_on.txt");

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

        for (int b = 0; b < libraries[i].bookCount; b++) {
            book newBook;
            file >> newBook.id;

            newBook.score = scores[newBook.id];
            libraries[i].books.push_back(newBook);
        }
    }

    int libraryIterator = 0;

    ofstream results;
    results.open("./results/a.txt");

    // The main days loop
    for (int i = 0; i < days; i++) {
        // Scan the books
        for (int s = 0; s < librariesCount; s++) {
            if (libraries[s].signedUp) {
                for (int s = 0; s < libraries[s].canBeScanned; s++) {
                    if (libraries[s].books.size() > 0) {
                        book scanningBook = libraries[s].books.back();
                        libraries[s].books.pop_back();
                        cout << "Day " << i+1 << ". Scanned book id:" << scanningBook.id << " score:" << scanningBook.score << endl; 
                        scannedBooks.push_back(scanningBook);
                    }
                }
            }
        }
        
        if (libraries[libraryIterator].signupTime > 0) {
            cout << "Day " << i+1 << ". Library " << libraryIterator << " time is " << libraries[libraryIterator].signupTime << endl;
            libraries[libraryIterator].signupTime --;
        } else {
            libraries[libraryIterator].signedUp = true;
            libraryIterator++;
        }
    }

    cout << endl << endl;

    for (book b : scannedBooks) {
        cout << "Scanned ID: " << b.id << ", score: " << b.score << endl;
    }

    results << "Hi" << endl;


    // Closing the file stream
    file.close();
    results.close();

    // Returning success
    return 0;
}