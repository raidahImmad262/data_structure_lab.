#include <iostream>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    Node* head;
    Node* tail;

    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    void addSite(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void showForward() {
        cout << "\nHistory (first -> last visited):\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->website << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void showBackward() {
        cout << "\nHistory (last -> first visited):\n";
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->website << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    BrowserHistory history;

    history.addSite("Google");
    history.addSite("YouTube");
    history.addSite("Facebook");
    history.addSite("Instagram");
    history.addSite("GitHub");

    history.showForward();
    history.showBackward();

    return 0;
}