/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

// Using SDL and standard IO
#include <SDL2/SDL.h>
#include "hangman.h"
#include <iostream>
#include "key_types.h"
#include <map>
#include <memory>
#include <stdio.h>
#include <string>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool Hangman::init_SDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool Hangman::init_window(SDL_Window** window) {
    *window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

SDL_Surface* Hangman::load_bit_map(std::string path) {
    SDL_Surface* bit_map = SDL_LoadBMP(path.c_str());
    if (bit_map == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "tiger.bmp",
               SDL_GetError());
    }
    return bit_map;
}

bool Hangman::init_surfaces(std::map<KeyTypes, SDL_Surface*>& surfaces) {
   for (auto& pair : surfaces) {
        switch (pair.first) {
            case KeyTypes::Default : 
                pair.second = load_bit_map("panda.bmp");
                if (pair.second == nullptr) return false;
                break;
            case KeyTypes::UP :
                pair.second = load_bit_map("tiger.bmp");
                if (pair.second == nullptr) return false;
                break;
            case KeyTypes::DOWN : 
                pair.second = load_bit_map("lizard.bmp");
                if (pair.second == nullptr) return false;
                break;
            case KeyTypes::LEFT :
                pair.second = load_bit_map("lion.bmp");
                if (pair.second == nullptr) return false;
                break;
            case KeyTypes::RIGHT :
                pair.second = load_bit_map("eagle.bmp");
                if (pair.second == nullptr) return false;
                break;
            default : 
                break;   
        }
    } 
    return true;
}

Hangman::Hangman() {}

int main(int argc, char* args[]) {
    std::unique_ptr<Hangman> game(new Hangman());
    // The window we'll be rendering to
    SDL_Window* window = nullptr;

    // The surface contained by the window
    SDL_Surface* screenSurface = nullptr;
    SDL_Surface* new_image = nullptr;
    SDL_Surface* old_image = nullptr;
    std::map<KeyTypes, SDL_Surface*> surfaces {
        { KeyTypes::Default, nullptr },
        { KeyTypes::UP, nullptr },
        { KeyTypes::DOWN, nullptr },
        { KeyTypes::LEFT, nullptr },
        { KeyTypes::RIGHT, nullptr }    
    };

    if (!game->init_SDL()) {
        exit(1);
    }
    if (!game->init_window(&window)) {
        exit(1);
    }
    // Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    // Fill the surface white
    SDL_FillRect(screenSurface, nullptr,
                 SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    SDL_UpdateWindowSurface(window);
    if (!game->init_surfaces(surfaces)) {
        goto cleanup;
    }
    old_image = surfaces[KeyTypes::Default];
    SDL_BlitSurface(old_image, nullptr, screenSurface, nullptr);
    SDL_UpdateWindowSurface(window);

    while (true) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                goto cleanup;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP :
                        new_image = surfaces[KeyTypes::UP];
                        break;
                    case SDLK_DOWN :
                        new_image = surfaces[KeyTypes::DOWN];
                        break;
                    case SDLK_LEFT :
                        new_image = surfaces[KeyTypes::LEFT];
                        break;
                    case SDLK_RIGHT :
                        new_image = surfaces[KeyTypes::RIGHT];
                        break;                    
                    default :
                        new_image = surfaces[KeyTypes::Default];
                        break; 
                }
            }
        }
        if (new_image != old_image) {
            old_image = new_image;
            SDL_FillRect(screenSurface, nullptr,
                         SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_BlitSurface(old_image, nullptr, screenSurface, nullptr);
            SDL_UpdateWindowSurface(window);
        }
    }

    cleanup:
    // Free surfaces
    SDL_FreeSurface(screenSurface);
    for (auto& pair : surfaces) {
        SDL_FreeSurface(pair.second);
        pair.second = nullptr;
    }
    screenSurface = nullptr;

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
