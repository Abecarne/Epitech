/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Core
*/

#include "../include/Core.hpp"

arcade::core::ACoreModule::~ACoreModule() {};

arcade::core::Core::Core()
{
}

arcade::core::Core::Core(int ac, char **av)
{
    graphicLoader = nullptr;
    graphicInstance = nullptr;
    gameLoader = nullptr;
    gameInstance = nullptr;
    currentGameLib = "";
    currentGraphicLib = "";
    state = State::MENU_WINDOW;
    playerName = "Unknown";

    try {
        Error error(ac, av);
        graphicLoader = new DLLoader<arcade::display::IDisplayModule>;
        graphicLoader->loadShared(av[1]);
        graphicInstance = graphicLoader->getInstance();
        currentGraphicLib = graphicInstance->getLibName();
        
        while (state != EXIT || state != STORE || state != NO_STORE) {
            std::cout << state << std::endl;
            if (state == MENU_WINDOW || currentGameLib == "") {
                state = menu();
            } else if (state == RUNNING && currentGameLib != "") {
                state = gameloop();
            } else if (state == WIN || state == LOOSE) {
                state = endLoop();
            }
        }
        if (state == STORE)
            storeInfos(score);
    } catch(const std::exception& e) {
        throw (std::invalid_argument(e.what()));
    }
}

arcade::core::Core::~Core()
{
    if (gameInstance)
        gameLoader->unloadShared();
    if (graphicLoader != nullptr)
        graphicLoader->unloadShared();
}

arcade::State arcade::core::Core::menu(void)
{
    arcade::Keys inputKey = NONE;

    ScanFolder();
    inputKey = graphicInstance->displayMenu(gameLibs, graphicLibs);
    inputKey = executeCommand(inputKey);
    return (state);
}

arcade::State arcade::core::Core::gameloop()
{
    arcade::Keys inputKey = arcade::Keys::NONE;

    inputKey = graphicInstance->keyPressed();
    inputKey = executeCommand(inputKey);
    std::cout << "res/maps/" + currentGameLib + ".txt" << std::endl;
    gameInstance->launch("res/maps/" + currentGameLib + ".txt");
    graphicInstance->refreshScreen(gameInstance->getMap());
    graphicInstance->updateScore(gameInstance->getScore());
    return (state);
}

arcade::State arcade::core::Core::endLoop(void)
{
    arcade::Keys inputKey = arcade::Keys::NONE;

    inputKey = graphicInstance->keyPressed();
    inputKey = executeCommand(inputKey);
    graphicInstance->endLib(state);
    return (state);
}

arcade::Keys arcade::core::Core::executeCommand(arcade::Keys inputKey)
{
    switch (inputKey) {
        case arcade::Keys::NEXTLIB:
            this->switchNextLibGraphic();
            break;
        case arcade::Keys::PREVLIB:
            this->switchPrevLibGraphic();
            break;
        case arcade::Keys::NEXTGAME:
            this->switchNextLibGame();
            break;
        case arcade::Keys::PREVGAME:
            this->switchPrevLibGame();
            break;
        case arcade::Keys::ENTER:
            state = arcade::State::RUNNING;
            break;
        case arcade::Keys::MENU:
            state = arcade::State::MENU_WINDOW;
            break;
        case arcade::Keys::ESC:
            state = arcade::State::EXIT;
            break;
        case arcade::Keys::W:
            state = arcade::State::WIN;
            break;
        case arcade::Keys::L:
            state = arcade::State::LOOSE;
            break;
        case arcade::Keys::YES:
            state = arcade::State::STORE;
            break;
        case arcade::Keys::NO:
            state = arcade::State::NO_STORE;
            break;
        default:
            break;
    }
    return (inputKey);
}

int arcade::core::Core::checkGameStatus(void)
{
    return (0);
}

void arcade::core::Core::switchNextLibGraphic(void)
{
    if (this->currentGraphicLib == "") {
        currentGraphicLib = graphicLibs[0];
        graphicLoader = new DLLoader<arcade::display::IDisplayModule>;
        graphicLoader->loadShared("lib/arcade_" + this->currentGraphicLib + ".so");
        graphicInstance = graphicLoader->getInstance();
    } else {
        for (int i = 0; i < graphicLibs.size(); i++) {
            if ((graphicInstance->getLibName() == graphicLibs[i]) && i < graphicLibs.size() - 1) {
                currentGraphicLib = graphicLibs[i + 1];
                break;
            } else if (i == graphicLibs.size() - 1) {
                currentGraphicLib = graphicLibs[0];
            }
        }
        if (this->graphicInstance != nullptr) {
            graphicLoader->unloadShared();
            graphicLoader = new DLLoader<arcade::display::IDisplayModule>;
            graphicLoader->loadShared("lib/arcade_" + this->currentGraphicLib + ".so");
            graphicInstance = graphicLoader->getInstance();
        }
    }
}

void arcade::core::Core::switchNextLibGame(void)
{
    if (this->currentGameLib == "") {
        currentGameLib = gameLibs[0];
        gameLoader = new DLLoader<arcade::game::IGameModule>;
        gameLoader->loadShared("lib/arcade_" + this->currentGameLib + ".so");
        gameInstance = gameLoader->getInstance();
    } else {
        for (int i = 0; i < gameLibs.size(); i++) {
            if ((gameInstance->getGameName() == gameLibs[i]) && i < gameLibs.size() - 1) {
                currentGameLib = gameLibs[i + 1];
                break;
            } else if (i == gameLibs.size() - 1) {
                currentGameLib = gameLibs[0];
            }
        }
        if (this->gameInstance != nullptr) {
            gameLoader->unloadShared();
            gameLoader = new DLLoader<arcade::game::IGameModule>;
            gameLoader->loadShared("lib/arcade_" + this->currentGameLib + ".so");
            gameInstance = gameLoader->getInstance();
        }
    }
}

