cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
    bomberman
    VERSION 0.1
    DESCRIPTION "Make a real Game"
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DBOOST_BIND_GLOBAL_PLACEHOLDERS")

include(${CMAKE_MODULE_PATH}/Findraylib.cmake)
find_package(raylib 4.0.0 REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DBOOST_BIND_GLOBAL_PLACEHOLDERS")

set(
    SOURCES
    src/main.cpp
    src/core/GameEngine.cpp
    src/core/Time.cpp
    src/core/Errors.cpp
    src/settings/Music.cpp
    src/settings/Options.cpp
    src/settings/Chronometer.cpp
    src/menu/LandingMenu.cpp
    src/menu/CreateProfile.cpp
    src/menu/SaveMenu.cpp
    src/menu/MainMenu.cpp
    src/menu/OptionsMenu.cpp
    src/menu/ControlOptions.cpp
    src/menu/VolumeOptions.cpp
    src/menu/SelectGame.cpp
    src/menu/SelectMap.cpp
    src/menu/PauseMenu.cpp
    src/game/PreGame.cpp
    src/game/Game.cpp
    src/game/assets/GameAssets.cpp
    src/entities/Camera.cpp
    src/entities/Bombs.cpp
    src/entities/Blast.cpp
    src/entities/LootBox.cpp
    src/entities/characters/ACharacters.cpp
    src/entities/characters/Players.cpp
    src/entities/characters/Bots.cpp
    src/entities/characters/MoveBots.cpp
    src/entities/characters/IA/MediumIA.cpp
    src/entities/characters/IA/EasyAI.cpp
    src/entities/characters/CharacterStats.cpp
	src/entities/powerUp/APowerUp.cpp
	src/entities/powerUp/BombUp.cpp
    src/entities/powerUp/FireUp.cpp
    src/entities/powerUp/SpeedUp.cpp
    src/entities/powerUp/WallPassUp.cpp
    src/objects/Button.cpp
    src/objects/TextButton.cpp
    src/objects/MenuButton.cpp
    src/objects/Image.cpp
    src/objects/models/AnimatedModels.cpp
    src/objects/models/StaticModels.cpp
    src/text/Text.cpp
    src/environments/Skybox.cpp
    src/environments/Map.cpp
    src/environments/GameBoard.cpp
    src/menu/LoadingScreen.cpp
)

set(
    HEADERS
    "${PROJECT_SOURCE_DIR}/include/core/GameEngine.hpp"
    "${PROJECT_SOURCE_DIR}/include/core/AGameState.hpp"
    "${PROJECT_SOURCE_DIR}/include/core/Time.hpp"
    "${PROJECT_SOURCE_DIR}/include/core/Errors.hpp"
    "${PROJECT_SOURCE_DIR}/include/settings/Music.hpp"
    "${PROJECT_SOURCE_DIR}/include/settings/Options.hpp"
    "${PROJECT_SOURCE_DIR}/include/settings/Chronometer.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/LandingMenu.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/SaveMenu.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/CreateProfile.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/MainMenu.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/OptionsMenu.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/ControlOptions.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/VolumeOptions.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/SelectGame.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/SelectMap.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/PauseMenu.hpp"
    "${PROJECT_SOURCE_DIR}/include/game/PreGame.hpp"
    "${PROJECT_SOURCE_DIR}/include/game/Game.hpp"
    "${PROJECT_SOURCE_DIR}/include/game/assets/GameAssets.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/Camera.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/Bombs.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/Blast.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/LootBox.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/characters/ICharacters.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/characters/ACharacters.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/characters/Players.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/characters/Bots.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/powerUp/APowerUp.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/powerUp/BombUp.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/powerUp/FireUp.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/powerUp/SpeedUp.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/powerUp/WallPassUp.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/characters/CharacterStats.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/Button.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/MenuButton.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/TextButton.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/Image.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/models/AnimatedModels.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/models/StaticModels.hpp"
    "${PROJECT_SOURCE_DIR}/include/text/Text.hpp"
    "${PROJECT_SOURCE_DIR}/include/environments/Skybox.hpp"
    "${PROJECT_SOURCE_DIR}/include/environments/Map.hpp"
    "${PROJECT_SOURCE_DIR}/include/environments/GameBoard.hpp"
    "${PROJECT_SOURCE_DIR}/include/utils/Vector3Utils.hpp"
)

add_executable(bomberman ${SOURCES} ${HEADERS})

target_include_directories(
    bomberman PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/core"
    "${PROJECT_SOURCE_DIR}/include/settings"
    "${PROJECT_SOURCE_DIR}/include/environments"
    "${PROJECT_SOURCE_DIR}/include/menu"
    "${PROJECT_SOURCE_DIR}/include/game"
    "${PROJECT_SOURCE_DIR}/include/game/assets"
    "${PROJECT_SOURCE_DIR}/include/entities"
    "${PROJECT_SOURCE_DIR}/include/entities/characters"
    "${PROJECT_SOURCE_DIR}/include/entities/powerUp"
    "${PROJECT_SOURCE_DIR}/include/objects"
    "${PROJECT_SOURCE_DIR}/include/objects/models"
    "${PROJECT_SOURCE_DIR}/include/text"
    "${PROJECT_SOURCE_DIR}/include/utils"
)

target_link_libraries(bomberman raylib)