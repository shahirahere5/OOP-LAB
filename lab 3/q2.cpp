#include <iostream>
using namespace std;

class fitnessTracker{
    private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

    public:
    fitnessTracker(string u, int d){
        userName = u;
        dailyStepGoal = d;
        stepsTaken = 0;
        caloriesBurned = 0;
    }
    void logSteps(int steps){
        stepsTaken += steps;
        caloriesBurned += steps * 0.04; // assuming 1 step burn 0.04 calories
    }
    void displayProgress(){
        cout << "User: " << userName << endl;
        cout << "Daily Step Goal: " << dailyStepGoal << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Calories Burned: " << caloriesBurned << " calories" << endl;
        if(stepsTaken >= dailyStepGoal){
            cout << "Congratulations! You've reached your goal." << endl;
        }else{
            cout << "Keep working hard!" << endl;
        }
    }
};    

int main(){
    fitnessTracker user1("laiba", 10000);
    user1.logSteps(5000);
    user1.displayProgress();

    return 0;
}    
