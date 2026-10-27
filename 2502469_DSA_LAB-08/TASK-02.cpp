
#include <iostream>
using namespace std;

class BST {
    struct Node {
        int id;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insert(Node* r, int x) {
        if (r == NULL) {
            Node* n = new Node;
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

    bool search(Node* r, int x) {
        if (r == NULL)
            return false;

        if (r->id == x)
            return true;

        if (x < r->id)
            return search(r->left, x);

        return search(r->right, x);
    }

    Node* deleteNode(Node* r, int x) {
        if (r == NULL)
            return NULL;

        if (x < r->id)
            r->left = deleteNode(r->left, x);

        else if (x > r->id)
            r->right = deleteNode(r->right, x);

        else {
            if (r->left == NULL) {
                Node* temp = r->right;
                delete r;
                return temp;
            }

            else if (r->right == NULL) {
                Node* temp = r->left;
                delete r;
                return temp;
            }

            Node* temp = r->right;

            while (temp->left != NULL)
                temp = temp->left;

            r->id = temp->id;
            r->right = deleteNode(r->right, temp->id);
        }

        return r;
    }

    void inorder(Node* r) {
        if (r == NULL)
            return;

        inorder(r->left);
        cout << r->id << " ";
        inorder(r->right);
    }

    void preorder(Node* r) {
        if (r == NULL)
            return;

        cout << r->id << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void postorder(Node* r) {
        if (r == NULL)
            return;

        postorder(r->left);
        postorder(r->right);
        cout << r->id << " ";
    }

    int countNodes(Node* r) {
        if (r == NULL)
            return 0;

        return 1 + countNodes(r->left) + countNodes(r->right);
    }

    int height(Node* r) {
        if (r == NULL)
            return 0;

        int left = height(r->left);
        int right = height(r->right);

        if (left > right)
            return left + 1;
        else
            return right + 1;
    }

    void destroy(Node* r) {
        if (r == NULL)
            return;

        destroy(r->left);
        destroy(r->right);
        delete r;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroy(root);
    }

    void insertID(int x) {
        root = insert(root, x);
    }

    void searchID(int x) {
        if (search(root, x))
            cout << "ID Found!\n";
        else
            cout << "ID Not Found!\n";
    }

    void deleteID(int x) {
        if (!search(root, x)) {
            cout << "ID does not exist!\n";
            return;
        }

        root = deleteNode(root, x);

        cout << "ID deleted successfully!\n";
        cout << "Updated IDs: ";
        inorder(root);
        cout << endl;
    }

    void displayInorder() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }

        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }

        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }

        postorder(root);
        cout << endl;
    }

    void totalNodes() {
        cout << "Total nodes: " << countNodes(root) << endl;
    }

    void treeHeight() {
        cout << "Tree height: " << height(root) << endl;
    }
};

int main() {
    BST t;

    t.insertID(55);
    t.insertID(35);
    t.insertID(75);
    t.insertID(25);
    t.insertID(45);
    t.insertID(65);
    t.insertID(85);
    t.insertID(40);
    t.insertID(50);

    int choice, x;

    do {
        cout << "\n1. Insert ID";
        cout << "\n2. Search ID";
        cout << "\n3. Delete ID";
        cout << "\n4. Inorder Traversal";
        cout << "\n5. Preorder Traversal";
        cout << "\n6. Postorder Traversal";
        cout << "\n7. Count Nodes";
        cout << "\n8. Calculate Height";
        cout << "\n9. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> x;
            t.insertID(x);
            break;

        case 2:
            cout << "Enter ID to search: ";
            cin >> x;
            t.searchID(x);
            break;

        case 3:
            cout << "Enter ID to delete: ";
            cin >> x;
            t.deleteID(x);
            break;

        case 4:
            cout << "Inorder: ";
            t.displayInorder();
            break;

        case 5:
            cout << "Preorder: ";
            t.displayPreorder();
            break;

        case 6:
            cout << "Postorder: ";
            t.displayPostorder();
            break;

        case 7:
            t.totalNodes();
            break;

        case 8:
            t.treeHeight();
            break;

        case 9:
            cout << "Program ended!";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 9);

    return 0;
}
