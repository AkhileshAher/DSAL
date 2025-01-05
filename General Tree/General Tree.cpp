#include <iostream>
#include <string>
using namespace std;

// Structure representing a node in the tree
struct Node {
    string name;
    int count; // Number of child nodes
    Node* child[10]; // Array of pointers to child nodes
};

// Class representing the tree
class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {} // Constructor initializes root to NULL
    ~Tree() { deleteTree(root); } // Destructor to free memory

    void createTree();
    void displayTree();
    void deleteTree(Node* node);

private:
    void displayNode(Node* node, int depth);
};

// Function to delete the tree and free memory
void Tree::deleteTree(Node* node) {
    if (node == nullptr) return;
    for (int i = 0; i < node->count; i++) {
        deleteTree(node->child[i]);
    }
    delete node;
}

// Function to create the tree
void Tree::createTree() {
    root = new Node;
    cout << "Enter the name of the book: ";
    cin.ignore(); // Ignore leftover newline
    getline(cin, root->name);
    cout << "Enter the number of chapters in the book: ";
    cin >> root->count;

    for (int i = 0; i < root->count; i++) {
        root->child[i] = new Node;
        cout << "\tEnter the name of chapter " << i + 1 << ": ";
        cin.ignore(); // Ignore leftover newline
        getline(cin, root->child[i]->name);
        cout << "\tEnter the number of sections in chapter " << root->child[i]->name << ": ";
        cin >> root->child[i]->count;

        for (int j = 0; j < root->child[i]->count; j++) {
            root->child[i]->child[j] = new Node;
            cout << "\t\tEnter the name of section " << j + 1 << ": ";
            cin.ignore(); // Ignore leftover newline
            getline(cin, root->child[i]->child[j]->name);
        }
    }
}

// Function to display the tree
void Tree::displayTree() {
    if (root == nullptr) {
        cout << "Tree is empty. Create the tree first.\n";
        return;
    }

    cout << "\n\n================ Index =================\n\n";
    displayNode(root, 0);
}

// Recursive helper function to display a node and its children
void Tree::displayNode(Node* node, int depth) {
    if (node == nullptr) return;

    for (int i = 0; i < depth; i++) {
        cout << "\t";
    }
    cout << node->name << endl;

    for (int i = 0; i < node->count; i++) {
        displayNode(node->child[i], depth + 1);
    }
}

// Main function
int main() {
    Tree t;
    int choice;

    while (true) {
        cout << "\n1. Create tree\n";
        cout << "2. Display tree\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t.createTree();
                break;
            case 2:
                t.displayTree();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
