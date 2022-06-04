/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include "../Type.hpp"

namespace arcade
{
    namespace display
    {
        class IDisplayModule {
            public:
                // Destructeur de la classe
                virtual ~IDisplayModule() = default;

                // Retourne le nom de la librairie courrante
                virtual std::string getLibName(void) = 0;

                // Change le nom du jeu courrant
                virtual void setGame(std::string gameName) = 0;

                // Affiche le menu avec les jeux et les librairies (jeux = gameLibs, librairies = graphicLibs)
                virtual Keys displayMenu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs) = 0; 
                
                // Fin de la librairie de jeu (affiche la victoire ou la défaite en fonction du paramètre)
                virtual arcade::State endLib(arcade::State) = 0;

                // Charge la map
                virtual void loadScreen(MapType map) = 0;

                // Rafraichit la map
                virtual void refreshScreen(MapType map) = 0;

                // Met à jour le score
                virtual bool updateScore(int score) = 0;

                // Retourne la touche appuyée
                virtual Keys keyPressed(void) = 0;
        };
    } // namespace display
} // namespace arcade

#endif /* !IDISPLAYMODULE_HPP_ */