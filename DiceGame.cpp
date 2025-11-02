/// @file DiceGame.cpp
/// @author AshuPrograms
/// @section 3001
/// @date 10/27/2025
///
/// @brief This program utilzes three functions that work to create a dice
///        game. There is impleentation of selection and repeition structures
///        to suffice the rules of the game.




///  Headers for the program
#include <iostream>
#include <string>
#include <cstdlib>  ///  for rand() and srand()
#include <ctime>    ///  for true randomness, but not utilized in this program
#include <cmath>

using namespace std;

/// Function Prototypes
int randomInt(int rangeHigh, int rangeLow);
int getDollar();
void printGameStats(int TotalGames, int playerWinCount, int playerWinnings,
                    int HouseWinCount, int houseWinnings);

/// Program Starts
int main() {
    srand(42);  ///  Fixed random seed given


    ///  Variable Declarations
    int TotalGames = 0;         ///  Intialization to 0
    int playerWinCount = 0;
    int playerWinnings = 0;
    int HouseWinCount = 0;
    int houseWinnings = 0;
    char playAgain = 'y';       ///  Use this variable to manipulate entries.


       ///  While loop to validate whether player wants to keep playing
    while (playAgain == 'y' || playAgain == 'Y') {
        const int bet = getDollar();
        if (bet == -1) {  ///  invalid input after 3 attempts
            break;
        }

           ///  Calling the function for both dices
        const int dice1 = randomInt(1, 6);
        const int dice2 = randomInt(1, 6);
        const int sum = dice1 + dice2;

        cout << "Roll = " << dice1 << " and " << dice2
             << " totaling " << sum << endl;

           ///  I set a flag to check if there is a winner
        bool winnerDeclared = false;


        /// If statment block chained with else if ladder.
        /// Player wins if sum = 7 or 11
        if (sum == 7 || sum == 11) {
            playerWinCount++;
            playerWinnings += bet * 2;  // double the bet
            cout << "Player Wins $" << bet * 2 << "!\n";
            winnerDeclared = true;
        }

        /// Player wins if pair = 2, 4, 5, +50% of bet
        else if (dice1 == dice2 && (dice1 == 2 || dice1 == 4 || dice1 == 5)) {
            playerWinCount++;  ///  Increments the playerWin count
            playerWinnings += (bet * 3) / 2;  ///  +50% bet, rounded down
            cout << "Player Wins $" << (bet * 3) / 2 << "!\n";
            winnerDeclared = true;
        }
        ///  Game rules for house
        ///  House wins if the pair = 1, 3, 6
        else if (dice1 == dice2 && (dice1 == 1 || dice1 == 3 || dice1 == 6)) {
            HouseWinCount++;   ///  Increments the houseWin count
            houseWinnings += bet;
            cout << "House Wins!\n";
            winnerDeclared = true;
        }
        ///  House wins if sum = 3, 5, 9
        else if (sum == 3 || sum == 5 || sum == 9) {
            HouseWinCount++;
            houseWinnings += bet;
            cout << "House Wins!\n";
            winnerDeclared = true;
        }

        if (!winnerDeclared) {
            cout << "No Winner!\n";
        }

        TotalGames++;

        cout << "\nDo you want to play again Y/N? ";  ///  Repeats if 'y'||'Y'
        cin >> playAgain;
    }

    /// Calls the function to print the final game stats
    printGameStats(TotalGames, playerWinCount, playerWinnings,
                   HouseWinCount, houseWinnings);

    return 0;
}

/// Function Definitions

int randomInt(int rangeHigh, int rangeLow) {
    int high;  ///  Assigns value later on
    int low;   ///  Assigns value later on

      ///  If statement that checks and assigns
      ///  numbers to both high and low
      ///  depending on the numbers
    if (rangeHigh > rangeLow) {
        high = rangeHigh;
        low = rangeLow;
    } else {
        high = rangeLow;
        low = rangeHigh;
    }
       ///  rand provides random numbers, the % operator followed by the
       ///  arithmetic restricts the dices within range of 1-10
    return rand() % (high - low +1) + low;

}

int getDollar() {
    int dollars;       ///  Variable to store input
    int attempts = 3;  ///  By declaring attempts we can decrement it
                       ///  until the player runs out of attempts.
    int result = -1;   ///  Assumes failure by default

       ///  Need one return, so I loop until it sets 'result' or
       ///  runs out of attempts
    while (attempts > 0 && result == -1) {
        cout << "Enter a bet in integer dollars: ";

           /// This flag will be set to true ONLY if all the checks pass
        bool inputSuccess = false;

        /// Check 1: Did it read an integer?
        if (cin >> dollars) {
            /// Check 2: Is the next character 'Enter'? (Catches "1.5"
            /// or "100abc")
            if (cin.peek() == '\n') {
                  ///  Check 3: Is it positive?
                if (dollars > 0) {
                    /// --- SUCCESS ---
                    ///  All three checks passed. This is the only way
                    ///  I found that I could have success with inputs
                    inputSuccess = true;
                    result = dollars;
                }
            }
        }

        ///  --- FAILURE ---
        ///  If the success flag was NOT set, *something* went wrong.
        if (!inputSuccess) {
            attempts--;  ///  Decrement attempt count
            cout << "Error... " << attempts << " attempt(s) left!\n";

            ///  fix the cin stream
            if (cin.fail()) {
                ///  This handles the "abc" case
                cin.clear();  ///  Reset
            }

            ///  2. Cleasr the bad input
            cin.ignore(1000, '\n');

        } else {
            ///  clears any reaminder
            cin.ignore(1000, '\n');
        }

        ///  Check attempts
        if (attempts == 0 && result == -1) {
            ///  Output error
            cout << "\nInvalid input, session over.\n";
        }
    }  ///  end while

    return result;  ///  The only return statement
}

   ///  Function for output, explanation uncessessary since its just
   ///  couts
void printGameStats(int TotalGames, int playerWinCount, int playerWinnings,
                    int HouseWinCount, int houseWinnings) {
    cout << "\nGame over. Thanks for playing!\n\n";
    cout << "Game Stats\n";
    cout << "----------------------------------------\n";
    cout << "                   Total Games: " << TotalGames << endl;
    cout << "Number of times the player won: " << playerWinCount << endl;
    cout << "               Player Winnings: " << playerWinnings << endl;
    cout << " Number of times the house won: " << HouseWinCount << endl;
    cout << "                House Winnings: " << houseWinnings << endl;
}
