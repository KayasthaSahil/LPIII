#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getinput() {
    int n;
    cout << "Enter number of Queens (N): ";
    cin >> n;
    return n;
}

void Print(const vector<int> &board, int N) {
    cout << "\nSolution:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) cout << " Q ";
            else               cout << " . ";
        }
        cout << '\n';
    }
}

// Check (row, col) against *all* already placed queens.
// This is important because one queen is pre-placed and may be in a future row.
bool isSafe(const vector<int> &board, int row, int col) {
    int N = (int)board.size();
    for (int i = 0; i < N; i++) {
        if (board[i] == -1 || i == row) continue;
        int c = board[i];
        if (c == col || abs(c - col) == abs(i - row)) return false;
    }
    return true;
}

// Backtracking with a fixed row (fixedRow) already set.
bool SolveBacktracking(vector<int> &board, int row, int N, int fixedRow) {
    if (row == N) {
        Print(board, N);
        return true;
    }

    //Skip the fixed row; it's already set.
    if (row == fixedRow) {
        return SolveBacktracking(board, row + 1, N, fixedRow);
    }

    bool found = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            found = SolveBacktracking(board, row + 1, N, fixedRow) || found;
            board[row] = -1; // backtrack
        }
    }
    return found;
}

int main() {
    int N = getinput();

    int r1, c1; // 1-indexed input for user convenience
    cout << "Enter position of the first Queen (row col) [1-indexed]: ";
    cin >> r1 >> c1;

    // Convert to 0-indexed and validate
    int fixedRow = r1 - 1, fixedCol = c1 - 1;
    if (N <= 0 || fixedRow < 0 || fixedRow >= N || fixedCol < 0 || fixedCol >= N) {
        cout << "Invalid input.\n";
        return 0;
    }

    cout << "\nSolving using backtracking with first queen fixed at ("
         << r1 << ", " << c1 << "):\n";

    vector<int> board(N, -1);
    board[fixedRow] = fixedCol;

    if (!SolveBacktracking(board, 0, N, fixedRow)) {
        cout << "No solution found.\n";
    }

    return 0;
}