
#include <iostream>
using namespace std;

struct Node
{
    int patientID;
    Node* next;
};

Node* head = NULL;

// Add patient at the end
void insert(int id)
{
    Node* newNode = new Node;
    newNode->patientID = id;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// Display waiting patients
void display()
{
    Node* temp = head;

    if (head == NULL)
    {
        cout << "No patients waiting." << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << "P" << temp->patientID;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

// Remove the first patient
void removeFirst()
{
    if (head == NULL)
    {
        cout << "No patient to serve." << endl;
        return;
    }

    Node* temp = head;

    cout << "Patient P" << temp->patientID
         << " is being served." << endl;

    head = head->next;

    delete temp;
}

int main()
{
    int n, id;

    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter Patient ID: ";
        cin >> id;

        insert(id);
    }

    cout << "\nWaiting Patients:" << endl;
    display();

    cout << endl;
    removeFirst();

    cout << "\nUpdated Queue:" << endl;
    display();

    return 0;
}

