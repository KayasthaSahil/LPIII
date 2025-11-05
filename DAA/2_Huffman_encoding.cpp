
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct MinHeapNode {
    char data;          
    unsigned freq;     
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode* root, string str) {
    if (!root) {
        return;
    }

    if (root->data != '$') { 
        cout << "  " << root->data << "   | " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}


void HuffmanCodes(const string& text) {
    map<char, unsigned> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (auto pair : freqMap) {
        minHeap.push(new MinHeapNode(pair.first, pair.second));
    }


    MinHeapNode *left, *right, *top;
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    cout << "---------------------\n";
    cout << " Char | Huffman Code\n";
    cout << "---------------------\n";
    printCodes(minHeap.top(), "");
}

int main() {
    string text;
    
    cout << "--------------------------------\n";
    cout << "  Huffman Encoding Program\n";
    cout << "--------------------------------\n";
    cout << "Enter a string to encode: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Input string is empty. Nothing to encode." << endl;
        return 1;
    }

    HuffmanCodes(text);

    return 0;
}
