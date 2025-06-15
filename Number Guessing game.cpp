#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator
    std::srand(std::time(0));
    
    // Generate random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;

    std::cout << "=== Number Guessing Game ===\n";
    std::cout << "Guess a number between 1 and 100:\n";

    // Loop until the user guesses correctly
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed it in " << attempts << " attempt(s).\n";
        }
    } while (guess != secretNumber);

    return 0;
}
