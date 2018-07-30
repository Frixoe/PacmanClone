#include "InteractionManager.h"



InteractionManager::InteractionManager()
{
}


InteractionManager::~InteractionManager()
{
}

bool InteractionManager::mouseOverShape(const sf::Shape & s, sf::RenderWindow & win)
{
	sf::Vector2i m = sf::Mouse::getPosition(win);
	return s.getGlobalBounds().contains((float) m.x, (float) m.y);
}

bool InteractionManager::mouseOverSprite(const sf::Sprite & s, sf::RenderWindow & win)
{
	sf::Vector2i m = sf::Mouse::getPosition(win);
	return s.getGlobalBounds().contains((float)m.x, (float)m.y);
}

bool InteractionManager::mouseOverBounds(const sf::FloatRect & f, sf::RenderWindow & win)
{
	return f.contains((float)sf::Mouse::getPosition(win).x, (float)sf::Mouse::getPosition(win).y);
}
