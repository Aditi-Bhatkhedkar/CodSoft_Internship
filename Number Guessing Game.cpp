#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts." << std::endl;
        }

    } while (userGuess != randomNumber);

    return 0;
}

