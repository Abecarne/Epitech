/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** encapsulate
*/

#include "encapsulate.hpp"

int MYSDL::sdl_Init(Uint32 flags)
{
    return (SDL_Init(flags));
}

Uint32 MYSDL::sdl_WasInit(Uint32 flags)
{
    return (SDL_WasInit(flags));
}

void MYSDL::sdl_Quit(void)
{
    SDL_Quit();
}

SDL_Surface *MYSDL::sdl_LoadBMP(std::string file)
{
    return (SDL_LoadBMP(file.c_str()));
}

SDL_Window *MYSDL::sdl_CreateWindow(std::string title, int x, int y, int w, int h, Uint32 flags)
{
    return (SDL_CreateWindow(title.c_str(), x, y, w, h, flags));
}

SDL_Renderer *MYSDL::sdl_CreateRenderer(SDL_Window *target, int index, Uint32 flags)
{
    return (SDL_CreateRenderer(target, index, flags));
}

SDL_Texture *MYSDL::sdl_CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface)
{
    return (SDL_CreateTextureFromSurface(renderer, surface));
}

void MYSDL::sdl_DestroyTexture(SDL_Texture *texture)
{
    return (SDL_DestroyTexture(texture));
}

void MYSDL::sdl_DestroySurface(SDL_Surface *surface)
{
    return (SDL_FreeSurface(surface));
}

void MYSDL::sdl_DestroyWindow(SDL_Window *target)
{
    SDL_DestroyWindow(target);
}

void MYSDL::sdl_DestroyRenderer(SDL_Renderer *target)
{
    SDL_DestroyRenderer(target);
}

int MYSDL::ttf_Init(void)
{
    return (TTF_Init());
}

int MYSDL::ttf_WasInit(void)
{
    return (TTF_WasInit());
}

TTF_Font *MYSDL::ttf_OpenFont(std::string file, int ptsize)
{
    return (TTF_OpenFont(file.c_str(), ptsize));
}

void MYSDL::ttf_CloseFont(TTF_Font *font)
{
    return (TTF_CloseFont(font));
}

SDL_Surface *MYSDL::ttf_RenderText_Solid(TTF_Font *font, std::string text, SDL_Color color)
{
    return (TTF_RenderText_Solid(font, text.c_str(), color));
}

void MYSDL::ttf_Quit(void)
{
    return (TTF_Quit());
}

void MYSDL::sdl_SetWindowTitle(SDL_Window *target, std::string title)
{
    return (SDL_SetWindowTitle(target, title.c_str()));
}

int MYSDL::sdl_SetRenderDrawColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return (SDL_SetRenderDrawColor(renderer, r, g, b, a));
}

int MYSDL::sdl_RenderClear(SDL_Renderer *renderer)
{
    return (SDL_RenderClear(renderer));
}

void MYSDL::sdl_RenderPresent(SDL_Renderer *renderer)
{
    return (SDL_RenderPresent(renderer));
}

int MYSDL::sdl_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect)
{
    return (SDL_RenderCopy(renderer, texture, srcrect, dstrect));
}

int MYSDL::sdl_QueryTexture(SDL_Texture *texture, Uint32 *format, int *access, int *w, int *h)
{
    return (SDL_QueryTexture(texture, format, access, w, h));
}

void MYSDL::sdl_RenderFillRect(SDL_Renderer *renderer, const SDL_Rect *rect)
{
    SDL_RenderFillRect(renderer, rect);
}

int MYSDL::sdl_PollEvent(SDL_Event *event)
{
    return (SDL_PollEvent(event));
}
