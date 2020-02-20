#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Structure for a book
struct book {
    long id;
    long score;
};

// Structure for a library
struct library {
    bool signedUp = false;
    long signedUpNumber;
    long signupTime;
    long canBeScanned;
    long bookCount;
    vector<book> books;
    vector<book> scannedBooks;
};

long fileID = 5;
string inputFileName [] = {"input/a_example.txt", "input/b_read_on.txt", "input/c_incunabula.txt", "input/d_tough_choices.txt", "input/e_so_many_books.txt", "input/f_libraries_of_the_world.txt"};
string outputFileName [] = {"results/a.txt", "results/b.txt", "results/c.txt", "results/d.txt", "results/e.txt", "results/f.txt"};

// Declaring the variables
long bookTypes, librariesCount, days;

int main () {
    // Declaring the ifstream
    ifstream file;
    // Opening a file
    file.open(inputFileName[fileID]);
    // file.open("input/b_read_on.txt");

    // Reading in the first line. B, L and D
    file >> bookTypes >> librariesCount >> days;

    // Declaring the score array
    long scores [bookTypes];
    library libraries [librariesCount];

    // Reading in the scores
    for (long i = 0; i < bookTypes; i++) {
        file >> scores[i];
    }

    // Reading in the library book counts
    for (long i = 0; i < librariesCount; i++) {
        file >> libraries[i].bookCount >> libraries[i].signupTime >> libraries[i].canBeScanned;

        for (long b = 0; b < libraries[i].bookCount; b++) {
            book newBook;
            file >> newBook.id;
            newBook.score = scores[newBook.id];
            libraries[i].books.push_back(newBook);
        }
    }

    long libraryIterator = 0;

    ofstream results;
    results.open(outputFileName[fileID]);

    cout << "Simulation start: " << endl;
    // The main days loop
    for (long i = 0; i < days; i++) {
        // Scan the books
        for (long s = 0; s < librariesCount; s++) {
            if (libraries[s].signedUp) {
                for (long c = 0; c < libraries[s].canBeScanned; c++) {
                    if (libraries[s].books.size() > 0) {
                        book scanningBook = libraries[s].books.back();
                        libraries[s].books.pop_back();
                        // cout << "Day " << i+1 << " lib:" << s << ". Scanned book id:" << scanningBook.id << " score:" << scanningBook.score << endl; 
                        libraries[s].scannedBooks.push_back(scanningBook);
                    }
                }
            }
        }
        
        if (libraries[libraryIterator].signupTime > 0) {
            // cout << "Day " << i+1 << ". Library " << libraryIterator << " time is " << libraries[libraryIterator].signupTime << endl;
            libraries[libraryIterator].signupTime --;
        } else {
            libraries[libraryIterator].signedUp = true;
            libraries[libraryIterator].signedUpNumber = libraryIterator;
            libraryIterator++;
        }
    }

    cout << "Simulation end" << endl << endl;

    // Outputting the results to a result file
    long howManyScanned = 0;

    for (long i = 0; i < librariesCount; i++) {
        if (libraries[i].signedUp) {
            howManyScanned ++;
        }
    }

    results << howManyScanned << endl;

    for (long i = 0; i < howManyScanned; i++) {
        for (long libs = 0; libs < librariesCount; libs++) {
            if (libraries[libs].signedUpNumber == i) {
                results << libs << " " << libraries[libs].scannedBooks.size() << endl;

                for (long b = 0; b < (long)libraries[libs].scannedBooks.size(); b++) {
                    results << libraries[libs].scannedBooks[b].id << " ";
                }

                results << endl;

                break;
            }
        }
    }

    // Closing the file streams
    file.close();
    results.close();

    // Returning success
    return 0;
}