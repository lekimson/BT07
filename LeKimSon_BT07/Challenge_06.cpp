#include <iostream>
#include <fstream>
using namespace std;

const int MONTHS = 3;
const int DAYS_PER_MONTH = 30;

// Function to read weather data from a file and store it in a 2D array
void readWeatherData(char weatherData[][DAYS_PER_MONTH], const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        for (int month = 0; month < MONTHS; month++) {
            for (int day = 0; day < DAYS_PER_MONTH; day++) {
                file >> weatherData[month][day];
            }
        }
        file.close();
    }
    else {
        cout << "Khong the mo tep " << filename << endl;
    }
}

// Function to calculate the number of rainy, cloudy, and sunny days for each month and the entire three-month period
void calculateWeatherStats(const char weatherData[][DAYS_PER_MONTH], int monthStats[][3], int& maxRainyMonth) {
    for (int month = 0; month < MONTHS; month++) {
        monthStats[month][0] = 0; // Rainy days
        monthStats[month][1] = 0; // Cloudy days
        monthStats[month][2] = 0; // Sunny days

        for (int day = 0; day < DAYS_PER_MONTH; day++) {
            switch (weatherData[month][day]) {
                case 'R':
                    monthStats[month][0]++;
                    break;
                case 'C':
                    monthStats[month][1]++;
                    break;
                case 'S':
                    monthStats[month][2]++;
                    break;
                default:
                    break;
            }
        }
    }

    maxRainyMonth = 0;
    for (int month = 1; month < MONTHS; month++) {
        if (monthStats[month][0] > monthStats[maxRainyMonth][0]) {
            maxRainyMonth = month;
        }
    }
}

// Function to display the weather statistics report
void displayWeatherReport(const int monthStats[][3], const int& maxRainyMonth) {
    const string months[] = {"Thang Sau", "Thang Bay", "Thang Tam"};

    cout << "Bao cao thoi tiet:" << endl;
    for (int month = 0; month < MONTHS; month++) {
        cout << months[month] << ":" << endl;
        cout << "So ngay mua: " << monthStats[month][0] << endl;
        cout << "So ngay am u: " << monthStats[month][1] << endl;
        cout << "So ngay nang: " << monthStats[month][2] << endl;
        cout << endl;
    }

    cout << "Tong ket ca ba thang:" << endl;
    int totalRainyDays = monthStats[0][0] + monthStats[1][0] + monthStats[2][0];
    int totalCloudyDays = monthStats[0][1] + monthStats[1][1] + monthStats[2][1];
    int totalSunnyDays = monthStats[0][2] + monthStats[1][2] +monthStats[2][2];
    cout << "So ngay mua: " << totalRainyDays << endl;
    cout << "So ngay am u: " << totalCloudyDays << endl;
    cout << "So ngay nang: " << totalSunnyDays << endl;
    cout << endl;

    cout << "Thang co so ngay mua nhieu nhat la: " << months[maxRainyMonth] << endl;
}

int main() {
    const string filename = "RainOrShine.txt";
    char weatherData[MONTHS][DAYS_PER_MONTH];
    int monthStats[MONTHS][3];
    int maxRainyMonth;

    readWeatherData(weatherData, filename);
    calculateWeatherStats(weatherData, monthStats, maxRainyMonth);
    displayWeatherReport(monthStats, maxRainyMonth);

    return 0;
}