/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** sdl2
*/

#include "sdl2.hpp"

arcade::display::ADisplayModule::~ADisplayModule() {};

// ~~~~~~ Beginning of member functions ~~~~~~

Sdl2::Sdl2(void)
{
    std::cout << "Constructeur SDL2" << std::endl;
    this->window = nullptr;
    this->libName = "sdl2";
    this->color = {255, 255, 255, 255};
    this->score = 0;

    if (MYSDL::sdl_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("Can't initialize SDL");
    } else {
	    MYSDL::ttf_Init();
        this->window = MYSDL::sdl_CreateWindow("SDL graphical window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 725, 845, SDL_WINDOW_SHOWN);
        if (!this->window)
            throw std::runtime_error("Can't create window");
        this->renderer = MYSDL::sdl_CreateRenderer(this->window, -1, 0);
    }
    this->font = MYSDL::ttf_OpenFont("res/Roboto-Light.ttf", 40);
}

Sdl2::~Sdl2()
{
    std::cout << "Destructeur SDL2" << std::endl;
    MYSDL::sdl_DestroyWindow(this->window);
    MYSDL::ttf_CloseFont(this->font);
    MYSDL::ttf_Quit();
    MYSDL::sdl_Quit();
}

std::string Sdl2::getLibName(void)
{
    return (this->libName);
}

void Sdl2::setGame(std::string gameName)
{
    (void)gameName;
}

void Sdl2::setTextsGameLibs(std::vector<std::string> gameLibs)
{
    int x = 725 / 3 * 2;
    int y = 380;
    int w = 150;
    int h = 40;

    for (auto i : gameLibs) {
        SDL_Surface *_surface = MYSDL::ttf_RenderText_Solid(font, i.c_str(), color);
        SDL_Texture *_texture = MYSDL::sdl_CreateTextureFromSurface(renderer, _surface);
        w = i.size() * 20;
        SDL_Rect _rect = {x, y, w, h};
        textsGameLibs.push_back(_texture);
        rectGameLibs.push_back(_rect);
        y += 60;
    }
}

void Sdl2::setTextsGraphicLibs(std::vector<std::string> graphicLibs)
{
    int x = 50;
    int y = 380;
    int w = 150;
    int h = 40;
    
    for (auto i : graphicLibs) {
        SDL_Surface *_surface = TTF_RenderText_Solid(font, i.c_str(), color);
        SDL_Texture *_texture = SDL_CreateTextureFromSurface(renderer, _surface);
        w = i.size() * 20;
        SDL_Rect _rect = {x, y, w, h};
        textsGraphicLibs.push_back(_texture);
        rectGraphicLibs.push_back(_rect);
        y += 60;
    }
}

void Sdl2::displayTitle(void)
{
    SDL_Color red = {255, 0, 0, 255};
    SDL_Surface *_surface = MYSDL::ttf_RenderText_Solid(font, "ARCADE", red);
    SDL_Texture *_texture = MYSDL::sdl_CreateTextureFromSurface(renderer, _surface);
    SDL_Rect _rect = {280, 50, 250, 100};
    MYSDL::sdl_RenderCopy(renderer, _texture, NULL, &_rect);
}

void Sdl2::displaygraphicLibs(void)
{
    SDL_Surface *_surface = MYSDL::ttf_RenderText_Solid(font, "Graphics available:", color);
    SDL_Texture *_texture = MYSDL::sdl_CreateTextureFromSurface(renderer, _surface);
    SDL_Rect _rect = {50, 300, 250, 50};
    MYSDL::sdl_RenderCopy(renderer, _texture, NULL, &_rect);
    for (size_t i = 0; i < textsGraphicLibs.size(); i++) {
        MYSDL::sdl_RenderCopy(renderer, textsGraphicLibs[i], NULL, &rectGraphicLibs[i]);
    }
}

void Sdl2::displaygameLibs(void)
{
    SDL_Surface *_surface = MYSDL::ttf_RenderText_Solid(font, "Games available:", color);
    SDL_Texture *_texture = MYSDL::sdl_CreateTextureFromSurface(renderer, _surface);
    SDL_Rect _rect = {725 / 3 * 2, 300, 200, 50};
    MYSDL::sdl_RenderCopy(renderer, _texture, NULL, &_rect);
    for (size_t i = 0; i < textsGameLibs.size(); i++) {
        MYSDL::sdl_RenderCopy(renderer, textsGameLibs[i], NULL, &rectGameLibs[i]);
    }
}

void Sdl2::displayScore(int score)
{
    SDL_Surface *_surface = MYSDL::ttf_RenderText_Solid(font, "Score: " + score, color);
    SDL_Texture *_texture = MYSDL::sdl_CreateTextureFromSurface(renderer, _surface);
    SDL_Rect _rect = {10, 10, 100, 25};
    MYSDL::sdl_RenderCopy(renderer, _texture, NULL, &_rect);
}

arcade::Keys Sdl2::displayMenu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs)
{
    setTextsGameLibs(gameLibs);
    setTextsGraphicLibs(graphicLibs);

    arcade::Keys input = arcade::Keys::NONE;
    input = keyPressed();

    MYSDL::sdl_RenderClear(this->renderer);
    displayTitle();
    displaygraphicLibs();
    displaygameLibs();
    MYSDL::sdl_RenderPresent(renderer);

    return (input);
}

