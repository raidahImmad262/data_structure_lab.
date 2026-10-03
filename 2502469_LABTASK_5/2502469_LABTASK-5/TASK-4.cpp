#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node(string n) {
        name = n;
        next = NULL;
    }
};

int main() {
    string songs[5] = {"Blinding Lights", "Shape of You", "Believer", "Perfect", "Faded"};
    Node* head = NULL;
    Node* tail = NULL;

    
    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(songs[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    tail->next = head; 

    
    Node* temp = head;
    for (int i = 0; i < 10; i++) {
        cout << temp->name << " ";
        temp = temp->next;
    }

    return 0;
}