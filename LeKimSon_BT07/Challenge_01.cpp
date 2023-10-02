#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int numbers[size];

    cout << "Nhap 10 gia tri vao mang:\n";
    for (int i = 0; i < size; i++) {
        cout << "Gia tri " << i+1 << ": ";
        cin >> numbers[i];
    }

    int smallest = numbers[0];
    int largest = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] < smallest)
            smallest = numbers[i];
        if (numbers[i] > largest)
            largest = numbers[i];
    }

    cout << "Gia tri nho nhat trong mang la: " << smallest << endl;
    cout << "Gia tri lon nhat trong mang la: " << largest << endl;

    return 0;
}