#include <iostream>
using namespace std;

class Node {
public:
    string playerName;
    Node* next;

    Node(string name) {
        playerName = name;
        next = NULL;
    }
};

class GamePlayers {
public:
    Node* head;
    Node* tail;

    GamePlayers() {
        head = NULL;
        tail = NULL;
    }

    void addPlayer(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        tail->next = head; 
    }

    void showTurnsOnce() {
        cout << "\nPlayer turns:\n";
        Node* temp = head;
        do {
            cout << temp->playerName;
            temp = temp->next;
            if (temp != head) cout << " -> ";
        } while (temp != head);

        cout << " -> (back to " << head->playerName << ")" << endl;
    }
};

int main() {
    GamePlayers game;

    game.addPlayer("Ali");
    game.addPlayer("Sara");
    game.addPlayer("Zain");
    game.addPlayer("Ayesha");
    game.addPlayer("Bilal");

    game.showTurnsOnce();

    return 0;
}