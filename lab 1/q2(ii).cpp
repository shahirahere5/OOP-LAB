#include <iostream>
using namespace std;


void inputAQI(int aqi[4][28]) {
    cout << "Enter AQI values for 4 cities over a month:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 28; j++) {
            cin >> aqi[i][j];
        }
    }
}


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


void monthlyAverage(int aqi[4][28], double avg[4]) {
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 28; j++) {
            sum += aqi[i][j];
        }
        avg[i] = sum / 28.0; 
    }
}


void improved(int week[4][4]) {
    int drop[4]; 

    for (int i = 0; i < 4; i++) {
        drop[i] = week[i][0] - week[i][3]; 
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


void compare(int aqi[4][28]) {
    cout << "\nHighest & Lowest AQI for Each City:\n";
    for (int i = 0; i < 4; i++) {
        int high = aqi[i][0];
        int low = aqi[i][0];

        for (int j = 1; j < 28; j++) {
            if (aqi[i][j] > high){
                high = aqi[i][j];
            }   
            if (aqi[i][j] < low){
                low = aqi[i][j];
            }    
        }
        cout << "City " << i + 1 << " - Highest AQI: " << high << ", Lowest AQI: " << low << endl;
    }
}


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
