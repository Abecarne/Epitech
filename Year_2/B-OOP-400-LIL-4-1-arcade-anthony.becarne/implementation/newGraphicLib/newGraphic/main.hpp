/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include "../../include/abstracts/AGameModule.hpp"
#include <fstream>

class NewGraphic : public arcade::game::IGameModule {
	public:
		NewGraphic(/* args */);
		~NewGraphic();

		void launch(std::string) override;
		void keyInput(arcade::Keys inputKey) override;

		void update(arcade::Keys inputKey) override;
		void setPos(void);
		MapType getMap(void) override;

		int getScore(void) override;
		arcade::State getState(void) override;
		std::string getGameName(void) override;
		MapType getMapFromFile(std::string filepath) override;

	private:
};

