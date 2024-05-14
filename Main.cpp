#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int trials = 1; // number of trials until number guessed correctly
float rate = 1.0; // accuracy of each round

/* difficulty options */
const int easy = 10;
const int medium = 50;
const int hard = 100;


void topScreen() { // Straight line on the top

    for (int i = 0; i < 120; i++) {
        cout << "~";
    }
    cout << endl;
}

void mainScreen() { // Game Title

    topScreen();
    cout << "\t\t\t\t " << "---------------------------------------------------------" << endl
        << "\t\t\t\t\t\t " << "Guess The Random Number" << endl
        << "\t\t\t\t " << "---------------------------------------------------------" << "\n\n\n";
}

int difficultyRange() { // Choosing Level

    int option; // for user's difficulty response

    do {
        mainScreen();

        cout << "\t\t\t\t " << "|Choose difficulty: " << endl
            << "\t\t\t\t " << "|=================================" << endl
            << "\t\t\t\t " << "|(1) Easy    (1-10)" << endl
            << "\t\t\t\t " << "|(2) Medium  (1-50)" << endl
            << "\t\t\t\t " << "|(3) Hard    (1-100)" << endl
            << "\t\t\t\t " << "|" << endl
            << "\t\t\t\t " << "|Choice: ";
        cin >> option;

        system("cls"); // clear screen

    } while (option > 3 || option < 1);

    return option; // return user's choosen difficulty
}

int gamePlay(int range) {

    trials = 1; // reseting number of trial in case of multiple rounds
    rate = 1.0; // resting value of accuracy in cas eof multiple rounds

    system("cls");
    mainScreen();

    srand(time(NULL)); // randomization

    int random = rand() % range + 1; // range of number 10, 50, or 100
    int userInput; // user's guessed entry
    bool correct = true; // to end loop when number is guessed correctly

    while (correct) {

        cout << "\nGuess a number (1 - " << range << "): ";
        cin >> userInput;

        if (userInput > random) {
            cout << "-Too high!" << endl;
            trials++;
            rate++;
        }
        else if (userInput < random) {
            cout << "-Too low!" << endl;
            trials++;
            rate++;
        }
        else {
            cout << "You guessed right!";
            correct = false;
        }
    }

    return trials; // returns number of trials for summary()
}

void summary(int tries) { // Displays player stats after round ending

    cout << "\n\n" << "\t\t\t\t\t\t\t" << "WELL PLAYED!" << endl;
    cout << "\t\t\t\t" << "============================================================" << endl
        << "\t\t\t\t " << "Number of tries: " << tries << endl // number of trials
        << "\t\t\t\t" << "============================================================" << endl
        << "\t\t\t\t " << "Accuracy: " << (1 / rate) * 100 << "%" << endl // accuracy result
        << "\t\t\t\t" << "============================================================" << "\n\n\n";
}

int main()
{
    char choice = 'y'; // in case user wants to play multiple times
    int NumOfTries; // number of entries user entered

    while (choice == 'y' || choice == 'Y') { // User input for playing another round

        int gameLevel = difficultyRange(); // to set difficulty based on users menu entry

        switch (gameLevel) {

        case 1: {

            NumOfTries = gamePlay(easy); // (1-10)
            summary(NumOfTries);
            break;
        }
        case 2: {

            NumOfTries = gamePlay(medium); // (1-50)
            summary(NumOfTries);
            break;
        }
        case 3: {

            NumOfTries = gamePlay(hard); // (1-100)
            summary(NumOfTries);
            break;
        }
        }

        cout << "\n\n" << "Another round?[y/n]: ";
        cin >> choice;

        system("cls");
    }

    // Program Termination Message
    cout << "\n\n\n\n\n\n"
        << "\t\t\t\t\t\t" << "====================================" << endl
        << "\t\t\t\t\t\t\t  " << "Program Executed" << endl
        << "\t\t\t\t\t\t" << "===================================="
        << "\n\n\n\n\n\n";

    return 0;
}
