#include <iostream>
using namespace std;

class AVLTree {
public:
    struct Node {
        int value;
        int height;
        Node* left;
        Node* right;

        Node(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
    };

    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    int findMinGreaterOrEqual(int value) {
        Node* result = findMinGreaterOrEqual(root, value);
        if (result) {
            return result->value;
        }
        return -1;  // If no such element exists
    }

    int findMaxSmallerOrEqual(int value) {
        Node* result = findMaxSmallerOrEqual(root, value);
        if (result) {
            return result->value;
        }
        return -1;  // If no such element exists
    }

private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        if (balance > 1 && value < node->left->value) {
            return rightRotate(node);
        }

        if (balance < -1 && value > node->right->value) {
            return leftRotate(node);
        }

        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (!node) return node;

        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = minValueNode(node->right);
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->value);
            }
        }

        if (!node) return node;

        updateHeight(node);

        int balance = balanceFactor(node);

        if (balance > 1 && balanceFactor(node->left) >= 0) {
            return rightRotate(node);
        }

        if (balance > 1 && balanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && balanceFactor(node->right) <= 0) {
            return leftRotate(node);
        }

        if (balance < -1 && balanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    Node* findMinGreaterOrEqual(Node* node, int value) {
        Node* result = nullptr;
        while (node) {
            if (node->value >= value) {
                result = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return result;
    }

    Node* findMaxSmallerOrEqual(Node* node, int value) {
        Node* result = nullptr;
        while (node) {
            if (node->value <= value) {
                result = node;
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return result;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
};

int main() {
    AVLTree tree;

    int values[] = {30, 20, 10, 5, 15, 25, 40, 50, 35, 45};
    for (int value : values) {
        tree.insert(value);
    }

    cout << "In-order traversal of AVL Tree after insertion: ";
    tree.inorder();

    cout << "Smallest element greater than or equal to 15: " 
         << tree.findMinGreaterOrEqual(15) << endl;
    
    cout << "Largest element smaller than or equal to 35: " 
         << tree.findMaxSmallerOrEqual(35) << endl;

    cout << "Smallest element greater than or equal to 50: " 
         << tree.findMinGreaterOrEqual(50) << endl;
    
    cout << "Largest element smaller than or equal to 5: " 
         << tree.findMaxSmallerOrEqual(5) << endl;

    cout << "Smallest element greater than or equal to 27: " 
         << tree.findMinGreaterOrEqual(27) << endl;

    cout << "Largest element smaller than or equal to 10: " 
         << tree.findMaxSmallerOrEqual(10) << endl;

    return 0;
}
