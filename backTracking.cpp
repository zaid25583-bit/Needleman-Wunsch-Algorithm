#include <iostream>
#include <string>
#include <vector>
#include "matrixCreation.h"

using namespace std;


int backTrack(vector<vector<int>> seqMatrix, string seqOne, string seqTwo, int match, int pMismatch, int pGap) {
    int i, j;
    i = seqTwo.size();
    j = seqOne.size();
    int score = 0;

    while (i > 0 && j > 0) {
        int scoreUp = seqMatrix[i - 1][j];
        int scoreLeft = seqMatrix[i][j - 1];
        int scoreDiag = seqMatrix[i - 1][j - 1];

        char nucleotideOne = seqOne[j - 1];
        char nucleotideTwo = seqTwo[i - 1];

        int remLeft, remDiag;
        int matchingNucleotide;
        if (nucleotideOne == nucleotideTwo) {
            remDiag = scoreDiag + match;
            matchingNucleotide = 1;
        }
        else {
            remDiag = scoreDiag + pMismatch;
            matchingNucleotide = 0;
        }
        remLeft = scoreLeft + pGap;

        if (remDiag == seqMatrix[i][j]) {
            i--;
            j--;
            if (matchingNucleotide) {
                score += match;
            }
            else {
                score += pMismatch;
            }
        }
        else if (remLeft == seqMatrix[i][j]) {
            score += pGap;
            j--;
        }
        else {
            score += pGap;
            i--;
        }
    }
    
    if (i > 0) {
        score += pGap * i;
    }
    if (j > 0) {
        score += pGap * j;
    }

    return score;
}

int main() {
    string seqOne, seqTwo;
    int pGap, pMismatch, match;

    takeInput(seqOne, seqTwo, match, pMismatch, pGap);

    //initialize matrix
    int m = seqOne.size();
    int n = seqTwo.size();

    vector<vector<int>> seqMatrix(n + 1, vector<int>(m + 1));
    seqMatrix = createSeqMatrix(seqOne, seqTwo, pGap, pMismatch, match);
    
    int score = backTrack(seqMatrix, seqOne, seqTwo, match, pMismatch, pGap);
    cout << endl;
    cout << "The score final score is: " << score << endl;
    return 0;
}
