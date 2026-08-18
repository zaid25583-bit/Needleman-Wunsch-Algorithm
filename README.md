# Needleman-Wunsch Algorithm 🧬

A C++ implementation of the **Needleman-Wunsch algorithm** for global DNA sequence alignment using a dynamic programming approach.

The program takes two DNA sequences along with user-defined scoring parameters and calculates the optimal matching score.

---

## 📌 About the Project

This project implements the Needleman-Wunsch algorithm to perform **global sequence alignment of DNA nucleotides**.

The program:

- Uses dynamic programming to construct the alignment matrix.
- Calculates a matching score for two DNA sequences.
- Performs backtracking to determine the optimal alignment score.
- Allows the user to define the scoring parameters.

The program is split across multiple C++ files to separate different parts of the implementation.

---

## 📁 Project Structure

```text
Needleman-Wunsch-Algorithm/
│
├── matrixCreation.cpp
├── backTracking.cpp
├── Input_Examples
└── README.md
