#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* next;
};

int main() {

    Node *head = NULL, *temp, *newNode;
    for(int i = 0; i < 4; i++) {
        newNode = new Node;

        cout << "Enter Roll Number: ";
        cin >> newNode->roll;

        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
    cout << "\nRegistered Students: ";

    temp = head;

    while(temp != NULL) {
        cout << temp->roll << " -> ";
        temp = temp->next;
    }

    int search;
    cout << "\nEnter Roll Number to Search: ";
    cin >> search;

    temp = head;

    while(temp != NULL) {
        if(temp->roll == search) {
            cout << "Student Found";
            return 0;
        }

        temp = temp->next;
    }

    cout << "Student Not Found";

    return 0;
}