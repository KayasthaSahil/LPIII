#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip> 
using namespace std; 

struct Item {
    int value;
    int weight;
};

bool compareItems(const Item& a, const Item& b) {
    double ratio_a = static_cast<double>(a.value) / a.weight;
    double ratio_b = static_cast<double>(b.value) / b.weight;
    return ratio_a > ratio_b;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);

    double finalValue = 0.0;
    int currentWeight = 0;

    cout << "\n--- Knapsack Filling Process ---" << endl;

    for (const auto& item : items) {
        if (currentWeight == W) {
            break;
        }

        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            finalValue += item.value;
            cout << "-> Took entire item with Value: " << item.value
                      << ", Weight: " << item.weight << endl;
        } else {
            int remainingWeight = W - currentWeight;
            double valueOfFraction = item.value * (static_cast<double>(remainingWeight) / item.weight);
            finalValue += valueOfFraction;
            currentWeight += remainingWeight;
            cout << "-> Took a fraction of item with Value: " << item.value
                      << ", Weight: " << item.weight << " (Fractional Value: " << valueOfFraction << ")" << endl;
        }
    }

    return finalValue;
}

int main() {
    int n; 
    int capacity; 

    cout << "-------------------------------------------\n";
    cout << "  Fractional Knapsack Problem Solver\n";
    cout << "-------------------------------------------\n";

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the total capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter the value and weight for each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << " (Value Weight): ";
        cin >> items[i].value >> items[i].weight;
        if (items[i].weight <= 0) {
            cout << "Error: Weight must be positive. Please try again." << endl;
            --i;
        }
    }

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "\n-------------------------------------------\n";
    cout << "Maximum value in knapsack = "
              << fixed << setprecision(2) << maxValue << endl;
    cout << "-------------------------------------------\n";

    return 0;
}
