#ifndef MATRIXCREATION_H
#define MATRIXCREATION_H

#include <vector>
#include <string>

std::vector<std::vector<int>> createSeqMatrix(
    std::string seqOne,
    std::string seqTwo,
    int pGap,
    int pMismatch,
    int match
);

void displaySeqMatrix(
    std::string seqOne,
    std::string seqTwo,
    std::vector<std::vector<int>> seqMatrix
);

void takeInput(
    std::string& seqOne,
    std::string& seqTwo,
    int& match,
    int& pMismatch,
    int& pGap
);

#endif
