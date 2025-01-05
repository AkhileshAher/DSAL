#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int bf;
    Node* left;
    Node* right;
    Node* root;

    Node() {
        root = NULL;
    }

    Node* insert(int data, int* c_flag);
    Node* create(Node* root, int data, int* c_flag);
    void display(Node* root);
};

Node* Node::insert(int data, int* c_flag) {
    root = create(root, data, c_flag);
    return root;
}

Node* Node::create(Node* root, int data, int* c_flag) {
    Node *t1, *t2;

    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->bf = 0;
        *c_flag = 1;
        return root;
    }

    if (data < root->data) {
        root->left = create(root->left, data, c_flag);

        if (*c_flag == 1) {
            switch (root->bf) {
                case -1:
                    root->bf = 0;
                    *c_flag = 0;
                    break;
                case 0:
                    root->bf = 1;
                    break;
                case 1:
                    t1 = root->left;
                    if (t1->bf == 1) {
                        cout << "\nLL Rotation";
                        root->left = t1->right;
                        t1->right = root;
                        root->bf = 0;
                        root = t1;
                    } else {
                        cout << "\nLR Rotation";
                        t2 = t1->right;
                        t1->right = t2->left;
                        t2->left = t1;
                        root->left = t2->right;
                        t2->right = root;

                        root->bf = (t2->bf == 1) ? -1 : 0;
                        t1->bf = (t2->bf == -1) ? 1 : 0;
                        root = t2;
                    }
                    *c_flag = 0;
                    break;
            }
        }
    } else if (data > root->data) {
        root->right = create(root->right, data, c_flag);

        if (*c_flag == 1) {
            switch (root->bf) {
                case 1:
                    root->bf = 0;
                    *c_flag = 0;
                    break;
                case 0:
                    root->bf = -1;
                    break;
                case -1:
                    t1 = root->right;
                    if (t1->bf == -1) {
                        cout << "\nRR Rotation";
                        root->right = t1->left;
                        t1->left = root;
                        root->bf = 0;
                        root = t1;
                    } else {
                        cout << "\nRL Rotation";
                        t2 = t1->left;
                        t1->left = t2->right;
                        t2->right = t1;
                        root->right = t2->left;
                        t2->left = root;

                        root->bf = (t2->bf == -1) ? 1 : 0;
                        t1->bf = (t2->bf == 1) ? -1 : 0;
                        root = t2;
                    }
                    *c_flag = 0;
                    break;
            }
        }
    }

    return root;
}

void Node::display(Node* root) {
    if (root != NULL) {
        display(root->left);
        cout << root->data << "\t";
        display(root->right);
    }
}

int main() {
    Node t;
    Node* root = nullptr;
    int data;
    char ch;
    int c_flag = 0;

    do {
        cout << "\nEnter data: ";
        cin >> data;
        root = t.insert(data, &c_flag);
        cout << "\n\nAVL TREE:\n";
        t.display(root);
        cout << "\n\nDo you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
