#include <iostream>
using namespace std;

class PassengerDeque
{
private:
    int queue[5];
    int front, rear;

public:
    PassengerDeque()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear + 1) % 5 == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void insertFront()
    {
        if (isFull())
        {
            cout << "Deque is full!\n";
            return;
        }

        int id;
        cout << "Enter passenger request ID: ";
        cin >> id;

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + 5) % 5;
        }

        queue[front] = id;
        cout << "Passenger inserted at front.\n";
    }

    void insertRear()
    {
        if (isFull())
        {
            cout << "Deque is full!\n";
            return;
        }

        int id;
        cout << "Enter passenger request ID: ";
        cin >> id;

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }

        queue[rear] = id;
        cout << "Passenger inserted at rear.\n";
    }

    void removeFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Removed passenger ID: " << queue[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % 5;
        }
    }

    void removeRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Removed passenger ID: " << queue[rear] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + 5) % 5;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Passenger requests: ";

        int i = front;

        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 5;
        }

        cout << endl;
    }
};

int main()
{
    PassengerDeque d;
    int choice;

    do
    {
        cout << "\n--- Train Station Passenger Management ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            d.insertFront();
        else if (choice == 2)
            d.insertRear();
        else if (choice == 3)
            d.removeFront();
        else if (choice == 4)
            d.removeRear();
        else if (choice == 5)
            d.display();
        else if (choice == 6)
            cout << "Program ended.\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 6);

    return 0;
}
