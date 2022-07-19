/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** LoadingScreen.cpp
*/

#include "LoadingScreen.hpp"
#include "PreGame.hpp"

bomberman::menu::LoadingScreen *bomberman::menu::LoadingScreen::_saveMenuInstance {nullptr};
std::mutex bomberman::menu::LoadingScreen::_mutex;

void bomberman::menu::LoadingScreen::init(bomberman::core::GameEngine *engine)
{
    _isLoaded = false;
    _loadingState = "MAP_MODULES";

    engine->initGameAssets();
    engine->getGameAssets()->initGameBoard(15, 17, {0, 0, 0}, DESTRUCTIBLE_WOODBOX, DESTRUCTIBLE_WOODBOX, DESTRUCTIBLE_JAPANEASE);
    engine->getGameAssets()->initSkyBox();
    engine->getGameAssets()->initMap(engine->options.getMapPath());

    _loadingFct = { {"MAP_MODULES", &bomberman::menu::LoadingScreen::loadMapAssets},
                    {"SKY_MODULES", &bomberman::menu::LoadingScreen::loadSkyAssets},
                    {"GAMEBOARD_MODULES",& bomberman::menu::LoadingScreen::loadGameBoardAssets},
                    {"CHARACTERS_MODULES", &bomberman::menu::LoadingScreen::loadAllPlayersAssets},
                    {"BOMBS_MODULES", &bomberman::menu::LoadingScreen::loadBombsAssets}};

    _camera.setPosition(0.0f, 0.0f, 0.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);

    StopMusicStream(engine->options.music.getMusicStream());
    _font = LoadFont("./assets/font/pikmin.ttf");
}

void bomberman::menu::LoadingScreen::cleanup(void)
{

}

void bomberman::menu::LoadingScreen::pause(void)
{
    // Nothing
}

void bomberman::menu::LoadingScreen::resume(void)
{
    // Nothing
}

void bomberman::menu::LoadingScreen::processInput(bomberman::core::GameEngine *engine)
{
    (void)engine;
    // Nothing
}

void bomberman::menu::LoadingScreen::loadAllAssets(bomberman::core::GameEngine *engine)
{
    for (auto it = _loadingFct.begin(); it != _loadingFct.end() ; ++it) {
        if (it->first == _loadingState) {
            (this->*_loadingFct[_loadingState])(engine);
            return;
        }
    }
}


void bomberman::menu::LoadingScreen::loadBombsAssets(bomberman::core::GameEngine *engine)
{
    engine->getGameAssets()->initNewTexture("BOMB", "./assets/models/entities/bombs/textures/walnut.png");

    if (!engine->getGameAssets()->getAllLoadedTextures().contains("BOMB"))
        throw bomberman::core::Errors("[Game]", "Bomb texture hasn't been loaded!");

    engine->getGameAssets()->initNewTexture("BLAST", "./assets/models/entities/blasts/textures/Fire.png");

    if (!engine->getGameAssets()->getAllLoadedTextures().contains("BLAST"))
        throw bomberman::core::Errors("[Game]", "Blast texture hasn't been loaded!");

    _loadingState = "FINISHING";
    _isLoaded = true;
}

void bomberman::menu::LoadingScreen::loadMapAssets(bomberman::core::GameEngine *engine)
{
    engine->getGameAssets()->getMap()->loadNextModels();

    if (engine->getGameAssets()->getMap()->getAssetsState())
        this->_loadingState = "SKY_MODULES";
}

void bomberman::menu::LoadingScreen::loadSkyAssets(bomberman::core::GameEngine *engine)
{
    if (engine->options.isNight())
        engine->getGameAssets()->getSkyBox()->init(bomberman::environment::Skybox::day_cycle::NIGHT);
    else
        engine->getGameAssets()->getSkyBox()->init(bomberman::environment::Skybox::day_cycle::DAY);

    this->_loadingState = "GAMEBOARD_MODULES";
}

void bomberman::menu::LoadingScreen::loadGameBoardAssets(bomberman::core::GameEngine *engine)
{
    engine->getGameAssets()->getGameBoard()->loadNextModels();

    if (engine->getGameAssets()->getGameBoard()->getAssetsState())
        _loadingState = "CHARACTERS_MODULES";
}

void bomberman::menu::LoadingScreen::loadAllPlayersAssets(bomberman::core::GameEngine *engine)
{
    int nbrEntity = 0;

    std::vector<std::string> modelEntity = {MODEL_RED_LEAF_PIKMIN, MODEL_BLUE_LEAF_PIKMIN, MODEL_WHITE_LEAF_PIKMIN, MODEL_YELLOW_LEAF_PIKMIN};

    for (nbrEntity = 0; nbrEntity < engine->options.getNbPlayers(); nbrEntity++)
        engine->getGameAssets()->initPlayer((bomberman::entities::ACharacters::playerNum)nbrEntity, modelEntity[nbrEntity], SKIN_DEFAULT, bomberman::entities::ACharacters::characterColors::DEFAULT, ANIMATION_PIKMIN_DEFAULT);
    
    for (nbrEntity; nbrEntity < 4; nbrEntity++)
        engine->getGameAssets()->initBots((bomberman::entities::ACharacters::playerNum)nbrEntity, modelEntity[nbrEntity], SKIN_DEFAULT, bomberman::entities::ACharacters::characterColors::DEFAULT, ANIMATION_PIKMIN_DEFAULT, (bomberman::entities::BotDifficulty)engine->options.getBotsDifficulty());

    _loadingState = "BOMBS_MODULES";
}

void bomberman::menu::LoadingScreen::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    (void)deltaTime;

    loadAllAssets(engine);
    if (_isLoaded)
        engine->changeState(bomberman::game::PreGame::getInstance());
}

void bomberman::menu::LoadingScreen::render(bomberman::core::GameEngine *engine)
{
    std::string tmpStr = _loadingState;
    tmpStr.append("...");

    (void)engine;

    BeginDrawing();
    DrawRectangle(0, 0, 1920, 1080, BLACK);
    DrawTextEx(_font, tmpStr.c_str(), {30, (float)engine->options.getWindowHeight() - 50}, 30, 1, WHITE);
    EndDrawing();
}
