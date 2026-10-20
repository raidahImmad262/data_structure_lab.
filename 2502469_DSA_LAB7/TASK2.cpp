#include <iostream>
using namespace std;

class NetworkQueue
{
private:
    int queue[5];
    int front, rear;

public:
    NetworkQueue()
    {
        front = -1;
        rear = -1;
    }

    void insertPacket()
    {
        if ((rear + 1) % 5 == front)
        {
            cout << "Queue is full! Cannot insert packet.\n";
            return;
        }

        int packet;
        cout << "Enter packet ID: ";
        cin >> packet;

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }

        queue[rear] = packet;
        cout << "Packet inserted successfully.\n";
    }

    void transmitPacket()
    {
        if (front == -1)
        {
            cout << "Queue is empty! No packet to transmit.\n";
            return;
        }

        cout << "Transmitted packet: " << queue[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % 5;
        }
    }

    void displayPackets()
    {
        if (front == -1)
        {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Packets waiting for transmission: ";

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
    NetworkQueue q;
    int choice;

    do
    {
        cout << "\n--- Network Packet Management ---\n";
        cout << "1. Insert Packet\n";
        cout << "2. Transmit Packet\n";
        cout << "3. Display Packets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            q.insertPacket();
        else if (choice == 2)
            q.transmitPacket();
        else if (choice == 3)
            q.displayPackets();
        else if (choice == 4)
            cout << "Program ended.\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 4);

    return 0;
}