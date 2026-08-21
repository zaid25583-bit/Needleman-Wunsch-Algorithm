#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> createSeqMatrix(string seqOne, string seqTwo, int pGap, int pMismatch, int match) {
    int n = seqTwo.size();
    int m = seqOne.size();

    // vector with m + 1 elements each a vector of size n + 1
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1));

    // deal with initial row and column
    int ini = 0;
    for (int i = 0; i < n + 1; i++) {
        matrix[i][0] = ini;
        ini = ini + pGap;
    }

    ini = 0;
    for (int j = 0; j < m + 1; j++) {
        matrix[0][j] = ini;
        ini = ini + pGap;
    }

    //traverse row by row
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            char one = seqOne[j - 1];
            char two = seqTwo[i - 1];

            int val1, val2, val3;
            val2 = matrix[i - 1][j] + pGap;
            val3 = matrix[i][j - 1] + pGap;

            if (one == two) {
                val1 = matrix[i - 1][j - 1] + match;
            }
            else {
                val1 = matrix[i - 1][j - 1] + pMismatch;
            }
            
            int correctPlacement = max(val1, max(val2, val3));
            matrix[i][j] = correctPlacement;
        }
    }
    return matrix;
}

void displaySeqMatrix(string seqOne, string seqTwo, vector<vector<int>> seqMatrix) {
    int m = seqOne.size();
    int n = seqTwo.size();

    cout << endl;

    // Print seqOne along the top
    cout << "\t\t";

    for (int i = 0; i < m; i++) {
        cout << seqOne[i] << "\t";
    }

    cout << endl;

    // Print matrix
    for (int i = 0; i < n + 1; i++) {

        cout << endl;

        // Print seqTwo character on the left
        if (i == 0) {
            cout << "\t";
        } else {
            cout << seqTwo[i - 1] << "\t";
        }

        for (int j = 0; j < m + 1; j++) {
            cout << seqMatrix[i][j] << "\t";
        }

        cout << endl;
    }
}


void takeInput(string& seqOne, string& seqTwo, int& match, int& pMismatch, int& pGap) {
    cout << "First Sequence: ";
    cin >> seqOne;

    cout << "Second Sequence: ";
    cin >> seqTwo;

    cout << "Enter match bonus: ";
    cin >> match;

    cout << "Enter mismatch penalty: ";
    cin >> pMismatch;

    cout << "Enter gap penalty: ";
    cin >> pGap;
}
