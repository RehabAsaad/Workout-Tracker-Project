#include <iostream>
#include<iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>

using namespace std;

// Structure to represent a workout
struct Workout {
    string name;
    string type;
    int duration;
    string location;
    bool completed;
};

// Structure to represent a user profile
struct UserProfile {
    string username;
    double weight;  // Weight in kg
    double height;  // Height in cm
    string fitnessGoals;
    double suggestedWorkoutTime;
    double suggestedCaloriesBurned;
};
bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}

// User profile instance
UserProfile currentUser;

//  Function to display the list of workouts
void displayWorkouts(const vector<Workout>& workouts) {
    if (workouts.empty()) {
        cout << "\nNo workouts available.\n";
        return;
    }

    cout << "\n=======================(Workouts)==================================\n";
    cout << "Completed | Name               | Type           | Duration | Location\n";
    cout << "---------------------------------------------------------------------\n";

    // Display each workout's details
    for (const auto& workout : workouts) {
        cout << (workout.completed ? "(#)" : "( )") << "       | ";
        cout << workout.name;
        if (workout.name.length() < 18) {
            cout << string(18 - workout.name.length(), ' ');
        }
        cout << " | " << workout.type;
        if (workout.type.length() < 15) {
            cout << string(15 - workout.type.length(), ' ');
        }
        cout << "| " << workout.duration << " mins   | ";
        cout << workout.location << "\n";
    }
    cout << "====================================================================\n";
    system("pause");
    system("cls");
}

// Function to add a workout
void addWorkout(vector<Workout>& workouts) {
    Workout workout;
    while (true) {
        cout << "\nEnter workout name: ";
        getline(cin, workout.name);
        if (isValidName(workout.name)) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a name with only letters and spaces.\n";
        }
    }

    // Input validation for duration
    while (true) {
        cout << "Enter workout duration (minutes): ";
        cin >> workout.duration;
        if (cin.fail() || workout.duration <= 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a positive number.\n";
        }
        else {
            cin.ignore(); // To ignore the newline character left in the buffer
            break;
        }
    }
    while (true) {
        cout << "Enter workout type (e.g., Cardio, Strength, Flexibility, Yoga, etc.): ";
        getline(cin, workout.type);
        if (isValidName(workout.type)) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a type with only letters.\n";
        }
    }
    while (true) {
        cout << "Enter workout location (e.g.,Home,Gym,outdoor): ";
        getline(cin, workout.location);
        if (isValidName(workout.location)) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a location with only letters .\n";
        }
    }

    

    // Input validation for completion status
    while (true) {
        cout << "Is this workout completed? (1 for Yes, 0 for No): ";
        cin >> workout.completed;
        if (cin.fail() || (workout.completed != 0 && workout.completed != 1)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter 1 (Yes) or 0 (No).\n";
        }
        else {
            cin.ignore();            // To ignore the newline character
            break;
        }
    }

    workouts.push_back(workout);   // Add the workout to the list
    cout << "Workout added successfully.\n";
    system("pause");
    system("cls");
}
// Function to display the main menu

void displayMenu() {
    system("color 8E");

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "||      Workout Organizer          ||\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "1. Add Workout\n";
    cout << "2. Display Workouts\n";
    cout << "3. Search Workouts\n";
    cout << "4. Generate Report\n";
    cout << "5. Delete Workout\n";
    cout << "6. Set User Profile\n";
    cout << "7. Display User Profile\n";
    cout << "8. Exit\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Choose an option: ";
}

