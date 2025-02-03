~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~workout organizer~~~~~~
---------------------------------

it is an application that helps users log, manage, and track their fitness activities.

"You can either manage your workouts yourself, or create a profile, and the application will suggest what you should do."
----------------------------------------------------------------------------------------------------------------------------

**Here's a summary based on the project you described:
*bool isValidName(const string& name):
The function you provided checks if a given name string contains only alphabetic characters and spaces
If the input is invalid, the program prompts the user to enter the name again, ensuring that the user input is always valid before proceeding.
=================================================================================================================
1. Workouts Management:
This section focuses on adding, displaying, searching, and deleting workouts as well as generating reports on workout statistics.

--> (Add Workouts): Users can input details of their workout such as name, type (e.g., Cardio, Strength), duration, and location.
----------------------
--> (Display Workouts): Shows a summary of all logged workouts with completion status.
-----------------------
--> (Search Workouts): Allows users to search workouts based on the name or type.
-----------------------
--> (Delete Workouts): 
-Provide a list of workouts with index numbers.
-The user can select the workout they wish to delete based on the index.
Once selected, the workout is removed from the in-memory list and the file is updated to reflect this change (e.g., by rewriting the file without the deleted workout).
------------------------
--> (Generate Report):
Calculate and display summary statistics:
-Total Workouts Logged: The number of workouts recorded.
-Total Duration: The sum of the durations of all workouts.
-Completed Workouts: The number of workouts marked as completed.
-Average Workout Duration: Calculated as the total duration divided by the number of workouts.
==============================================================================================


2-User Profile:

The User Profile section stores and manages user-specific data and gives personalized fitness suggestions.

**Users can set their personal details such as name, weight, height, and fitness goals (e.g., weight loss, muscle gain).

**Based on these inputs, the app provides suggested workout duration and estimated calories to burn.
===================================================================================================

3-Saving Workouts:

Workouts are stored in a file (e.g., workouts.txt), ensuring that they persist between program runs.
==================================================================================================
4-Loading Workouts:

When the program starts, it reads the workout file and populates the internal data structures (e.g., an array or list of workouts) with the saved workout data.
This allows the user to continue managing their workouts from where they last left off.
=================================================================================================
                          **Made BY**
Salma Mohamed
Rehab Ali
Dina
Mariam mubarak


