# Dice-Game
Description:
This program utilizes three functions that work to create a simple dice game. There is implementation of selection and repetition structures to suffice the rules of the game.

To run:
Type in terminal
g++ DiceGame.cpp -o DiceGame
./DiceGame
Program Starts

Game Rules:
The variable containing the total game count is incremented.

The player enters a bet in dollars.

The computer rolls two dice and calculates their total.

If the total is 7 or 11, the player wins.

the variable tracking player wins is incremented.
The bet entered by the player is doubled and added to the variable tracking player winnings.
"Player Wins $!" is printed
If the computer rolls a pair of 2s, 4s, or 5s, the player wins


the variable tracking player wins is incremented.
The bet entered by the player is increased by 50%. The results of increasing the bet by 50% should be rounded down to the nearest integer before adding to the variable tracking player winnings.
"Player Wins $!" is printed
If the computer rolls a pair of 1s, 3s, or 6s, the house wins.


the variable tracking the house wins is incremented.
The bet entered by the player is added to a variable that tracks house winnings.
"House Wins!" is printed
If the dice total rolled by the computer totals 3, 5, or 9, the house wins.

the variable tracking the house wins is incremented.
The bet entered by the player is added to a variable that tracks house winnings.
"House Wins!" is printed