// Function to search workouts by name or type
void searchWorkouts(const vector<Workout>& workouts) {
    if (workouts.empty()) {
        cout << "\nNo workouts available to search.\n";
        return;
    }

    cout << "\nEnter the workout name or type to search: ";
    string searchTerm;
    getline(cin, searchTerm);

    bool found = false;
    cout << "\n=====================(Search Results)=================================\n";
    cout << "Completed | Name               | Type           | Duration | Location\n";
    cout << "-----------------------------------------------------------------------\n";

    for (const auto& workout : workouts) {
        if (workout.name.find(searchTerm) != string::npos || workout.type.find(searchTerm) != string::npos) {
            cout << (workout.completed ? "(#)" : "( )") << "       | ";
            cout << workout.name;
            if (workout.name.length() < 18) {
                cout << string(18 - workout.name.length(), ' ');
            }
            cout << " | " << workout.type;
            if (workout.type.length() < 15) {
                cout << string(15 - workout.type.length(), ' ');
            }
            cout << "| " << workout.duration << " mins   | ";
            cout << workout.location << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "\nNo workouts found matching the search criteria.\n";
    }

    cout << "=======================================================================\n";
    system("pause");
    system("cls");
}

// Function to generate a report of the workouts
void generateReport(const vector<Workout>& workouts) {
    int completedCount = 0;
    int totalDuration = 0;

    for (const auto& workout : workouts) {
        if (workout.completed) {
            completedCount++;
        }
        totalDuration += workout.duration;
    }

    cout << "\nReport:\n";
    cout << "Total Workouts ---> " << workouts.size() << "\n";
    cout << "Completed Workouts ---> " << completedCount << "\n";
    cout << "Total Duration of Workouts ---> " << totalDuration << " minutes\n";
    cout << "Average Duration ---> " << (workouts.size() > 0 ? totalDuration / workouts.size() : 0) << " minutes\n";
    // cout << "\nPress Enter to continue...";
    cin.get();
    system("pause");
    system("cls");
}

// Function to delete a workout by name or type
void deleteWorkout(vector<Workout>& workouts) {
    if (workouts.empty()) {
        cout << "\nNo workouts available to delete.\n";
        return;
    }

    // Display all workouts with numbers
    cout << "\nSelect the workout you want to delete by number:\n";
    cout << "===========================================================\n";
    for (size_t i = 0; i < workouts.size(); ++i) {
        cout << i + 1 << ". ";
        cout << (workouts[i].completed ? "(#)" : "( )") << " ";
        cout << workouts[i].name;
        if (workouts[i].name.length() < 18) {
            cout << string(18 - workouts[i].name.length(), ' ');
        }
        cout << " | " << workouts[i].type;
        if (workouts[i].type.length() < 15) {
            cout << string(15 - workouts[i].type.length(), ' ');
        }
        cout << " | " << workouts[i].duration << " mins | ";
        cout << workouts[i].location << "\n";
    }
    cout << "============================================================\n";

    int index;
    while (true) {
        cout << "Enter the number of the workout to delete: ";
        cin >> index;
        if (cin.fail() || index < 1 || index > static_cast<int>(workouts.size())) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number between 1 and " << workouts.size() << ".\n";
        }
        else {
            cin.ignore(); // To ignore the newline character left in the buffer
            break;
        }
    }

    // Adjust index to 0-based
    index -= 1;

    workouts.erase(workouts.begin() + index); // Delete the workout

    cout << "Workout deleted successfully.\n";
    system("pause");
    system("cls");
}
// Function to set the user profile


