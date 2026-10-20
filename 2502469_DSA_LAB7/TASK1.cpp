
#include <iostream>
using namespace std;

int main()
{
    int q[5], front = -1, rear = -1, choice, customer;

    do
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Count";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (rear == 4)
                cout << "Overflow!";
            else
            {
                cout << "Enter customer token: ";
                cin >> customer;

                if (front == -1)
                    front = 0;

                q[++rear] = customer;
            }
        }
        else if (choice == 2)
        {
            if (front == -1 || front > rear)
                cout << "Underflow!";
            else
            {
                cout << "Served customer: " << q[front];
                front++;

                if (front > rear)
                    front = rear = -1;
            }
        }
        else if (choice == 3)
        {
            if (front == -1)
                cout << "Queue is empty!";
            else
            {
                for (int i = front; i <= rear; i++)
                    cout << q[i] << " ";
            }
        }
        else if (choice == 4)
        {
            if (front == -1)
                cout << "Waiting customers: 0";
            else
                cout << "Waiting customers: " << rear - front + 1;
        }

    } while (choice != 5);

    return 0;
}
