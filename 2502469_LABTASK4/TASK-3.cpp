
#include <iostream>
using namespace std;

struct Node
{
    int productID;
    Node* next;
};

Node* head = NULL;
void insert(int id)
{
    Node* newNode = new Node;
    newNode->productID = id;
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

void display()
{
    Node* temp = head;

    if (head == NULL)
    {
        cout << "Shopping cart is empty." << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << "P" << temp->productID;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

void removeProduct(int id)
{
    if (head == NULL)
    {
        cout << "Shopping cart is empty." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->productID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Product not found." << endl;
        return;
    }

    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;

    cout << "Product P" << id << " removed." << endl;
}

int main()
{
    int n, id, removeID;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter Product ID: ";
        cin >> id;

        insert(id);
    }

    cout << "\nShopping Cart:" << endl;
    display();

    cout << "\nEnter Product ID to remove: ";
    cin >> removeID;

    removeProduct(removeID);

    cout << "\nUpdated Cart:" << endl;
    display();

    return 0;
}

