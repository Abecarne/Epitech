/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include "../Type.hpp"

namespace arcade
{
    namespace game
    {
        class IGameModule {
            public:
                // Destructeur de la classe
                virtual ~IGameModule() = default;

                // Retourne le nom du jeu courrant
                virtual std::string getGameName(void) = 0;

                // Retourne l'état du jeu courrant
                virtual State getState(void) = 0;

                // Retourne le score du jeu courrant
                virtual int getScore(void) = 0;

                // Lance le jeu avec le lien vers la map de jeu passé en paramètre
                virtual void launch(std::string) = 0; 

                // Effectue l'action correspondante en fonction de la touche appuyée (envoyée en paramètre)
                virtual void keyInput(Keys inputKey) = 0;

                // Met à jour le jeu
                virtual void update(arcade::Keys inputKey) = 0;

                // Retourne la map du jeu courrant
                virtual MapType getMap(void) = 0;

                // Retourne la map du fichier passé en paramètre (la stocke idéalemanement dans un attribut)
                virtual MapType getMapFromFile(std::string filepath) = 0;
        };
    } // namespace game
} // namespace arcade

#endif /* !IGAMEMODULE_HPP_ */
