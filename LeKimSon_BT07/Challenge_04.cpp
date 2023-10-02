#include <iostream>
using namespace std;

// Function to display numbers greater than n in an array
void displayNumbersGreaterThanN(const int arr[], int size, int n) {
    cout << "Cac so trong mang lon hon " << n << " la: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] > n) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {10, 20, 30, 40, 50};
    int n;

    cout << "Nhap mot so nguyen n: ";
    cin >> n;

    displayNumbersGreaterThanN(numbers, SIZE, n);

    return 0;
}