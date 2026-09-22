#include <iostream>
using namespace std;

int main() {
    int parking[4][5] = {
        {1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0}
    };

    int occupied = 0;

    cout << "Parking Layout:\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << parking[i][j] << " ";

            if (parking[i][j] == 1)
                occupied++;
        }
        cout << endl;
    }

    cout << "\nOccupied: " << occupied << endl;
    cout << "Empty: " << 20 - occupied << endl;

    int row, column;

    cout << "\nEnter row (1-4): ";
    cin >> row;

    cout << "Enter column (1-5): ";
    cin >> column;

    if (parking[row - 1][column - 1] == 0)
        cout << "Space is AVAILABLE.\n";
    else
        cout << "Space is OCCUPIED.\n";

    cout << "Total spaces: 20\n";

    return 0;
}
