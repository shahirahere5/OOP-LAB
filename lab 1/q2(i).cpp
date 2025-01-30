#include <iostream>
using namespace std;

void inputAQI(int aqi[4][7]){
    cout << "enter AQI values for 4 cities over a week" << endl;
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 7; j++){
            cin >> aqi[i][j];
        }
    }
    
}

void displayAverage(int aqi[4][7], double avg[4]){
    
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for(int j = 0; j < 7; j++){
            sum += aqi[i][j];
        }
        avg[i] = sum / 7.0;
        
    }
    
}

int worstAQI(double avg[4]){
    int worstCity = 0;
    for (int i = 1; i < 4; i++){
        if(avg[i] > avg[worstCity]){
            worstCity = i;
        }
    }
    return worstCity;
}

void criticalDays(int aqi[4][7]){
    cout << "critical pollution days" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "city " << i+1 << ": ";
        for (int j = 0; j < 7; j++)
        {
            if (aqi[i][j] > 150){
                cout << "Day " << j+1 << ", ";
            }
        }
        cout << endl;
    }
    
}

void displayVisualisation(int aqi[4][7]){
    cout << "AQI visualisation" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "city " << i+1 << ": ";
        for (int j = 0; j < 7; j++)
        {
            int stars = aqi[i][j]/50;
            for (int k = 0; k < stars; k++)
            {
                cout << "*";
            }
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int aqi[4][7];
    double avg[4];

    inputAQI(aqi);
    displayAverage(aqi, avg);
    
    cout << "Average AQI for each city:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "City " << i+1 << ": " << avg[i] << endl;
    }
    
    int worstCity = worstAQI(avg);

    cout << "Worst city: City " << worstCity+1 << ", AQI: " << avg[worstCity] << endl;
    
    criticalDays(aqi);
    displayVisualisation(aqi);
}