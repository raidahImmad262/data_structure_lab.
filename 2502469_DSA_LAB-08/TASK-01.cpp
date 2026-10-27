
#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = right = NULL;
    }
};

void displayTree(Node* root) {
    if (root == NULL)
        return;

    cout << root->name << " | Left: ";

    if (root->left != NULL)
        cout << root->left->name;
    else
        cout << "NULL";

    cout << " | Right: ";

    if (root->right != NULL)
        cout << root->right->name;
    else
        cout << "NULL";

    cout << endl;

    displayTree(root->left);
    displayTree(root->right);
}

class BST {
    struct BNode {
        int id;
        BNode* left;
        BNode* right;
    };

    BNode* root;

    BNode* insert(BNode* r, int x) {
        if (r == NULL) {
            BNode* n = new BNode;
            n->id = x;
            n->left = n->right = NULL;
            return n;
        }

        if (x < r->id)
            r->left = insert(r->left, x);
        else if (x > r->id)
            r->right = insert(r->right, x);
        else
            cout << "Duplicate ID!\n";

        return r;
    }

    bool search(BNode* r, int x, int &count) {
        if (r == NULL)
            return false;

        count++;

        if (r->id == x)
            return true;

        if (x < r->id)
            return search(r->left, x, count);

        return search(r->right, x, count);
    }

    BNode* deleteNode(BNode* r, int x) {
        if (r == NULL)
            return NULL;

        if (x < r->id)
            r->left = deleteNode(r->left, x);

        else if (x > r->id)
            r->right = deleteNode(r->right, x);

        else {
            if (r->left == NULL) {
                BNode* temp = r->right;
                delete r;
                return temp;
            }

            else if (r->right == NULL) {
                BNode* temp = r->left;
                delete r;
                return temp;
            }

            BNode* temp = r->right;

            while (temp->left != NULL)
                temp = temp->left;

            r->id = temp->id;
            r->right = deleteNode(r->right, temp->id);
        }

        return r;
    }

    void inorder(BNode* r) {
        if (r == NULL)
            return;

        inorder(r->left);
        cout << r->id << " ";
        inorder(r->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insertID(int x) {
        root = insert(root, x);
    }

    void searchID(int x) {
        int count = 0;

        if (search(root, x, count))
            cout << "ID Found ";
        else
            cout << "ID Not Found ";

        cout << "| Visits: " << count << endl;
    }

    void deleteID(int x) {
        root = deleteNode(root, x);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

void original(BST &t) {
    t.insertID(48);
    t.insertID(28);
    t.insertID(68);
    t.insertID(18);
    t.insertID(38);
    t.insertID(58);
    t.insertID(78);
}

int main() {
    cout << "GENERAL BINARY TREE\n";

    Node* root = new Node("Ali");
    root->left = new Node("Ahmed");
    root->right = new Node("Sara");
    root->left->left = new Node("Usman");
    root->left->right = new Node("Ayesha");
    root->right->left = new Node("Zain");
    root->right->right = new Node("Hina");

    displayTree(root);

    cout << "\nBINARY SEARCH TREE\n";

    BST t;
    original(t);

    cout << "Initial IDs: ";
    t.display();

    int x;

    cout << "Enter 3 IDs: ";
    for (int i = 0; i < 3; i++) {
        cin >> x;
        t.insertID(x);
    }

    cout << "After insertion: ";
    t.display();

    cout << "\nSEARCH:\n";
    t.searchID(48);
    t.searchID(100);
    t.searchID(5);

    cout << "Enter ID to search: ";
    cin >> x;
    t.searchID(x);

    cout << "\nEnter ID to delete: ";
    cin >> x;
    t.deleteID(x);

    cout << "After deletion: ";
    t.display();

    BST a, b, c;

    original(a);
    a.deleteID(18);
    cout << "Leaf deletion (18): ";
    a.display();

    original(b);
    b.deleteID(28);
    cout << "One child deletion (28): ";
    b.display();

    original(c);
    c.deleteID(48);
    cout << "Two children deletion (48): ";
    c.display();

    return 0;
}
