#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

// Function to find the lowest number in an array
int findLowestNumber(const int numbers[], int size) {
    int lowest = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
    }
    return lowest;
}

// Function to find the highest number in an array
int findHighestNumber(const int numbers[], int size) {
    int highest = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
    }
    return highest;
}

// Function to calculate the total of numbers in an array
int calculateTotal(const int numbers[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += numbers[i];
    }
    return total;
}

// Function to calculate the average of numbers in an array
double calculateAverage(const int numbers[], int size) {
    int total = calculateTotal(numbers, size);
    double average = static_cast<double>(total) / size;
    return average;
}

int main() {
    string filename;
    int numbers[MAX_SIZE];
    int size = 0;

    cout << "Nhap ten tep: ";
    cin >> filename;

    ifstream file(filename);
    if (file.is_open()) {
        int number;
        while (file >> number) {
            numbers[size] = number;
            size++;
        }
        file.close();

        if (size > 0) {
            int lowest = findLowestNumber(numbers, size);
            int highest = findHighestNumber(numbers, size);
            int total = calculateTotal(numbers, size);
            double average = calculateAverage(numbers, size);

            cout << "So nho nhat: " << lowest << endl;
            cout << "So lon nhat: " << highest << endl;
            cout << "Tong: " << total << endl;
            cout << "Trung binh: " << average << endl;
        } else {
            cout << "Tep rong." << endl;
        }
    } else {
        cout << "Khong the mo tep." << endl;
    }

    return 0;
}