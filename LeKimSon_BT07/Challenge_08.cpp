#include <iostream>
using namespace std;

const int SIZE = 3;

// Function to check if a 2D array is a Lo Shu Magic Square
bool isLoShuMagicSquare(int grid[][SIZE]) {
    // Calculate the sum of the first row
    int sum = 0;
    for (int col = 0; col < SIZE; col++) {
        sum += grid[0][col];
    }

    // Check if each row has the same sum
    for (int row = 1; row < SIZE; row++) {
        int rowSum = 0;
        for (int col = 0; col < SIZE; col++) {
            rowSum += grid[row][col];
        }
        if (rowSum != sum) {
            return false;
        }
    }

    // Check if each column has the same sum
    for (int col = 0; col < SIZE; col++) {
        int colSum = 0;
        for (int row = 0; row < SIZE; row++) {
            colSum += grid[row][col];
        }
        if (colSum != sum) {
            return false;
        }
    }

    // Check if the main diagonal has the same sum
    int mainDiagonalSum = 0;
    for (int i = 0; i < SIZE; i++) {
        mainDiagonalSum += grid[i][i];
    }
    if (mainDiagonalSum != sum) {
        return false;
    }

    // Check if the secondary diagonal has the same sum
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < SIZE; i++) {
        secondaryDiagonalSum += grid[i][SIZE - 1 - i];
    }
    if (secondaryDiagonalSum != sum) {
        return false;
    }

    // If all checks pass, the grid is a Lo Shu Magic Square
    return true;
}

int main() {
    int grid[SIZE][SIZE];

    cout << "Nhap cac so cho ma tran Lo Shu Magic Square:\n";
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cin >> grid[row][col];
        }
    }

    if (isLoShuMagicSquare(grid)) {
        cout << "Day la mot ma tran Lo Shu Magic Square.\n";
    } else {
        cout << "Day khong phai la mot ma tran Lo Shu Magic Square.\n";
    }

    return 0;
}