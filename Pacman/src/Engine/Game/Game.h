#pragma once

#include <iostream>
#include <string>

#include "../StateManager/StateManager.h"
#include "../AssetManager/AssetManager.h"
#include "../InteractionManager/InteractionManager.h"
#include "../../States/StartScreenState/StartScreen.h"

namespace ss
{
	class Game
	{
	public:
		Game(int, int, const std::string&);
		~Game();

	private:
		void run();

		sf::RenderWindow win;

		StateManager man;
		AssetManager aMan;
		InteractionManager iMan;
	};
}

