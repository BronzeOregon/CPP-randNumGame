#include <iostream>
#include <ctime>
int setup();
int randGen();
int guess();
bool checkGuess(int guess, int targetNum);
bool playAgain();
bool game = true;

int main() {
    std::cout << "Hello, let's play a guessing game!" << std::endl;
    int targetNum;
    targetNum = setup();
    while(game){
        int currentGuess;
        currentGuess = guess();

        bool guessedCorrect;
        guessedCorrect = checkGuess(currentGuess, targetNum);

        if(guessedCorrect){
            game = playAgain();
        }
    }
    return 0;
}

//outputs that the computer is choosing a number and then generates one.
int setup(){
    std::cout << "I'll choose a number between 1 and 20, then you try to guess it!" << std::endl;
    return randGen();
}

//generates a random number based on the system time.
int randGen(){
    srand(time(nullptr));

    int targetNum = rand() % (1 - 20+1);

    return targetNum;
}

//takes console input as a guess.
int guess(){
    std::cout << "Please enter a number between 1 and 20!" << std::endl;
    int input;
    std::cin >> input;
    return input;
}

//checks to see if guess is too low, too high, or correct. Returns bool value to determine if game is won.
bool checkGuess(int guess, int targetNum){
    if(guess < targetNum){
        std::cout << "I'm sorry, your number was too low!" << std::endl;
        return false;
    } else if(guess > targetNum){
        std::cout << "I'm sorry, your number was too high!" << std::endl;
        return false;
    } else{
        std::cout << "That's correct! You guessed the number!" << std::endl;
        return true;
    }
}

//checks to see if player wants to go again. Recursive to allow for incorrect entries.
bool playAgain(){
    std::cout << "Would you like to play again? (enter 1 for yes, 2 for no.)" << std::endl;
    int cont;
    std::cin >> cont;
    if(cont == 1)
        return true;
    else if(cont == 2)
        return false;
    else
        return playAgain();
}