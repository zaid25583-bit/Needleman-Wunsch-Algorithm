#include <iostream>
#include <string>
#include <vector>
#include "matrixCreation.h"

using namespace std;

void recursion(
            vector<vector<int>> seqMatrix,
            string seqOne,
            string seqTwo,
            int match,
            int pMismatch,
            int pGap,
            string currStringOne,
            string currStringTwo,
            int currIdxSeqOne,
            int currIdxSeqTwo,
            vector<vector<string>>& alignedSequences) 
{
    if (currIdxSeqOne == 0 && currIdxSeqTwo == 0) {
        vector<string> curr = {currStringOne, currStringTwo};
        alignedSequences.push_back(curr);
        return;
    }

    if (currIdxSeqTwo == 0) {
        while (currIdxSeqOne > 0) {
            currStringOne = seqOne[currIdxSeqOne - 1] + currStringOne;
            currStringTwo = "_" + currStringTwo;
            currIdxSeqOne--;
        }

        alignedSequences.push_back({currStringOne, currStringTwo});
        return;
    }
    
    if (currIdxSeqOne == 0) {
        while (currIdxSeqTwo > 0) {
            currStringOne = "_" + currStringOne;
            currStringTwo = seqTwo[currIdxSeqTwo - 1] + currStringTwo;
            currIdxSeqTwo--;
        }

        alignedSequences.push_back({currStringOne, currStringTwo});
        return;
    }

    char topChar = seqOne[currIdxSeqOne - 1];
    char leftChar = seqTwo[currIdxSeqTwo - 1];

    int remDiag = seqMatrix[currIdxSeqTwo - 1][currIdxSeqOne - 1];
    int remLeft = seqMatrix[currIdxSeqTwo][currIdxSeqOne - 1] + pGap;
    int remUp = seqMatrix[currIdxSeqTwo - 1][currIdxSeqOne] + pGap;

    if (topChar == leftChar) {
        remDiag += match;
    }
    else {
        remDiag += pMismatch;
    }

    // use recursion now using by checking cases
    int currRem = seqMatrix[currIdxSeqTwo][currIdxSeqOne];

    if (remDiag == currRem) {
        string newStringOne = seqOne[currIdxSeqOne - 1] + currStringOne;
        string newStringTwo = seqTwo[currIdxSeqTwo - 1] + currStringTwo;

        recursion(
            seqMatrix, seqOne, seqTwo,
            match, pMismatch, pGap,
            newStringOne, newStringTwo,
            currIdxSeqOne - 1, currIdxSeqTwo - 1,
            alignedSequences
        );
    }

    if (remUp == currRem) {
        string newStringOne = "_" + currStringOne;
        string newStringTwo = seqTwo[currIdxSeqTwo - 1] + currStringTwo;

        recursion(
            seqMatrix, seqOne, seqTwo,
            match, pMismatch, pGap,
            newStringOne, newStringTwo,
            currIdxSeqOne, currIdxSeqTwo - 1,
            alignedSequences
        );
    }

    if (remLeft == currRem) {
        string newStringOne = seqOne[currIdxSeqOne - 1] + currStringOne;
        string newStringTwo = "_" + currStringTwo;

        recursion(
            seqMatrix, seqOne, seqTwo,
            match, pMismatch, pGap,
            newStringOne, newStringTwo,
            currIdxSeqOne - 1, currIdxSeqTwo,
            alignedSequences
        );
    }
}

void printPossibleAlignments(vector<vector<string>> alignedSequences) {
    int count = 1;

    for (vector<string> alignment : alignedSequences) {
        cout << "Alignment " << count << ":" << endl;

        for (string sequence : alignment) {
            cout << sequence << endl;
        }

        cout << endl;
        count++;
    }
}

void printScore(vector<string> curr, int match, int pMismatch, int pGap) {
    int score = 0;
    string arrangementOne = curr[0];
    string arrangementTwo = curr[1];
    int n = arrangementOne.size();
    for (int i = 0; i < n; i++) {
        if (arrangementOne[i] == '_' || arrangementTwo[i] == '_') {
            score += pGap;
        }
        else if (arrangementOne[i] == arrangementTwo[i]) {
            score += match;
        }
        else {
            score += pMismatch;
        }
    }

    cout << "Matching score: " << score << endl;
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

    displaySeqMatrix(seqOne, seqTwo, seqMatrix);
    
    string currStringOne;
    string currStringTwo;
    int currIdxSeqOne = m;
    int currIdxSeqTwo = n;
    vector<vector<string>> alignedSequences;

    recursion(seqMatrix, seqOne, seqTwo, match, pMismatch, pGap, currStringOne, currStringTwo, currIdxSeqOne, currIdxSeqTwo, alignedSequences);
    printPossibleAlignments(alignedSequences);

    printScore(alignedSequences[0], match, pMismatch, pGap);
    return 0;
}
