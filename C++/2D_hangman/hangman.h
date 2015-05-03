#ifndef __HANGMAN_H
#define __HANGMAN_H

#include <SDL2/SDL.h>
#include "key_types.h"
#include <map>
#include <string>

class Hangman {
public:
    bool init_SDL();
    bool init_window(SDL_Window** window);
    bool init_surfaces(std::map<KeyTypes, SDL_Surface*>& surfaces); 
    SDL_Surface* load_bit_map(std::string path);
    Hangman();
};

#endif