void arcade::core::Core::switchPrevLibGraphic(void)
{
    int i = 0;

    if (this->currentGraphicLib == "") {
        currentGraphicLib = graphicLibs[graphicLibs.size() - 1];
        graphicLoader = new DLLoader<arcade::display::IDisplayModule>;
        graphicLoader->loadShared("lib/arcade_" + this->currentGraphicLib + ".so");
        graphicInstance = graphicLoader->getInstance();
    } else {
        for (i; i < graphicLibs.size(); i++) {
            if ((graphicInstance->getLibName() == graphicLibs[i])) {
                if (i == 0) {
                    currentGraphicLib = graphicLibs[graphicLibs.size() - 1];
                    break;
                } else {
                    currentGraphicLib = graphicLibs[i - 1];
                    break;
                }
            }
        }
        if (i == graphicLibs.size()) {
            currentGraphicLib = graphicLibs[graphicLibs.size() - 1];
        }
        graphicLoader->unloadShared();
        graphicLoader = new DLLoader<arcade::display::IDisplayModule>;
        graphicLoader->loadShared("lib/arcade_" + this->currentGraphicLib + ".so");
        graphicInstance = graphicLoader->getInstance();
    }
}

void arcade::core::Core::switchPrevLibGame(void)
{
    int i = 0;

    if (this->currentGameLib == "") {
        currentGameLib = gameLibs[gameLibs.size() - 1];
        gameLoader = new DLLoader<arcade::game::IGameModule>;
        gameLoader->loadShared("lib/arcade_" + this->currentGameLib + ".so");
        gameInstance = gameLoader->getInstance();
    } else {
        for (i; i < gameLibs.size(); i++) {
            if ((gameInstance->getGameName() == gameLibs[i])) {
                if (i == 0) {
                    currentGameLib = gameLibs[gameLibs.size() - 1];
                    break;
                } else {
                    currentGameLib = gameLibs[i - 1];
                    break;
                }
            }
        }
        if (i == gameLibs.size()) {
            currentGameLib = gameLibs[gameLibs.size() - 1];
        }
        gameLoader->unloadShared();
        gameLoader = new DLLoader<arcade::game::IGameModule>;
        gameLoader->loadShared("lib/arcade_" + this->currentGameLib + ".so");
        gameInstance = gameLoader->getInstance();
    }
}

void arcade::core::Core::setGamesLib(std::vector<std::string> & vec)
{
    std::vector<std::string> games = {"nibbler", "pacman", "qix", "solarfox", "centipede"};
    this->gameLibs.clear();

    for (auto file : vec)
        for (auto game : games)
            if (file == "arcade_" + game + ".so")
                this->gameLibs.push_back(game);
}

void arcade::core::Core::setDisplayLib(std::vector<std::string> & vec)
{
    std::vector<std::string> libs = {"ndk++", "aalib", "libcaca", "allegro5", "xlib", "gtk+", "sfml", "irrlicht", "opengl", "vulkan", "qt5", "ncurses", "sdl2"};
    
    this->graphicLibs.clear();
    for (auto file : vec)
        for (auto lib : libs)
            if (file == "arcade_" + lib + ".so")
                this->graphicLibs.push_back(lib);
}

std::vector<std::string> arcade::core::Core::getGamesLib(void) { return (this->gameLibs); }
std::vector<std::string> arcade::core::Core::getDisplayLib(void) { return (this->graphicLibs); }

std::string arcade::core::Core::getCurrentGameLib(void) { return (this->currentGameLib); }
std::string arcade::core::Core::getCurrentGraphicLib(void) { return (this->currentGraphicLib); }


std::vector<std::string> arcade::core::Core::ScanFolder(void)
{
    DIR* dirp = opendir("./lib");
    struct dirent *dp;
    std::vector<std::string> res;
    std::vector<std::string> games;
    std::vector<std::string> graphics;

    while ((dp = readdir(dirp)) != NULL) {
        res.push_back(dp->d_name);
    }
    closedir(dirp);

    this->cleanVector(res);

    setGamesLib(res);
    setDisplayLib(res);
    return (res);
}

void arcade::core::Core::cleanVector(std::vector<std::string> & vec)
{
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].find("arcade_") == std::string::npos || vec[i].find(".so") == std::string::npos) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }
}

void arcade::core::Core::storeInfos(int score)
{
    std::string name;
    std::string score_str;
    std::string line;
    std::ifstream file;
    std::ofstream new_file;
    std::vector<std::string> contentOfFile;
    std::vector<std::string> scores;
    std::vector<std::string> names;

    file.open("lib/scores.txt");
    new_file.open("lib/scores.txt", std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        while (getline(file, line)) {
            contentOfFile.push_back(line);
        }
        file.close();
    }
    for (int i = 0; i < contentOfFile.size(); i++) {
        scores.push_back(contentOfFile[i].substr(0, contentOfFile[i].find(" ")));
        names.push_back(contentOfFile[i].substr(contentOfFile[i].find(" ") + 1, contentOfFile[i].size()));
    }
    for (int i = 0; i < scores.size(); i++) {
        if (std::stoi(scores[i]) < score) {
            scores.insert(scores.begin() + i, std::to_string(score));
            std::cout << "Enter your name : ";
            std::cin >> name;
            names.insert(names.begin() + i, name);
            break;
        }
    }
    for (int i = 0; i < scores.size(); i++) {
        new_file << scores[i] << " " << names[i] << std::endl;
    }
    new_file.close();
}