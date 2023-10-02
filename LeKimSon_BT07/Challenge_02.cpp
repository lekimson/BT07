#include <iostream>
using namespace std;

int main() {
    const int months = 12;
    double rainfall[months];
    double totalRainfall = 0.0;
    double averageRainfall;
    double highestRainfall = 0.0;
    double lowestRainfall = 0.0;
    int highestMonth = 0;
    int lowestMonth = 0;

    cout << "Nhap tong luong mua hang thang trong nam:\n";
    for (int i = 0; i < months; i++) {
        cout << "Thang " << i + 1 << ": ";
        cin >> rainfall[i];

        // Kiem tra gia tri am va yeu cau nhap lai neu can
        while (rainfall[i] < 0) {
            cout << "Luong mua khong the la so am. Nhap lai: ";
            cin >> rainfall[i];
        }

        totalRainfall += rainfall[i];

        // Tim thang co luong mua cao nhat
        if (rainfall[i] > highestRainfall) {
            highestRainfall = rainfall[i];
            highestMonth = i;
        }

        // Tim thang co luong mua thap nhat
        if (i == 0 || rainfall[i] < lowestRainfall) {
            lowestRainfall = rainfall[i];
            lowestMonth = i;
        }
    }

    averageRainfall = totalRainfall / months;

    cout << "Tong luong mua trong nam la: " << totalRainfall << "mm" << endl;
    cout << "Luong mua trung binh hang thang la: " << averageRainfall << "mm" << endl;
    cout << "Thang co luong mua cao nhat la thang " << highestMonth + 1 << " voi " << highestRainfall << "mm" << endl;
    cout << "Thang co luong mua thap nhat la thang " << lowestMonth + 1 << " voi " << lowestRainfall << "mm" << endl;

    return 0;
}