void Sdl2::displayMap(MapType map)
{
    int x = 5;
    int y = 75;

    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '#') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                MYSDL::sdl_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == 'P') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == '.') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == 'O') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == '1') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == '2') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 255, 192, 203, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == '3') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == '4') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == '"') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 64, 224, 208, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == '_') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 128, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == 'F') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map[i][j] == 'S') {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else {
                SDL_Rect rect = {(int)(x + (j * 20)), (int)(y + (i * 20)), 20, 20};
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}


arcade::State Sdl2::endLib(arcade::State state)
{
    MYSDL::sdl_RenderClear(this->renderer);
    if (state == arcade::State::LOOSE) {
        SDL_Surface *_surface = MYSDL::ttf_RenderText_Solid(font, "You lost!", color);
        SDL_Texture *_texture = MYSDL::sdl_CreateTextureFromSurface(renderer, _surface);
        SDL_Rect _rect = {300, 300, 120, 60};
        MYSDL::sdl_RenderCopy(renderer, _texture, NULL, &_rect);
        SDL_Surface *_surfaceScore = MYSDL::ttf_RenderText_Solid(font, "Do you want to save your score ? ( Y / N )", color);
        SDL_Texture *_textureScore = MYSDL::sdl_CreateTextureFromSurface(renderer, _surfaceScore);
        SDL_Rect _rectScore = {150, 450, 420, 50};
        MYSDL::sdl_RenderCopy(renderer, _textureScore, NULL, &_rectScore);
    }
    else if (state == arcade::State::WIN) {
        SDL_Surface *_surface = MYSDL::ttf_RenderText_Solid(font, "You won!", color);
        SDL_Texture *_texture = MYSDL::sdl_CreateTextureFromSurface(renderer, _surface);
        SDL_Rect _rect = {300, 300, 120, 60};
        MYSDL::sdl_RenderCopy(renderer, _texture, NULL, &_rect);
        SDL_Surface *_surfaceScore = MYSDL::ttf_RenderText_Solid(font, "Do you want to save your score ? ( Y / N )", color);
        SDL_Texture *_textureScore = MYSDL::sdl_CreateTextureFromSurface(renderer, _surfaceScore);
        SDL_Rect _rectScore = {150, 450, 420, 50};
        MYSDL::sdl_RenderCopy(renderer, _textureScore, NULL, &_rectScore);
    }
    MYSDL::sdl_RenderPresent(renderer);
    return (state);
}


void Sdl2::loadScreen(MapType map)
{
    (void)map;
}

void Sdl2::refreshScreen(MapType map)
{
    (void)map;
    MYSDL::sdl_RenderClear(this->renderer);
    displayScore(this->score);
    displayMap(map);
    MYSDL::sdl_RenderPresent(this->renderer);
}

bool Sdl2::updateScore(int _score)
{
    this->score = _score;
    return (true);
}

arcade::Keys Sdl2::keyPressed(void)
{
    while (SDL_PollEvent(&this->events)) {
        switch (events.type) {
            case SDL_QUIT:
                return (arcade::Keys::ESC);
                break;
            case SDL_KEYDOWN:
                switch(events.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        return (arcade::Keys::ESC);
                    case SDLK_a:
                        return (arcade::Keys::PREVLIB);
                    case SDLK_e:
                        return (arcade::Keys::NEXTLIB);
                    case SDLK_o:
                        return (arcade::Keys::PREVGAME);
                    case SDLK_p:
                        return (arcade::Keys::NEXTGAME);
                    case SDLK_m:
                        return (arcade::Keys::MENU);
                    case SDLK_SPACE:
                        return (arcade::Keys::ENTER);
                    case SDLK_w:
                        return (arcade::Keys::W);
                    case SDLK_l:
                        return (arcade::Keys::L);
                    case SDLK_y:
                        return (arcade::Keys::YES);
                    case SDLK_n:
                        return (arcade::Keys::NO);
                    default:
                        break;
                }
            default:
                break;
        }
    }
    return (arcade::Keys::NONE);
}

// ~~~~~~ End of member functions ~~~~~~

extern "C" {
    arcade::display::IDisplayModule *EntryPoint(void)
    {
        arcade::display::IDisplayModule *instance = new Sdl2();
        return instance;
    }

    void deleteInstance(arcade::display::IDisplayModule *instance)
    {
        delete instance;
    }
}