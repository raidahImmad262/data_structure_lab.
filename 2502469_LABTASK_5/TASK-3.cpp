#include <iostream>
using namespace std;
class Node {
public:
    string name;
    Node* prev;
    Node* next;
    Node(string n) {
        name = n;
        prev = NULL;
        next = NULL;
    }
};
int main() {
    string images[5] = {"Sunset", "Mountains", "Beach", "Forest", "City"};
    Node* head = NULL;
    Node* tail = NULL;

    
    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(images[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
    }

    
    cout << "Forward: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->name << " ";
        temp = temp->next;
    }

    
    cout << "\nBackward: ";
    temp = tail;
    while (temp != NULL) {
        cout << temp->name << " ";
        temp = temp->prev;
    }

    return 0;
}