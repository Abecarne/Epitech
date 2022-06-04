cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
    bomberman
    VERSION 0.1
    DESCRIPTION "Make a real Game"
    LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas -Wall -Wextra -lraylib -lGL -lboost_thread -lm -lvlc -lpthread -ldl -lrt -lX11 -g")

set(
    SOURCES
    src/main.cpp
    src/core/GameEngine.cpp
    src/core/Time.cpp
    src/core/Errors.cpp
    src/settings/Music.cpp
    src/settings/Options.cpp
    src/menu/LandingMenu.cpp
    src/menu/LoadingScreen.cpp
    src/menu/CreateProfile.cpp
    src/menu/SaveMenu.cpp
    src/menu/MainMenu.cpp
    src/game/PreGame.cpp
    src/game/assets/GameAssets.cpp
    src/entities/Camera.cpp
    src/entities/characters/ACharacters.cpp
    src/entities/characters/Players.cpp
    src/objects/Button.cpp
    src/objects/MenuButton.cpp
    src/objects/Image.cpp
    src/objects/models/AnimatedModels.cpp
    src/objects/models/StaticModels.cpp
    src/text/Text.cpp
    src/environments/Skybox.cpp
    src/environments/Map.cpp
    src/environments/GameBoard.cpp
)

set(
    HEADERS
    "${PROJECT_SOURCE_DIR}/include/core/GameEngine.hpp"
    "${PROJECT_SOURCE_DIR}/include/core/AGameState.hpp"
    "${PROJECT_SOURCE_DIR}/include/core/Time.hpp"
    "${PROJECT_SOURCE_DIR}/include/core/Errors.hpp"
    "${PROJECT_SOURCE_DIR}/include/settings/Music.hpp"
    "${PROJECT_SOURCE_DIR}/include/settings/Options.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/LandingMenu.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/LoadingScreen.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/SaveMenu.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/CreateProfile.hpp"
    "${PROJECT_SOURCE_DIR}/include/menu/MainMenu.hpp"
    "${PROJECT_SOURCE_DIR}/include/game/PreGame.hpp"
    "${PROJECT_SOURCE_DIR}/include/game/assets/GameAssets.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/Camera.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/characters/ICharacters.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/characters/ACharacters.hpp"
    "${PROJECT_SOURCE_DIR}/include/entities/characters/Players.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/Button.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/MenuButton.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/Image.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/models/AnimatedModels.hpp"
    "${PROJECT_SOURCE_DIR}/include/objects/models/StaticModels.hpp"
    "${PROJECT_SOURCE_DIR}/include/text/Text.hpp"
    "${PROJECT_SOURCE_DIR}/include/environments/Skybox.hpp"
    "${PROJECT_SOURCE_DIR}/include/environments/Map.hpp"
    "${PROJECT_SOURCE_DIR}/include/environments/GameBoard.hpp"
)

add_executable(bomberman ${SOURCES} ${HEADERS})
    find_package(PkgConfig)
    if (PKG_CONFIG_FOUND)
        pkg_check_modules(GTK "glib-2.0")
        if (GTK_FOUND)
            target_link_libraries(bomberman ${GTK_LIBRARIES})
            add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
        endif()
    else()
        install("glib-2.0")
    endif()

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
    "${PROJECT_SOURCE_DIR}/include/objects"
    "${PROJECT_SOURCE_DIR}/include/objects/models"
    "${PROJECT_SOURCE_DIR}/include/text"
)