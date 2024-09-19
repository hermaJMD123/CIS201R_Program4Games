/*
* Program: Games.cpp
* Name: Jon-Michael Herman
* Date: September 19 2024
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Games.h"

using namespace std;

//PRE: This function initializes a game of Craps. It sets the random seed for die rolls, initializes the player's net worth, and prompts the player for a bet. The function handles game logic, including rolling dice and determining win/loss conditions based on standard Craps rules.
//POST: The function concludes the game, updating the player's net worth based on the outcome of the bets placed. It prompts the player to play again, looping until the player chooses to stop.
void playCraps() {
    srand(static_cast<unsigned int>(time(0))); //Seed random number generator
    char playAgain;
    double netWorth = 50.0;
    double bet;

    
    cout << "WELCOME TO CRAPS!\n";
    cout << endl;

    do {
        cout << "Your net worth is: $" << netWorth << ". Please enter your bet: ";
        cin >> bet;

        while (bet > netWorth) {
            cout << "Your net worth is only: $" << netWorth << ". Please adjust your bet: ";
            cin >> bet;
        }
        //Initialize die
        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1;
        int sum = die1 + die2;

        cout << "You rolled: " << die1 << " + " << die2 << " = " << sum << endl;
        cout << endl;

        if (sum == 7 || sum == 11) {
            cout << "You Win!!\n";
            netWorth += bet;
            cout << endl;
        }
        else if (sum == 2 || sum == 3 || sum == 12) {
            cout << "You Lost!!\n";
            netWorth -= bet;
            cout << endl;
        }
        else {
            int point = sum;
            cout << "Point is: " << point << endl;
            bool keepRolling = true;

            while (keepRolling) {
                die1 = rand() % 6 + 1;
                die2 = rand() % 6 + 1;
                sum = die1 + die2;

                cout << "You rolled: " << die1 << " + " << die2 << " = " << sum << endl;

                if (sum == point) {
                    cout << "Yay, you Win!!\n";
                    cout << endl;
                    netWorth += bet;
                    keepRolling = false;
                }
                else if (sum == 7) {
                    cout << "Sorry, but you Lost!!\n";
                    cout << endl;
                    netWorth -= bet;
                    keepRolling = false;
                }
            }
        }

        cout << "You now have: $" << netWorth << endl;
        cout << endl;
        cout << "Would you like to go again? Y or N ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'Y' || playAgain == 'y');
}

//PRE: This function initializes a game of Scraps. It seeds the random number generator, sets the player's initial net worth, and prompts the player for a bet. The function manages the game logic, including rolling three dice and determining win/loss conditions based on specific game rules.
//POST: The function concludes the game by updating the player's net worth according to the results of the bets placed. It prompts the player to decide whether to continue playing, looping until the player chooses to stop.
void playScraps() {
    srand(static_cast<unsigned int>(time(0))); //Seed random number generator
    char playAgain;
    double netWorth = 50.0;
    double bet;

    cout << "WELCOME TO SCRAPS!\n";
    cout << endl;

    do {
        cout << "Your net worth is: $" << netWorth << ". Please enter your bet: ";
        cin >> bet;
        cout << endl;

        while (bet > netWorth) {
            cout << "Your net worth is only: $" << netWorth << ". Please adjust your bet: ";
            cin >> bet;
        }
        //Initialize die
        int die1 = rand() % 8 + 1;
        int die2 = rand() % 8 + 1;
        int die3 = rand() % 8 + 1;
        int sum = die1 + die2 + die3;

        cout << "You rolled: " << die1 << " + " << die2 << " + " << die3 << " = " << sum << endl;
        cout << endl;

        if (die1 == 8 || die2 == 8 || die3 == 8) {
            cout << "You Win!!\n";
            netWorth += bet;
            cout << endl;
        }
        else if (sum == 9 || sum == 10 || sum == 14) {
            cout << "You Win!!\n";
            netWorth += bet;
            cout << endl;
        }
        else if (die1 == 1 || die2 == 1 || die3 == 1) {
            cout << "You Lost!!\n";
            netWorth -= bet;
            cout << endl;
        }
        else if (sum == 8 || sum == 20 || sum == 23 || sum == 24) {
            cout << "You Lost!!\n";
            netWorth -= bet;
            cout << endl;
        }
        else {
            int point = sum;
            cout << "Point is: " << point << endl;
            bool keepRolling = true;

            while (keepRolling) {
                die1 = rand() % 8 + 1;
                die2 = rand() % 8 + 1;
                die3 = rand() % 8 + 1;
                sum = die1 + die2 + die3;

                cout << "You rolled: " << die1 << " + " << die2 << " + " << die3 << " = " << sum << endl;

                if (sum == point) {
                    cout << "Yay, you Win!!\n";
                    netWorth += bet;
                    keepRolling = false;
                }
                else if (die1 == 8 || die2 == 8 || die3 == 8 || sum == 15) {
                    cout << "Sorry, but you Lost!!\n";
                    netWorth -= bet;
                    keepRolling = false;
                    cout << endl;
                }
            }
        }

        cout << "You now have: $" << netWorth << endl;
        cout << endl;
        cout << "Would you like to go again? Y or N ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'Y' || playAgain == 'y');
}

//PRE: Initializes the Rock, Paper, Scissors game, seeding the random number generator and prompting the player for their choice.
//POST: Concludes the game by displaying the result of the match and asking the player if they want to play again.
void playRockPaperScissors() {
    srand(static_cast<unsigned int>(time(0))); //Seed random number generator
    char playAgain;
    string userChoice;
    string choices[3] = { "rock", "paper", "scissors" }; //Initialize choices for game

    cout << "WELCOME TO Rock, Paper, Scissors!\n";
    cout << endl;

    do {
        cout << "Enter rock, paper, or scissors: ";
        cin >> userChoice;

        int computerChoice = rand() % 3;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        if (userChoice == choices[computerChoice]) {
            cout << "It's a tie!\n";
            cout << endl;
        }
        else if ((userChoice == "rock" && choices[computerChoice] == "scissors") ||
            (userChoice == "paper" && choices[computerChoice] == "rock") ||
            (userChoice == "scissors" && choices[computerChoice] == "paper")) {
            cout << "You win!\n";
            cout << endl;
        }
        else {
            cout << "You lose!\n";
            cout << endl;
        }

        cout << "Would you like to go again? Y or N ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'Y' || playAgain == 'y');
}

//PRE: Initializes the Rock, Paper, Scissors, Spock game, seeding the random number generator and prompting the player for their choice.
//POST: Concludes the game by displaying the result and asking the player if they want to play again.
void playRockPaperScissorsSpock() {
    srand(static_cast<unsigned int>(time(0))); //Seed random number generator
    char playAgain;
    string userChoice;
    string choices[4] = { "rock", "paper", "scissors", "spock" };

    cout << "WELCOME TO Rock, Paper, Scissors, Spock!\n";
    cout << endl;

    do {
        cout << "Enter rock, paper, scissors, or spock: ";
        cin >> userChoice;

        int computerChoice = rand() % 4;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        if (userChoice == choices[computerChoice]) {
            cout << "It's a tie!\n";
            cout << endl;
        }
        else if ((userChoice == "rock" && choices[computerChoice] == "scissors") ||
            (userChoice == "paper" && choices[computerChoice] == "rock") ||
            (userChoice == "scissors" && choices[computerChoice] == "paper") ||
            (userChoice == "paper" && choices[computerChoice] == "spock") ||
            (userChoice == "spock" && choices[computerChoice] == "rock") ||
            (userChoice == "spock" && choices[computerChoice] == "scissors")) {
            cout << "You win!\n";
            cout << endl;
        }
        else {
            cout << "You lose!\n";
            cout << endl;
        }

        cout << "Would you like to go again? Y or N ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'Y' || playAgain == 'y');
}
//Constructs card for blackjack deck
struct Card {
    string suit;
    string rank;
    int value;
};

//PRE: Initializes a standard deck of playing cards, defining suits, ranks, and their values.
//POST: Shuffles the deck and returns it as a vector of Card objects.
vector<Card> createDeck() {
    vector<Card> deck;
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    for (const string& suit : suits) {
        for (int i = 0; i < 13; ++i) {
            deck.push_back({suit, ranks[i], values[i]});
        }
    }
    random_shuffle(deck.begin(), deck.end());
    return deck;
}

//PRE: Calculates the total value of a hand of cards, accounting for Aces that can count as either 1 or 11.
//POST: Returns the adjusted hand value, ensuring it does not exceed 21.
int calculateHandValue(vector<Card>& hand) {
    int value = 0;
    int aceCount = 0;

    for (const Card& card : hand) {
        value += card.value;
        if (card.rank == "Ace") {
            aceCount++;
        }
    }

    while (value > 21 && aceCount > 0) {
        value -= 10;
        aceCount--;
    }

    return value;
}

//PRE: Initializes and manages a game of Blackjack, handling card dealing and player/dealer turns.
//POST: Concludes the game by determining the winner and asking if the player wants to play again.
void playBlackjack() {
    srand(static_cast<unsigned int>(time(0))); //Seed random number generator
    char playAgain;

    cout << "WELCOME TO BLACKJACK!\n";
    cout << endl;

    do {
        vector<Card> deck = createDeck();
        vector<Card> playerHand;
        vector<Card> dealerHand;

        // Initial deal
        playerHand.push_back(deck.back());
        deck.pop_back();
        dealerHand.push_back(deck.back());
        deck.pop_back();
        playerHand.push_back(deck.back());
        deck.pop_back();
        dealerHand.push_back(deck.back());
        deck.pop_back();

        bool playerBusted = false;
        bool dealerBusted = false;

        //Player turn
        while (true) {
            cout << "Player has the following cards:\n";
            for (const Card& card : playerHand) {
                cout << card.rank << " of " << card.suit << endl;
            }
            int playerTotal = calculateHandValue(playerHand);
            cout << "       TOTAL: " << playerTotal << endl;
            cout << endl;

            if (playerTotal > 21) {
                cout << "OOPS - Player went over 21. DEALER WINS!!\n";
                cout << endl;
                playerBusted = true;
                break;
            }

            char choice;
            cout << "Would you like to take another card? Y or N ";
            cin >> choice;
            cout << endl;
            if (choice == 'N' || choice == 'n') {
                break;
            }

            playerHand.push_back(deck.back());
            deck.pop_back();
        }

        //Dealer turn
        if (!playerBusted) {
            while (calculateHandValue(dealerHand) <= (calculateHandValue(playerHand))) {
                dealerHand.push_back(deck.back());
                deck.pop_back();
            }

            cout << "Dealer has the following cards:\n";
            for (const Card& card : dealerHand) {
                cout << card.rank << " of " << card.suit << endl;
            }
            int dealerTotal = calculateHandValue(dealerHand);
            cout << "       TOTAL: " << dealerTotal << endl;
            cout << endl;

            if (dealerTotal > 21) {
                cout << "OOPS - Dealer went over 21. PLAYER WINS!!\n";
                cout << endl;
                dealerBusted = true;
            }
        }

        //Determine winner
        if (!playerBusted && !dealerBusted) {
            int playerTotal = calculateHandValue(playerHand);
            int dealerTotal = calculateHandValue(dealerHand);

            if (playerTotal > dealerTotal) {
                cout << "PLAYER WINS!!\n";
                cout << endl;
            } else if (playerTotal < dealerTotal) {
                cout << "DEALER WINS!!\n";
                cout << endl;
            } else {
                cout << "It's a PUSH!!\n";
                cout << endl;
            }
        }

        cout << "Would you like to play again? Y or N ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'Y' || playAgain == 'y');
}

//PRE: Initializes and manages a game of Hangman, loading words from a file and setting up the game state.
//POST: Concludes the game by announcing the result and revealing the chosen word.
void playHangman() {
    srand(static_cast<unsigned int>(time(0))); //Seed random number generator
    ifstream file("words.txt");
    vector<string> words;
    string word;

    while (file >> word) {
        words.push_back(word);
    }

    if (words.empty()) {
        cout << "No words available to play Hangman.\n";
        return;
    }

    string chosenWord = words[rand() % words.size()];
    string guessWord(chosenWord.size(), '?');
    int guessesLeft = 6;
    vector<char> guessedLetters;

    cout << "WELCOME TO HANGMAN!\n";
    cout << endl;

    while (guessesLeft > 0 && guessWord != chosenWord) {
        cout << "Your word is: " << guessWord << "\n";
        cout << endl;
        cout << "Enter your guess: ";
        char guess;
        cin >> guess;

        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You already guessed that letter. Try again.\n";
            cout << endl;
            continue;
        }

        guessedLetters.push_back(guess); //Pushes object data back to vector
        bool correctGuess = false;

        for (size_t i = 0; i < chosenWord.size(); ++i) {
            if (chosenWord[i] == guess) {
                guessWord[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess) {
            cout << "Nice Guess!\n";
            cout << endl;
        }
        else {
            guessesLeft--;
            cout << "Sorry! Guess is not valid. You have " << guessesLeft << " guesses left.\n";
            cout << endl;
        }
    }

    if (guessWord == chosenWord) {
        cout << "Congratulations! You WIN !!!! The word was " << chosenWord << "\n";
        cout << endl;
    }
    else {
        cout << "You ran out of guesses. The word was " << chosenWord << ". Better luck next time!\n";
        cout << endl;
    }
}