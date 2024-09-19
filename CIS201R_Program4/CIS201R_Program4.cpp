/*
* Program: CIS201R_Program4.cpp (includes main)
* Name: Jon-Michael Herman
* Date: September 19 2024
* Description: This class serves as the main entry point for a console-based game menu, allowing users to choose from a variety of games 
* including Craps, Scraps, Rock Paper Scissors, Blackjack, and Hangman. It continuously prompts the player for their game choice and executes 
* the corresponding game function until the player decides to quit. The user-friendly interface ensures easy navigation and interaction with 
* the available games
*/

#include <iostream>
#include "Games.h"

using namespace std;

int main() {
    char choice;
    //Menu for Game
    do {
        cout << "Your Games List\n";
        cout << "C - Craps\n";
        cout << "S - Scraps\n";
        cout << "R - Rock, Paper, Scissors\n";
        cout << "E - Rock, Paper, Scissors, Spock\n";
        cout << "B - Blackjack\n";
        cout << "H - Hangman\n";
        cout << "Q - Quit\n";
        cout << "\nWhat game would you like to play? ";

        cin >> choice;
        cout << endl;

        //Handles different cases for each game selected, or allows the user to quit.
        switch (choice) {
        case 'C':
        case 'c':
            playCraps();
            break;
        case 'S':
        case 's':
            playScraps();
            break;
        case 'R':
        case 'r':
            playRockPaperScissors();
            break;
        case 'E':
        case 'e':
            playRockPaperScissorsSpock();
            break;
        case 'B':
        case 'b':
            playBlackjack();
            break;
        case 'H':
        case 'h':
            playHangman();
            break;
        case 'Q':
        case 'q':
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'Q' && choice != 'q');

    return 0;
}