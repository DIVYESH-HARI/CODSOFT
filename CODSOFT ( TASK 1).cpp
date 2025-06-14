#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // set up random seed based on current time
    srand(time(0));

    // generate number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;

    cout << "Welcome to the guessing game!" << endl;
    cout << "I've picked a number between 1 and 100." << endl;
    cout << "Try to guess it." << endl;

    while (true) {
        cout << "\nYour guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number." << endl;
            continue;
        }

        if (guess < secretNumber) {
            cout << "Too low, try again.";
        } else if (guess > secretNumber) {
            cout << "Too high, try again.";
        } else {
            cout << "You got it! The number was " << secretNumber << "." << endl;
            break;
        }
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
