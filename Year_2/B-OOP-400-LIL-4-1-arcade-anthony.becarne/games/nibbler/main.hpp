/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include "../../include/abstracts/AGameModule.hpp"
#include <fstream>

class Nibbler : public arcade::game::AGameModule {
	public:
		Nibbler(/* args */);
		~Nibbler();

		void launch(std::string) override;
		void keyInput(arcade::Keys inputKey) override;

		int getScore(void) override;
		void update(arcade::Keys inputKey) override;
		MapType getMap(void) override;
		arcade::State getState(void) override;
		std::string getGameName(void) override;
		MapType getMapFromFile(std::string filepath) override;

		void setState(arcade::State new_state);
		void endGame(void);
		void moveUp(void);
		void moveDown(void);
		void moveRight(void);
		void moveLeft(void);
		void setPos(void);
	
	private:
		arcade::State state;
        MapType map;
		int posx;
        int posy;
		int score;
};