void setUserProfile() {

    while (true) {  
        cout << "\nEnter your username: ";
        getline(cin, currentUser.username);
        if (isValidName(currentUser.username)) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a name with only letters and spaces.\n";
        }
    }

    while (true) {
        cout << "Enter your weight (kg): ";
        cin >> currentUser.weight;
        if (cin.fail() || currentUser.weight <= 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a positive number.\n";
        }
        else {
            cin.ignore(); // To ignore the newline character left in the buffer
            break;
        }
    }

    while (true) {
        cout << "Enter your height (cm): ";
        cin >> currentUser.height;
        if (cin.fail() || currentUser.height <= 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a positive number.\n";
        }
        else {
            cin.ignore(); // To ignore the newline character left in the buffer
            break;
        }
    }

    while (true) {
        cout << "Enter your fitness goals (e.g., Weight Loss, Muscle Gain, Maintenance): ";
        getline(cin, currentUser.fitnessGoals);
        if (isValidName(currentUser.fitnessGoals)) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a name with only letters and spaces.\n";
        }
    }
   

    // Calculation for suggested workout time and calories burned
    currentUser.suggestedWorkoutTime = 30; // Start with a base of 30 minutes
    if (currentUser.fitnessGoals == "Weight Loss" || currentUser.fitnessGoals == "weight loss") {
        currentUser.suggestedWorkoutTime += 10; // Add 10 minutes for weight loss goals
    }
    else if (currentUser.fitnessGoals == "Muscle Gain" || currentUser.fitnessGoals == "muscle gain") {
        currentUser.suggestedWorkoutTime += 5;  // Add 5 minutes for muscle gain goals
    }



    // Calories burned formula (approximation): Calories burned per minute = 0.0175 * MET * weight in kg
    // MET is the metabolic equivalent (e.g., 8 for running, 6 for weightlifting)
    // For simplicity, we assume an average MET value of 5
    double caloriesBurnedPerMinute = 0.0175 * 5 * currentUser.weight;
    currentUser.suggestedCaloriesBurned = currentUser.suggestedWorkoutTime * caloriesBurnedPerMinute;

    cout << "\nBased on your profile, here's a suggestion:\n";
    cout << "\n** You should exercise for approximately " << round(currentUser.suggestedWorkoutTime) << " minutes per day.\n";
    cout << "** You should aim to burn approximately " << round(currentUser.suggestedCaloriesBurned) << " calories per day.\n";

    cout << "\nUser profile updated successfully.\n";
    system("pause");
    system("cls");

}

// Function to save workouts to a file
void saveWorkoutsToFile(const vector<Workout>& workouts) {
    ofstream outFile("workouts.txt");
    if (!outFile) {
        cout << "Error opening file for writing.\n";
        return;
    }

    for (const auto& workout : workouts) {
        outFile << workout.name << "\n"
            << workout.type << "\n"
            << workout.duration << "\n"
            << workout.location << "\n"
            << workout.completed << "\n";
    }

    outFile.close();
    cout << "Workouts saved to file successfully.\n";
}

//Loads workouts from a file into the program when it starts.
void loadWorkoutsFromFile(vector<Workout>& workouts) {
    ifstream inFile("workouts.txt");
    if (!inFile) {
        cout << "Error opening file for reading or file doesn't exist.\n";
        return;
    }

    Workout workout;
    while (getline(inFile, workout.name)) {
        getline(inFile, workout.type);
        inFile >> workout.duration;
        inFile.ignore(); // To ignore the newline character
        getline(inFile, workout.location);
        inFile >> workout.completed;
        inFile.ignore(); // To ignore the newline character
        workouts.push_back(workout);
    }

    inFile.close();
    cout << "Workouts loaded from file successfully.\n";
}

// Function to display the user profile
void displayUserProfile() {




    cout << "\n=======================(User Profile)==============================\n";
    cout << "Username               | " << currentUser.username << "\n";
    cout << "Weight (kg)            | " << currentUser.weight << "\n";
    cout << "Height (cm)            | " << currentUser.height << "\n";
    cout << "Fitness Goals          | " << currentUser.fitnessGoals << "\n";
    cout << "Suggested Workout Time | " << round(currentUser.suggestedWorkoutTime) << " minutes\n";
    cout << "Calories to Burn       | " << round(currentUser.suggestedCaloriesBurned) << " calories\n";
    cout << "====================================================================\n";
    system("pause");
    system("cls");
}

int main() {
    vector<Workout> workouts;

    // Load workouts from the file when the program starts
    loadWorkoutsFromFile(workouts);



    int choice;

    while (true) {
        displayMenu();

        // Input validation for choice
        while (!(cin >> choice)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number between 1 and 8.\n";
        }
        cin.ignore(); // To ignore the newline character left in the buffer

        switch (choice) {
        case 1:
            addWorkout(workouts);
            break;
        case 2:
            displayWorkouts(workouts);
            break;
        case 3:
            searchWorkouts(workouts);
            break;
        case 4:
            generateReport(workouts);
            break;
        case 5:
            deleteWorkout(workouts);
            break;
        case 6:
            setUserProfile();
            break;
        case 7:
            displayUserProfile(); // New option to display user profile
            break;
        case 8:
            saveWorkoutsToFile(workouts);
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
