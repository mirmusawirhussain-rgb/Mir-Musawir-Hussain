#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

// Function to handle the game logic
void playGame() {
    int secretNumber;
    int guess;
    int attempts = 0;
    int difficultyChoice;
    int maxNumber; // This variable changes based on difficulty

    // --- NEW FEATURE: Difficulty Menu ---
    cout << "\n--- Select Difficulty Level ---\n";
    cout << "1. Easy   (1 - 10)\n";
    cout << "2. Medium (1 - 100)\n";
    cout << "3. Hard   (1 - 1000)\n";
    cout << "Enter choice: ";
    cin >> difficultyChoice;

    // Setting the range based on user choice using a SWITCH statement
    switch (difficultyChoice) {
        case 1:
            maxNumber = 10;
            break;
        case 2:
            maxNumber = 100;
            break;
        case 3:
            maxNumber = 1000;
            break;
        default:
            cout << "Invalid choice! Defaulting to Medium (1-100).\n";
            maxNumber = 100;
    }

    // Generate random number based on the selected maxNumber
    secretNumber = rand() % maxNumber + 1; 

    cout << "\nOK! I have picked a number between 1 and " << maxNumber << ".\n";

    // --- Game Loop ---
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too High!\n";
        } 
        else if (guess < secretNumber) {
            cout << "Too Low!\n";
        } 
        else {
            cout << "\nCONGRATULATIONS! You won!\n";
            cout << "The number was: " << secretNumber << "\n";
            cout << "Score (Attempts): " << attempts << "\n";
        }

    } while (guess != secretNumber);
}

int main() {
    srand(time(0)); // Seed the random generator once

    char playAgain;
    
    do {
        playGame();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}