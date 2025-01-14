#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        Node *left;
        Node *right;
        int height;

        Node(int key) {
            this->key = key;
            left = NULL;
            right = NULL;
            height = 1; // Initial height of a new node is 1
        }
};

// Function to get the height of a node
int getHeight(Node* node) {
    return node == NULL ? 0 : node->height;
}

// Function to calculate the balance factor of a node
int getBalance(Node* node) {
    return node == NULL ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Function to perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Function to insert a node into the AVL tree
Node* Insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = Insert(root->left, key);
    } else if (key > root->key) {
        root->right = Insert(root->right, key);
    } else {
        cout << "\nCannot Repeat the Values." << endl;
        return root;
    }

    // Update height of the current node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Check balance factor and perform rotations if needed
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to find the node with the minimum value in a subtree
Node* findMin(Node* root) {
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the AVL tree
Node* Delete(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = Delete(root->left, key);
    } else if (key > root->key) {
        root->right = Delete(root->right, key);
    } else {
        // Node to be deleted found

        // Case 1: No child or one child
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            // Case 2: Node with two children
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = Delete(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    // Update height of the current node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Check balance factor and perform rotations if needed
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Traversals
void Display(Node* root) {
    if (root != NULL) {
        Display(root->left);
        cout << root->key << " ";
        Display(root->right);
    }
}
void DisplayPre(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        DisplayPre(root->left);
        DisplayPre(root->right);
    }
}
void DisplayPost(Node* root) {
    if (root != NULL) {
        DisplayPost(root->left);
        DisplayPost(root->right);
        cout << root->key << " ";
    }
}

int main() {
    Node* root = NULL;

    root = Insert(root, 11);
    root = Insert(root, 12);
    root = Insert(root, 10);
    root = Insert(root, 15);
    root = Insert(root, 17);

    cout << "\nInorder Traversal: ";
    Display(root);
    cout << "\nPreorder Traversal: ";
    DisplayPre(root);
    cout << "\nPostorder Traversal: ";
    DisplayPost(root);

    cout << "\n\nDeleting 15...";
    root = Delete(root, 15);
    cout << "\nAfter Deletion, Inorder Traversal: ";
    Display(root);

    return 0;
}