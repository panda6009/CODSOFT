#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int secretNumber = std::rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "Try to guess the number between 1 and 100.\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number in "
                      << attempts << " attempts.\n";
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Too low! Try again.\n";
        }

        attempts++;

    } while (userGuess != secretNumber);

    return 0;
}

