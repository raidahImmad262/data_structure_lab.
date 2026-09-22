#include <iostream>
using namespace std;

int main() {

    int marks[6][4] = {
        {85, 90, 78, 88},
        {76, 82, 91, 80},
        {92, 88, 95, 90},
        {68, 75, 70, 72},
        {89, 94, 86, 91},
        {80, 79, 84, 87}
    };

    
    cout << "Marks Table:\n";

    for (int i = 0; i < 6; i++) {
        cout << "Student " << i + 1 << ": ";

        for (int j = 0; j < 4; j++) {
            cout << marks[i][j] << " ";
        }

        cout << endl;
    }

    
    cout << "\nTotal and Average:\n";

    int highestTotal = 0;
    int highestStudent = 0;

    for (int i = 0; i < 6; i++) {

        int total = 0;

        for (int j = 0; j < 4; j++) {
            total = total + marks[i][j];
        }

        double average = total / 4.0;

        cout << "Student " << i + 1;
        cout << "  Total = " << total;
        cout << "  Average = " << average << endl;

        
        if (total > highestTotal) {
            highestTotal = total;
            highestStudent = i;
        }
    }
    
    cout << "\nHighest Marks in Each Subject:\n";

    for (int j = 0; j < 4; j++) {

        int highest = marks[0][j];

        for (int i = 1; i < 6; i++) {
            if (marks[i][j] > highest) {
                highest = marks[i][j];
            }
        }

        cout << "Subject " << j + 1 << ": " << highest << endl;
    }

    
    cout << "\nStudent with Highest Total:\n";
    cout << "Student " << highestStudent + 1;
    cout << " with " << highestTotal << " marks." << endl;

    return 0;
}
