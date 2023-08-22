#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string filename;

    cout << "Enter the name of the text file: ";
    cin >> filename;

    ifstream inputFile(filename.c_str());
    
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    int wordCount = 0;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            wordCount++;
        }
    }

    inputFile.close();

    cout << "Total word count in the file: " << wordCount << endl;

    return 0;
}

