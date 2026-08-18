#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <vector>
#include <string>

int backTrack (
  const std::vector<std::vector<int>> seqMatrix,
  const std::string seqOne,
  const std::string seqTwo, 
  int match,
  int pMismatch,
  int pGap,
  int temp
);

#endif
