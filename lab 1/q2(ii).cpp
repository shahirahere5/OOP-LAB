#include <iostream>
using namespace std;

// Function to input AQI values
void inputAQI(int aqi[4][28]) {
    cout << "Enter AQI values for 4 cities over 28 days:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 28; j++) {
            cin >> aqi[i][j];
        }
    }
}

// Function to calculate weekly average AQI
void weeklyAverage(int aqi[4][28], int week[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = 0;
            for (int k = j * 7; k < (j + 1) * 7; k++) {
                sum += aqi[i][k];
            }
            week[i][j] = sum / 7;
        }
    }
}

// Function to calculate monthly average AQI
void monthlyAverage(int aqi[4][28], double avg[4]) {
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 28; j++) {
            sum += aqi[i][j];
        }
        avg[i] = sum / 28.0; // Ensure floating-point division
    }
}

// Function to find the city with most improved air quality
void improved(int week[4][4]) {
    int drop[4]; // Stores improvement amount for each city

    for (int i = 0; i < 4; i++) {
        drop[i] = week[i][0] - week[i][3]; // Change from Week 1 to Week 4
    }

    int maxDrop = drop[0], city = 1;

    for (int i = 1; i < 4; i++) {
        if (drop[i] > maxDrop) {
            maxDrop = drop[i];
            city = i + 1;
        }
    }
    cout << "\nCity with most improved air quality: City " << city << endl;
}

// Function to identify critical pollution days (AQI > 150)
void critical(int aqi[4][28]) {
    cout << "\nCritical Pollution Days (AQI > 150):\n";
    for (int i = 0; i < 4; i++) {
        cout << "City " << i + 1 << ": ";
        bool hasCriticalDays = false;
        for (int j = 0; j < 28; j++) {
            if (aqi[i][j] > 150) {
                cout << "Day " << j + 1 << " ";
                hasCriticalDays = true;
            }
        }
        if (!hasCriticalDays) {
            cout << "No critical pollution days";
        }
        cout << endl;
    }
}

// Function to compare highest and lowest AQI for each city
void compare(int aqi[4][28]) {
    cout << "\nHighest & Lowest AQI for Each City:\n";
    for (int i = 0; i < 4; i++) {
        int high = aqi[i][0], low = aqi[i][0];

        for (int j = 1; j < 28; j++) {
            if (aqi[i][j] > high) high = aqi[i][j];
            if (aqi[i][j] < low) low = aqi[i][j];
        }
        cout << "City " << i + 1 << " - Highest AQI: " << high << ", Lowest AQI: " << low << endl;
    }
}

// Main function
int main() {
    int aqi[4][28];
    inputAQI(aqi);

    int week[4][4];
    weeklyAverage(aqi, week);

    double avg[4];
    monthlyAverage(aqi, avg);

    improved(week);

    cout << "\nWeekly AQI Averages:\n";
    for (int i = 0; i < 4; i++) {
        cout << "City " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            cout << week[i][j] << " ";
        }
        cout << endl;
    }

    critical(aqi);
    compare(aqi);

    return 0;
}
