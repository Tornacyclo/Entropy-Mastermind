#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

const int MAX_GUESSES = 10;



bool check_guess(std::string guess, std::string code) {
    int correct_pos = 0;
    int correct_color = 0;

    for (int i = 0; i < 4; i++) {
        if (guess[i] == code[i]) {
            correct_pos++;
        } else {
            for (int j = 0; j < 4; j++) {
                if (i != j && guess[i] == code[j]) {
                    correct_color++;
                }
            }
        }
    }

    std::cout << "Correct Positions: " << correct_pos << std::endl;
    std::cout << "Correct Colors: " << correct_color << std::endl;

    return correct_pos == 4;
}


void solve_entropy_mastermind(std::string code) {
    std::string guess;
    std::vector<std::string> guesses;

    for (int i = 0; i < MAX_GUESSES; i++) {
        std::cout << "Guess " << i + 1 << ": ";
        std::cin >> guess;

        if (guess.length() != 4) {
            std::cout << "Invalid guess. Please enter a 4-letter code." << std::endl;
            i--;
            continue;
        }

        if (std::find(guesses.begin(), guesses.end(), guess) != guesses.end()) {
            std::cout << "You have already guessed this code. Please enter a new code." << std::endl;
            i--;
            continue;
        }

        guesses.push_back(guess);

        if (check_guess(guess, code)) {
            std::cout << "You win!" << std::endl;
            return;
        }
    }

    std::cout << "You lose! The code was " << code << "." << std::endl;
}



int main() {
    std::string code;

    std::cout << "Enter the code to solve: ";
    std::cin >> code;

    solve_entropy_mastermind(code);

    return 0;
}
