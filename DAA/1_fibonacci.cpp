#include <iostream>
using namespace std;

long long fibonacciIterative(int n) {
    if (n <= 1) {
        return n;
    }

    long long a = 0;
    long long b = 1;
    long long result = 0;

    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;          
        b = result;     
    }

    return result;
}

long long fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}


int main() {
    int n;

    cout << "  Fibonacci Number Calculator\n";
    cout << "-------------------------------------------\n";
    
    cout << "Enter a non-negative integer: ";
    cin >> n;


    if (n < 0) {
        cout << "Error: Input must be a non-negative integer." << endl;
        return 1;
    }

    // --- Iterative Method Calculation ---
    cout << "\n--- Using Iterative Method ---" << endl;
    long long iterativeResult = fibonacciIterative(n);
    cout << "The Fibonacci number at position " << n << " is: " << iterativeResult << endl;

    // --- Recursive Method Calculation ---
    cout << "\n--- Using Recursive Method ---" << endl;
    long long recursiveResult = fibonacciRecursive(n);
    cout << "The Fibonacci number at position " << n << " is: " << recursiveResult << endl;

    return 0; 
}