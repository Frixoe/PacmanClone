#include "Game.h"

namespace ss
{
	Game::Game(int width, int height, const std::string& title)
	{
		this->win.create(sf::VideoMode(width, height), title, sf::Style::Close);
		this->man.addState(std::make_shared<StartScreen>(&this->win, &this->man, &this->aMan, &this->iMan), false);

		this->run();
	}


	Game::~Game()
	{
	}

	void Game::run()
	{
		this->win.setFramerateLimit(60);

		float dt;
		sf::Clock clock;

		while (this->win.isOpen())
		{
			dt = clock.restart().asSeconds();

			this->man.handleEvents(this->win);
			this->man.updateStates(dt);

			this->win.clear();
			this->man.drawStates();
			this->win.display();
		}
	}
}

