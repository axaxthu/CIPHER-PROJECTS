#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isprime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int ranNum = rand() % 100;

    cout << "┌───────────────────────────────────────────┐" << endl;
    cout << "│                                           │" << endl;
    cout << "│         WELCOME TO GUESS IT,              │" << endl;
    cout << "│              WIN IT                       │" << endl;
    cout << "└───────────────────────────────────────────┘" << endl;

    bool win = false;
    const int trials = 3;
    int guess;
    int pTries = 0;   //variable that will indicate how many trails have finished
    int score = 100;  // Initialized score to 100

    // Hints related variables
    int hintsLeft = 2;  // Number of hints available
    bool Hint1 = false;  // to track if odd/even hint has been used
    bool Hint2 = false;  // to track if prime/composite hint has been used

    while (!win && pTries != trials) {
        cout << "Guess a Number, Let's see how lucky you are: ";
        cin >> guess;
        pTries++;

        // Deduct score only after the first try
        if (pTries > 1) {
            score -= 10;
        }

        if (guess == ranNum) {
            // Additional deduction if hint was used
            //if (oddEvenHintUsed || primeHintUsed) {
            //    score -= 10;
            //}
            cout << "Congratulations! You Guessed the Number in " << pTries << " Tries." << endl;
            cout << "Your score is: " << score << endl;
            win = true;
        } else if (guess < ranNum) {
            int diff = ranNum - guess;
            if (diff <= 10) {
                cout << "Too low but very close!" << endl;
            } else if (diff <= 20) {
                cout << "Low, but close. Guess again." << endl;
            } else {
                cout << "Too low and too far. Guess again." << endl;
            }
        } else {
            int diff = guess - ranNum;
            if (diff <= 10) {
                cout << "Too high but very close!" << endl;
            } else if (diff <= 20) {
                cout << "High, but close. Guess again." << endl;
            } else {
                cout << "Too high and too far. Guess again." << endl;
            }
        }

        // Check if hints can be provided
        if (!win && hintsLeft > 0) {
            char choice;
            cout << "Would you like a hint? (Y/N): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                hintsLeft--;
                if (hintsLeft == 1 && !Hint1) {
                    Hint1 = true;
                    if (ranNum % 2 == 0) {
                        cout << "The number is even." << endl;
                    } else {
                        cout << "The number is odd." << endl;
                    }
                    // Deduct additional 10 points for using a hint
                    score -= 10;
                } else if (hintsLeft == 0 && !Hint2) {
                    Hint2 = true;
                    if (isprime(ranNum)) {
                        cout << "The number is prime." << endl;
                    } else {
                        cout << "The number is composite." << endl;
                    }
                    // Deduct additional 10 points for using a hint
                    score -= 10;
                }
                cout << "Hints Left: " << hintsLeft << endl;
            }
        }
    }

    if (!win) {
        cout << "You failed the game. The correct number was " << ranNum << "." << endl;
        cout << "Better luck next time!" << endl;
    }

    return 0;
}
