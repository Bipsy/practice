#include "hangman.h"
#include <fstream>
#include <iostream>
#include <tuple>

#define MAX_GUESSES 10
#define ALPHA 26

auto Hangman::getSecretWord() {
    std::cout << "Please enter the secret word!" << std::endl;
    std::string input, current_progress;
    std::cin >> input;
    while (any_of(std::begin(input), std::end(input),
                  [] (char c) { return !isalpha(c); })) {
        std::cout << "Your word was definitely not a word!" << std::endl;
        std::cin >> input;
    }
    auto len = input.length();
    for (int i = 0; i < len; i++) {
        current_progress += '_';
    }
    for (int i = 0; i < 101; i++) {
        std::cout << std::endl;
    }
    return std::tuple<std::string, std::string>(input, current_progress);
}

auto Hangman::getGuess(const std::string& secret_word, 
                       const std::string& current_progress,
                       char letters_so_far[ALPHA],
                       int guesses) {
    char guess;
    std::cout << "Enter a guess" << std::endl;
    std::cin >> guess;
    while (true) {

        if (!isalpha(guess)) {
            std::cout << "You didn't enter a valid letter, try again please." 
                      << std::endl;
            std::cin >> guess;
            continue;
        }
        auto lower_guess = tolower(guess);
        if (letters_so_far[lower_guess-97] == '-') {
            std::cout << "You have already guessed that letter." << std::endl 
                      << "Try again please." 
                      << std::endl;
            std::cin >> guess;
            continue;
        } else {
            break;
        }
    }
    
    
    auto copy_progress = current_progress;
    auto len = secret_word.length();
    auto lower_guess = tolower(guess);
    letters_so_far[lower_guess-97] = '-';
    for (auto i = 0; i < len; i++) {
        auto lower_secret = tolower(secret_word[i]);
        if (lower_guess == lower_secret) {
            copy_progress[i] = secret_word[i];
        }
    }
    if (copy_progress == current_progress) {
        return std::tuple<std::string, int>(copy_progress, guesses+1);
    } else {
        return std::tuple<std::string, int>(copy_progress, guesses);
    }
}

auto Hangman::checkGameStatus(const std::string& secret_word,
                              const std::string& current_progress,
                              int guesses) {
    if (secret_word == current_progress) {
        printGallows(-1);
        std::cout << "You have won the game!" << std::endl;
        std::cout << "Secret Word: " << secret_word << std::endl;
        return false;
    } else if (guesses == MAX_GUESSES) {
        printGallows(guesses);
        std::cout << "You have lost the game!" << std::endl;
        std::cout << "The secret word was " << secret_word << std::endl;
        return false;
    } else {
        return true;
    }
}

auto Hangman::printGallows(int guesses) -> void {
    std::string file_name;
    switch (guesses) {
        case -1 : file_name = "free.txt";
                  break;
        case 0 : file_name = "empty_gallows.txt";
                 break;
        case 1 : file_name = "head_gallows.txt";
                 break;
        case 2 : file_name = "no_arms_gallows.txt";
                 break;
        case 3 : file_name = "right_arm_gallows.txt";
                 break;
        case 4 : file_name = "no_legs_gallows.txt";
                 break;
        case 5 : file_name = "right_leg_gallows.txt";
                 break;
        case 6 : file_name = "stubbs_gallows.txt";
                 break;
        case 7 : file_name = "right_foot_gallows.txt";
                 break;
        case 8 : file_name = "no_hands_gallows.txt";
                 break;
        case 9 : file_name = "right_hand_gallows.txt";
                 break;
        case 10 : file_name = "full_gallows.txt";
                 break;
        default : file_name = "empty.txt";
    }
    std::ifstream in_file;
    std::string line;
    in_file.open(file_name, std::ios::in);
    while (std::getline(in_file, line)) {
        printf("%s\n", line.c_str());    
    }
    in_file.close();
}

auto Hangman::printToScreen(std::string current_progress,
                            char letters_so_far[ALPHA],
                            int guesses) {
    if (guesses == 1) {
        std::cout << "You have used " << guesses << " guess so far." 
                  << std::endl;
    } else {
        std::cout << "You have used " << guesses << " guesses so far." 
                  << std::endl;
    }
    if (MAX_GUESSES-guesses == 1) {
        std::cout << "You have " << MAX_GUESSES-guesses 
                  << " guess left" << std::endl;
    } else {
        std::cout << "You have " << MAX_GUESSES-guesses
                  << " guesses left" << std::endl;
    }
    std::cout << "Current Progress: " << current_progress << std::endl;
    std::cout << "Letters Guessed: ";
    for (int i = 0; i < ALPHA; i++) {
        std::cout << letters_so_far[i];
    }
    Hangman::printGallows(guesses);
    std::cout << std::endl << std::endl;
}

auto Hangman::initialize(char letters_so_far[ALPHA]) {
    for (int i = 0; i < ALPHA; i++) {
        letters_so_far[i] = 97+i;
    }
}

int main(int argc, char** argv) {
    std::string secret_word, current_progress;
    tie(secret_word, current_progress) = Hangman::getSecretWord();
    int guesses = 0;
    char letters_so_far[ALPHA];
    bool game_not_over = true;
    Hangman::initialize(letters_so_far);
    do {
        Hangman::printToScreen(current_progress, letters_so_far, guesses);
        tie(current_progress, guesses) 
            = Hangman::getGuess(secret_word, current_progress, 
                                letters_so_far, guesses);
        game_not_over 
            = Hangman::checkGameStatus(secret_word, current_progress, guesses);
    } while (game_not_over);
    return 0;
}
