#pragma once

#include <SFML/Graphics.hpp>

class InteractionManager
{
public:
	InteractionManager();
	~InteractionManager();

	bool mouseOverShape(const sf::Shape& s, sf::RenderWindow& win);
	bool mouseOverSprite(const sf::Sprite& s, sf::RenderWindow& win);
};