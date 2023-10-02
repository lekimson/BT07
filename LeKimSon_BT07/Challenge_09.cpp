#include <iostream>
using namespace std;

const int SIZE = 7;

int main() {
    long empId[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[SIZE];
    double payRate[SIZE];
    double wages[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Nhap so gio lam viec cho nhan vien co so nhan dang " << empId[i] << ": ";
        cin >> hours[i];

        // Kiem tra gia tri hop le cho so gio lam viec
        while (hours[i] < 0) {
            cout << "So gio lam viec khong duoc am. Vui long nhap lai: ";
            cin >> hours[i];
        }

        cout << "Nhap muc luong theo gio cho nhan vien co so nhan dang " << empId[i] << ": ";
        cin >> payRate[i];

        // Kiem tra gia tri hop le cho muc luong theo gio
        while (payRate[i] < 15.00) {
            cout << "Muc luong theo gio khong duoc nho hon 15.00. Vui long nhap lai: ";
            cin >> payRate[i];
        }

        wages[i] = hours[i] * payRate[i];
    }

    cout << "Tong thu nhap cua moi nhan vien:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Nhan vien co so nhan dang " << empId[i] << ": " << wages[i] << endl;
    }

    return 0;
}