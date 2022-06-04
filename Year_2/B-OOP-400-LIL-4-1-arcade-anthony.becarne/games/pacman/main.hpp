/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** lib_a
*/

#include "../../include/abstracts/AGameModule.hpp"
#include <fstream>
#include <chrono>
#include <ctime>
#include <cmath>

class Timer {
   public:
      Timer();
      ~Timer();
      void start(void);
      void stop(void);      
      double NowMilliseconds(void);      
      double NowSeconds(void);

   private:
      std::chrono::time_point<std::chrono::system_clock> startTime;
      std::chrono::time_point<std::chrono::system_clock> stopTime;
      bool running;
};

class Pacman : public arcade::game::AGameModule {
   public:
      Pacman();
      ~Pacman();

      void launch(std::string filemap) override;
      void keyInput(arcade::Keys inputKey) override;

      int getScore(void) override;
      arcade::State getState(void) override;
      void update(arcade::Keys inputKey) override;
      MapType getMap(void) override;

      std::string getGameName(void) override;
      MapType getMapFromFile(std::string filepath) override;

      void setState(arcade::State new_state);
      void endGame(void);
      void moveUp(void);
      void moveDown(void);
      void moveRight(void);
      void moveLeft(void);
      void moveGhost(void);
      void setPos(void);

   private:
         arcade::State state;
         MapType map;
         int posx;
         int posy;
         int score;
         int startGhost;

         Timer time;
};