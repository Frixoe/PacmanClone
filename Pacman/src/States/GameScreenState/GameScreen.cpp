#include "GameScreen.h"

namespace ss
{
	GameScreen::GameScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im)
		: State(win, man, am, im)
	{
		this->rect = sf::RectangleShape(sf::Vector2f(200.0f, 200.0f));
		this->rect.setPosition({ 20.0f, 20.0f });

		// TODO: Add audio to the states.
	}

	GameScreen::~GameScreen()
	{
	}

	void GameScreen::handleEventsContent(sf::Event & evnt)
	{
		switch (evnt.type)
		{
		case sf::Event::KeyPressed:
			this->man->resumePrevState();
			break;
		}
	}

	void GameScreen::updateContent(float dt)
	{
	}

	void GameScreen::draw()
	{
		this->win->draw(this->rect);
	}
}