/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "abstracts/ACoreModule.hpp"
#include <sys/types.h>
#include <dirent.h>
#include "Errors.hpp"
#include <fstream>
#include "DLLoader.hpp"

namespace arcade
{
    namespace core
    {
        class Core : public arcade::core::ACoreModule {
            public:
                Core();
                Core(int ac, char **av);
                ~Core();

                // ~~~~~~ Interface member funtions ~~~~~~
                arcade::State menu(void);
                int checkGameStatus(void);
                arcade::State gameloop(void);

                // ~~~~~~ Functions ~~~~~~
                arcade::State endLoop();
                void cleanVector(std::vector<std::string> & vec);
                std::vector<std::string> ScanFolder(void);
                arcade::Keys executeCommand(arcade::Keys input);
                void storeInfos(int score);

                // ~~~~~~ Switch library ~~~~~~
                void switchNextLibGraphic(void);
                void switchPrevLibGraphic(void);
                void switchNextLibGame(void);
                void switchPrevLibGame(void);

                // ~~~~~~ Setters ~~~~~~
                void setGamesLib(std::vector<std::string> & vec);
                void setDisplayLib(std::vector<std::string> & vec);

                // ~~~~~~ Getters ~~~~~~
                std::vector<std::string> getGamesLib(void);
                std::vector<std::string> getDisplayLib(void);
                std::string getCurrentGameLib(void);
                std::string getCurrentGraphicLib(void);
            
            private:
                DLLoader<display::IDisplayModule> *graphicLoader;
                DLLoader<game::IGameModule> *gameLoader;
                arcade::display::IDisplayModule *graphicInstance;
                arcade::game::IGameModule *gameInstance;
    
                std::vector<std::string> gameLibs;
                std::vector<std::string> graphicLibs;
                std::string currentGameLib;
                std::string currentGraphicLib;
        };
    } // namespace core
} // namespace arcade

#endif /* !CORE_HPP_ */
