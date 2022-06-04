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

static void *handle_new_render_video(void *data, void **p_pixels)
{
    bomberman::menu::video_t *temp = (bomberman::menu::video_t *)data;

    g_mutex_lock(&temp->mutex);
    // Put all video pixels into the buffer
    *p_pixels = temp->videoBuffer;

    return NULL;
}

static void handle_end_render_video(void *data, void *id, void *const *p_pixels)
{
    bomberman::menu::video_t *temp = (bomberman::menu::video_t *)data;

    (void)id;
    (void)p_pixels;
    // Next frame is fully rendering, so we need to update
    temp->getUpdate = true;
    g_mutex_unlock(&temp->mutex);
}

void bomberman::menu::LoadingScreen::init(bomberman::core::GameEngine *engine)
{
    char *args[1]  = {(char *)"--verbose=-1"};

    std::srand(std::time(nullptr));
    this->_videoList = {LOADING1, LOADING2};
    this->_readedVideo = this->_videoList[std::rand() % this->_videoList.size()];
    _isLoaded = false;
    _loadingState = "MAP_MODULES";

    engine->initGameAssets();
    engine->getGameAssets()->initMap(CHINEASE_MAP);
    engine->getGameAssets()->initSkyBox(bomberman::environment::Skybox::DAY);
    engine->getGameAssets()->initGameBoard(15, 17, {0, 0, 0}, DESTRUCTIBLE_WOODBOX, DESTRUCTIBLE_WOODBOX, DESTRUCTIBLE_JAPANEASE);

    _loadingFct = {{"MAP_MODULES", &bomberman::menu::LoadingScreen::loadMapAssets},
                   {"SKY_MODULES", &bomberman::menu::LoadingScreen::loadSkyAssets},
                   {"GAMEBOARD_MODULES", &bomberman::menu::LoadingScreen::loadGameBoardAssets}};

    _camera.setPosition(0.0f, 0.0f, 0.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);

    _font = LoadFont("./assets/font/pikmin.ttf");

    // Create and Check if libvlc is created
    this->_lib_vlc = libvlc_new(1, args);
    if (!this->_lib_vlc)
        throw bomberman::core::Errors("[LoadingScreen]", "LibVLC is not loaded!");

    // Create and Check if struct video is created
    this->_video = new video_t;
    if (!this->_video)
        throw bomberman::core::Errors("[LoadingScreen]", "Video can't be load!");

    g_mutex_init(&this->_video->mutex);

    // Create and Check if the choosen media can be opened or not
    this->_media = libvlc_media_new_path(this->_lib_vlc, this->_readedVideo.c_str());
    if (!this->_media)
        throw bomberman::core::Errors("[LoadingScreen]", "Video can't be open!");
    this->_mediaPlayer = libvlc_media_player_new_from_media(this->_media);

    // Init all video parameters
    this->instanceVideo(engine->options.getWindowWidth(), engine->options.getWindowHeight());
    libvlc_video_set_callbacks(this->_mediaPlayer, handle_new_render_video, handle_end_render_video, NULL, this->_video);
}

void bomberman::menu::LoadingScreen::cleanup(void)
{
    // Free all memories allocated previously
    libvlc_media_player_stop(this->_mediaPlayer);
    libvlc_media_player_release(this->_mediaPlayer);
    UnloadTexture(this->_video->texture);
    MemFree(this->_video->videoBuffer);
    libvlc_release(this->_lib_vlc);
    delete this->_video;
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

void bomberman::menu::LoadingScreen::loadMapAssets(bomberman::core::GameEngine *engine)
{
    engine->getGameAssets()->getMap()->loadNextModels();

    if (engine->getGameAssets()->getMap()->getAssetsState())
        this->_loadingState = "SKY_MODULES";
}

void bomberman::menu::LoadingScreen::loadSkyAssets(bomberman::core::GameEngine *engine)
{
    engine->getGameAssets()->getSkyBox()->init(bomberman::environment::Skybox::day_cycle::DAY);

    this->_loadingState = "GAMEBOARD_MODULES";
}

void bomberman::menu::LoadingScreen::loadGameBoardAssets(bomberman::core::GameEngine *engine)
{
    engine->getGameAssets()->getGameBoard()->loadNextModels();

    if (engine->getGameAssets()->getGameBoard()->getAssetsState()) {
        _loadingState = "Finishing";
        _isLoaded = true;
    }
}

void bomberman::menu::LoadingScreen::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    (void)deltaTime;

    g_mutex_lock(&this->_video->mutex);
    // Update texture with the updated buffer
    UpdateTexture(this->_video->texture, this->_video->videoBuffer);
    this->_video->getUpdate = false;
    g_mutex_unlock(&this->_video->mutex);
    loadAllAssets(engine);
    if (videoIsFinished()) {
        if (_isLoaded)
            engine->changeState(bomberman::game::PreGame::getInstance());
        else
            restartLoadingScreen();
    }
}

void bomberman::menu::LoadingScreen::render(bomberman::core::GameEngine *engine)
{
    std::string tmpStr = _loadingState;
    tmpStr.append("...");

    (void)engine;

    BeginDrawing();
    DrawTextureEx(this->_video->texture, (Vector2){0, 0}, 0, 1, WHITE);
    DrawTextEx(_font, tmpStr.c_str(), {30, (float)engine->options.getWindowHeight() - 50}, 30, 1, WHITE);
    EndDrawing();
}

void bomberman::menu::LoadingScreen::instanceVideo(size_t screenWidth, size_t screenHeight)
{
    // Init media parameters like width, height or state
    libvlc_media_release(this->_media);
    libvlc_media_player_play(this->_mediaPlayer);
    libvlc_video_set_format(this->_mediaPlayer, "RV24", screenWidth, screenHeight, screenWidth * 3);

    g_mutex_lock(&this->_video->mutex);

    // Init default texture parameters
    this->_video->texture.id = rlLoadTexture(nullptr, screenWidth, screenHeight, PIXELFORMAT_UNCOMPRESSED_R8G8B8, 1);
    this->_video->texture.width = screenWidth;
    this->_video->texture.height = screenHeight;
    this->_video->texture.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8;
    this->_video->texture.mipmaps = 1;

    // Alloc memory for video buffer
    this->_video->videoBuffer = (uint8_t *)MemAlloc(screenWidth * screenHeight * 3);
    if (!this->_video->videoBuffer)
        throw bomberman::core::Errors("[LoadingScreen]", "Video buffer can't be loaded!");

    this->_video->getUpdate = false;
    g_mutex_unlock(&this->_video->mutex);
}

void bomberman::menu::LoadingScreen::restartLoadingScreen(void)
{
    libvlc_media_player_stop(this->_mediaPlayer);
    libvlc_media_player_set_position(this->_mediaPlayer, 0.0f);
    libvlc_media_player_play(this->_mediaPlayer);
}

bool bomberman::menu::LoadingScreen::videoIsFinished(void)
{
    if (libvlc_media_player_get_state(this->_mediaPlayer) == libvlc_Ended)
        return true;
    return false;
}