# Needleman–Wunsch DNA Sequence Alignment

A C++ implementation of the Needleman–Wunsch algorithm for finding the optimal **global alignment** between two DNA sequences using dynamic programming.

---

## 🧬 About the Project

The Needleman–Wunsch algorithm is a dynamic programming algorithm used for global sequence alignment.

This project:

- Takes two DNA sequences as input
- Constructs the dynamic programming scoring matrix
- Performs traceback to find the optimal alignment
- Calculates the final alignment score

---

## 📁 Project Structure

```text
needleman-wunsch/
├── src/
│   ├── main.cpp
│   ├── needleman_wunsch.cpp
│   └── needleman_wunsch.h
├── data/
│   └── sequences.txt
├── README.md
└── .gitignore
