/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Encapsulate
*/

#ifndef ENCAPSULATE_HPP_
#define ENCAPSULATE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class MYSDL {
    public:
        static int sdl_Init(Uint32 flags);
        static Uint32 sdl_WasInit(Uint32 flags);

        static SDL_Surface *sdl_LoadBMP(std::string file);
        static SDL_Window *sdl_CreateWindow(std::string title, int x, int y, int w, int h, Uint32 flags);
        static SDL_Renderer *sdl_CreateRenderer(SDL_Window *target, int index, Uint32 flags);
        static SDL_Texture *sdl_CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface);

        static void sdl_DestroyTexture(SDL_Texture *texture);
        static void sdl_DestroySurface(SDL_Surface *texture);
        static void sdl_DestroyWindow(SDL_Window *target);
        static void sdl_DestroyRenderer(SDL_Renderer *target);

        static int ttf_Init(void);
        static int ttf_WasInit(void);
        static TTF_Font *ttf_OpenFont(std::string file, int ptsize);
        static void ttf_CloseFont(TTF_Font *font);
        static SDL_Surface *ttf_RenderText_Solid(TTF_Font *font, std::string text, SDL_Color color);
        static void ttf_Quit(void);

        static void sdl_SetWindowTitle(SDL_Window *target, std::string title);
        static int sdl_SetRenderDrawColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        static int sdl_RenderClear(SDL_Renderer *renderer);
        static void sdl_RenderPresent(SDL_Renderer * renderer);
        static int sdl_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect);

        static int sdl_QueryTexture(SDL_Texture *texture, Uint32 *format, int *access, int *w, int *h);
        static int sdl_PollEvent(SDL_Event *event);

        static void sdl_RenderFillRect(SDL_Renderer *renderer, const SDL_Rect *rect);

        static void sdl_Quit(void);
};

#endif /* !ENCAPSULATE_HPP_ */
