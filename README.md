# Needleman-Wunsch Algorithm 🧬

A C++ implementation of the **Needleman-Wunsch algorithm** for global DNA sequence alignment using a dynamic programming approach.

The program takes two DNA sequences along with user-defined scoring parameters and calculates the optimal matching score.

---

## 📌 About the Project

This project implements the Needleman-Wunsch algorithm to perform **global sequence alignment of DNA nucleotides**.

The program:

* Uses dynamic programming to construct the alignment matrix.
* Calculates a matching score for two DNA sequences.
* Performs backtracking to determine the optimal alignment score.
* Allows the user to define the scoring parameters.
* Is split across multiple C++ source files.

---

## 📁 Project Structure

```text
Needleman-Wunsch-Algorithm/
│
├── matrixCreation.cpp
├── backTracking.cpp
├── Input_Examples
├── README.md
└── .gitignore
```

### Files

* **`matrixCreation.cpp`**
  Creates and processes the dynamic programming matrix.

* **`backTracking.cpp`**
  Performs the backtracking process to obtain the final matching score.

* **`Input_Examples`**
  Contains example inputs that can be used to test the program.

---

## ⚙️ Scoring Parameters

The program allows the user to specify three scoring parameters:

| Parameter        | Description                               |
| ---------------- | ----------------------------------------- |
| Match Bonus      | Score awarded when two nucleotides match  |
| Mismatch Penalty | Penalty when two nucleotides do not match |
| Gap Penalty      | Penalty for introducing a gap             |

This allows different scoring schemes to be tested.

---

## 🚀 How to Run

Follow these steps to compile and run the program.

### Step 1: Clone the Repository

Clone the repository using Git:

```bash
git clone https://github.com/YOUR-USERNAME/Needleman-Wunsch-Algorithm.git
```

Then move into the project directory:

```bash
cd Needleman-Wunsch-Algorithm
```

> Replace `YOUR-USERNAME` with your GitHub username.

---

### Step 2: Open the Terminal in the Project Folder

Make sure your terminal is currently inside the `Needleman-Wunsch-Algorithm` folder.

You can check your current directory using:

```bash
pwd
```

---

### Step 3: Compile the Program

The program is divided into two C++ source files:

* `matrixCreation.cpp`
* `backTracking.cpp`

Compile both files together using:

```bash
g++ matrixCreation.cpp backTracking.cpp -o needlemanWunsch
```

This creates an executable named:

```text
needlemanWunsch
```

---

### Step 4: Run the Program

Run the executable using:

```bash
./needlemanWunsch
```

---

### Step 5: Enter the Required Inputs

The program will ask you to enter:

1. The first DNA sequence
2. The second DNA sequence
3. Match bonus
4. Mismatch penalty
5. Gap penalty

Enter the required values when prompted.

---

### Step 6: View the Result

The program calculates the dynamic programming matrix and performs backtracking to produce the final matching score.

---

## 🧪 Input Examples

The repository contains an **`Input_Examples`** file with example inputs that can be used to test the program.

A typical input consists of:

```text
Sequence 1
Sequence 2
Match Bonus
Mismatch Penalty
Gap Penalty
```

You can use these examples to understand the expected input format before running the program with your own sequences.

---

## 🧠 Algorithm

The Needleman-Wunsch algorithm uses **dynamic programming** to find an optimal global alignment between two sequences.

For each cell in the alignment matrix, three possible operations are considered:

1. **Diagonal:** Match or mismatch the two nucleotides.
2. **Up:** Introduce a gap in one sequence.
3. **Left:** Introduce a gap in the other sequence.

The matrix is constructed using the best score among these possibilities.

After the matrix is completed, **backtracking** is performed from the bottom-right cell to determine the optimal alignment path and final score.

---

## ⏱️ Complexity

For two sequences of lengths `m` and `n`:

* **Time Complexity:** `O(m × n)`
* **Space Complexity:** `O(m × n)`

The space complexity is `O(m × n)` because the complete dynamic programming matrix is stored.

---

## ⚠️ Known Limitation

The current implementation does **not fully handle cases where multiple possible backtracking directions have the same score**.

For example, if two or more of the possible moves have equal scores, the current `backTrack` function does not explicitly consider all possible paths.

Therefore, the implementation may not account for all equally optimal alignments in such cases.

The relevant function is located in:

```text
backTracking.cpp
```

Specifically, the `backTrack` function would need to be modified to handle cases where multiple directions have equal scores.

### Possible Future Improvements

* Handle ties between two possible backtracking directions.
* Handle ties between all three possible directions.
* Return all possible optimal alignments instead of only one.
* Improve input validation.
* Separate function declarations into header (`.h`) files.

---

## 🛠️ Technologies

* **C++**
* **Dynamic Programming**
* **Needleman-Wunsch Algorithm**
* **DNA Sequence Alignment**
* **Git & GitHub**

---

## 📚 What I Learned

Through this project, I worked with:

* Dynamic programming
* Two-dimensional matrices
* DNA sequence alignment
* Backtracking
* Multi-file C++ programs
* Compiling multiple C++ source files using `g++`

---

## 👤 Author

**Zaid Irfan Baig**

If you have suggestions for improving the backtracking implementation, feel free to open an issue or contribute to the project.
s
