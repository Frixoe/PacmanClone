#include "StartScreen.h"

namespace ss
{
	StartScreen::StartScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im)
		: State(win, man, am, im)
	{
		this->rect = sf::RectangleShape(sf::Vector2f(100, 100));
		this->rect.setPosition(sf::Vector2f(0, 0));
		this->rect.setFillColor(sf::Color::Cyan);
		/*this->aMan->loadTexture("pacman_spritesheet", "src/Resources/pacman_spritesheet.png");

		sf::Texture* tex = this->aMan->getTexture("pacman_spritesheet");

		this->pacman = AnimatedSprite(
			tex,
			{ tex->getSize().x / 3.0f, tex->getSize().y / 4.0f },
			{ 0.0f, 0.0f },
			{ 0.0f, 0.0f },
			{ 3.0f, 4.0f },
			{ this->win->getSize().x, this->win->getSize().y }
		);
		this->pacman.setScale({ 2, 2 });*/
	}

	StartScreen::~StartScreen()
	{
	}

	void StartScreen::handleEventsContent(sf::Event & evnt)
	{
	}

	void StartScreen::updateContent(float dt)
	{
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->pacman.setAnimationIndex(2);
			this->pacman.setDir({ 0, -1 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->pacman.setAnimationIndex(1);
			this->pacman.setDir({ -1, 0 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->pacman.setAnimationIndex(0);
			this->pacman.setDir({ 1, 0 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->pacman.setAnimationIndex(3);
			this->pacman.setDir({ 0, 1 });
		}
		this->pacman.update(dt);*/
	}

	void StartScreen::draw()
	{
		this->win->draw(this->rect);
		//this->win->draw(this->pacman);
	}
}

