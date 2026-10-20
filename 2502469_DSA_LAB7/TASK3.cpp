#include <iostream>
using namespace std;

class HospitalQueue
{
private:
    int patientID[10];
    int priority[10];
    int count;

public:
    HospitalQueue()
    {
        count = 0;
    }

    void insertPatient()
    {
        if (count == 10)
        {
            cout << "Queue is full! Cannot add more patients.\n";
            return;
        }

        cout << "Enter patient ID (e.g. 102): ";
        cin >> patientID[count];

        cout << "Enter priority (1 = highest): ";
        cin >> priority[count];

        count++;

        cout << "Patient added successfully.\n";
    }

    void treatPatient()
    {
        if (count == 0)
        {
            cout << "No patients waiting for treatment.\n";
            return;
        }

        int highest = 0;

        for (int i = 1; i < count; i++)
        {
            if (priority[i] < priority[highest])
            {
                highest = i;
            }
        }

        cout << "Treating patient P" << patientID[highest]
             << " with priority " << priority[highest] << endl;

        for (int i = highest; i < count - 1; i++)
        {
            patientID[i] = patientID[i + 1];
            priority[i] = priority[i + 1];
        }

        count--;
    }

    void displayPatients()
    {
        if (count == 0)
        {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "\nWaiting Patients:\n";
        cout << "Patient ID\tPriority\n";

        for (int i = 0; i < count; i++)
        {
            cout << "P" << patientID[i]
                 << "\t\t" << priority[i] << endl;
        }
    }
};

int main()
{
    HospitalQueue h;
    int choice;

    do
    {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Highest Priority Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            h.insertPatient();
        else if (choice == 2)
            h.treatPatient();
        else if (choice == 3)
            h.displayPatients();
        else if (choice == 4)
            cout << "Program ended.\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 4);

    return 0;
}