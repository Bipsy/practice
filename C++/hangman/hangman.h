#ifndef _HANGMAN_H
#define _HANGMAN_H

#include <string>

class Hangman {
public:
    auto static initialize(char letters_so_far[26]);
    auto static getSecretWord();
    auto static getGuess(const std::string& secret_word, 
                         const std::string& current_progress,
                         char letters_so_far[26],
                         int guesses);
    auto static printToScreen(std::string current_progress,
                              char letters_so_far[26],
                              int guesses);
    auto static checkGameStatus(const std::string& secret_word,
                                const std::string& current_progress,
                                int guesses);
    auto static resetGame();
    auto static printGallows(int guesses) -> void;
private:
};

#endif
