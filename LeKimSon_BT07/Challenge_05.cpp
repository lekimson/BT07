#include <iostream>
using namespace std;

const int NUM_MONKEYS = 3;
const int NUM_DAYS = 5;

// Function to calculate the average amount of food eaten per day by the family of monkeys
double calculateAverage(const int food[][NUM_DAYS]) {
    double totalFood = 0;
    for (int i = 0; i < NUM_MONKEYS; i++) {
        for (int j = 0; j < NUM_DAYS; j++) {
            totalFood += food[i][j];
        }
    }
    return totalFood / (NUM_MONKEYS * NUM_DAYS);
}

// Function to find the least amount of food eaten during the week by any one monkey
int findLeastAmount(const int food[][NUM_DAYS]) {
    int leastAmount = food[0][0];
    for (int i = 0; i < NUM_MONKEYS; i++) {
        for (int j = 0; j < NUM_DAYS; j++) {
            if (food[i][j] < leastAmount) {
                leastAmount = food[i][j];
            }
        }
    }
    return leastAmount;
}

// Function to find the greatest amount of food eaten during the week by any one monkey
int findGreatestAmount(const int food[][NUM_DAYS]) {
    int greatestAmount = food[0][0];
    for (int i = 0; i < NUM_MONKEYS; i++) {
        for (int j = 0; j < NUM_DAYS; j++) {
            if (food[i][j] > greatestAmount) {
                greatestAmount = food[i][j];
            }
        }
    }
    return greatestAmount;
}

int main() {
    int food[NUM_MONKEYS][NUM_DAYS];

    cout << "Nhap so luong pounds thuc an moi ngay cho tung con khi:\n";
    for (int i = 0; i < NUM_MONKEYS; i++) {
        for (int j = 0; j < NUM_DAYS; j++) {
            cout << "So luong pounds thuc an cho khi " << i + 1 << ", ngay " << j + 1 << ": ";
            cin >> food[i][j];

            // Kiem tra gia tri am va yeu cau nhap lai neu can
            while (food[i][j] < 0) {
                cout << "So luong pounds thuc an khong the la so am. Nhap lai: ";
                cin >> food[i][j];
            }
        }
    }

    double averageAmount = calculateAverage(food);
    int leastAmount = findLeastAmount(food);
    int greatestAmount = findGreatestAmount(food);

    cout << "\nBao cao luong thuc an:\n";
    cout << "Luong thuc an trung binh moi ngay cua ca gia dinh khi: " << averageAmount << " pounds" << endl;
    cout << "Luong thuc an it nhat trong tuan cua mot con khi: " << leastAmount << " pounds" << endl;
    cout << "Luong thuc an nhieu nhat trong tuan cua mot con khi: " << greatestAmount << " pounds" << endl;

    return 0;
}