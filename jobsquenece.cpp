#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Define a Node structure to represent a Huffman tree node
class Node {
public:
    int freq;
    std::string symbol;
    Node* left;
    Node* right;
    std::string huff;

    Node(int freq_, std::string symbol_, Node* left_ = nullptr, Node* right_ = nullptr) 
        : freq(freq_), symbol(symbol_), left(left_), right(right_), huff("") {}
};

// Function to print the Huffman code for each symbol
void printNodes(Node* node, std::string val = "") {
    std::string new_val = val + node->huff;
    if (node->left) {
        printNodes(node->left, new_val);
    }
    if (node->right) {
        printNodes(node->right, new_val);
    }
    // Leaf node (no left or right children)
    if (!node->left && !node->right) {
        std::cout << node->symbol << " -> " << new_val << std::endl;
    }
}

int main() {
    std::vector<std::string> chars = {"a", "b", "c", "d", "e", "f"};
    std::vector<int> freq = {10, 4, 9, 7, 1, 15};

    // Create a list of nodes with symbols and frequencies
    std::vector<Node*> nodes;
    for (size_t i = 0; i < chars.size(); ++i) {
        nodes.push_back(new Node(freq[i], chars[i]));
    }

    // Build the Huffman tree
    while (nodes.size() > 1) {
        // Sort nodes based on frequency
        std::sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
            return a->freq < b->freq;
        });

        // Take two nodes with the lowest frequency
        Node* left = nodes[0];
        Node* right = nodes[1];

        // Assign Huffman values
        left->huff = "0";
        right->huff = "1";

        // Create a new internal node with combined frequency
        Node* newNode = new Node(left->freq + right->freq, left->symbol + right->symbol, left, right);

        // Remove the two nodes from the list and add the new node
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());

        nodes.push_back(newNode);
    }

    // Output the characters and their frequencies
    std::cout << "Characters : [";
    for (const auto& ch : chars) {
        std::cout << ch << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Frequency : ";
    for (const auto& f : freq) {
        std::cout << f << " ";
    }
    std::cout << "\n\nHuffman Encoding:\n";

    // Print the Huffman codes
    printNodes(nodes[0]);

    // Clean up the dynamically allocated memory
    for (auto node : nodes) {
        delete node;
    }

    return 0;
}
