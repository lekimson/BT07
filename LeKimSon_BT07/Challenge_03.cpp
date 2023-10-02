#include <iostream>
#include <string>
using namespace std;

const int NUM_TYPES = 5;

// Function to find the index of the highest selling product
int findHighestSales(const int sales[]) {
    int highestIndex = 0;
    for (int i = 1; i < NUM_TYPES; i++) {
        if (sales[i] > sales[highestIndex])
            highestIndex = i;
    }
    return highestIndex;
}

// Function to find the index of the lowest selling product
int findLowestSales(const int sales[]) {
    int lowestIndex = 0;
    for (int i = 1; i < NUM_TYPES; i++) {
        if (sales[i] < sales[lowestIndex])
            lowestIndex = i;
    }
    return lowestIndex;
}

int main() {
    string salsaNames[NUM_TYPES] = {"mild", "medium", "sweet", "hot", "zesty"};
    int jarsSold[NUM_TYPES];
    int totalSales = 0;

    cout << "Nhap so luong lo ban duoc cho tung loai salsa:\n";
    for (int i = 0; i < NUM_TYPES; i++) {
        cout << "So luong lo ban duoc cho salsa " << salsaNames[i] << ": ";
        cin >> jarsSold[i];

        // Kiem tra gia tri am va yeu cau nhap lai neu can
        while (jarsSold[i] < 0) {
            cout << "So luong lo khong the la so am. Nhap lai: ";
            cin >> jarsSold[i];
        }

        totalSales += jarsSold[i];
    }

    int highestIndex = findHighestSales(jarsSold);
    int lowestIndex = findLowestSales(jarsSold);

    cout << "\nBao cao doanh so ban hang:\n";
    for (int i = 0; i < NUM_TYPES; i++) {
        cout << "So luong lo ban duoc cho salsa " << salsaNames[i] << ": " << jarsSold[i] << endl;
    }
    cout << "Tong so luong lo ban duoc: " << totalSales << endl;
    cout << "Salsa ban chay nhat: " << salsaNames[highestIndex] << endl;
    cout << "Salsa ban it nhat: " << salsaNames[lowestIndex] << endl;

    return 0;
}