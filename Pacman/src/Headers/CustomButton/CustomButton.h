#pragma once

#include <SFML/Graphics.hpp>

#include "../../Engine/InteractionManager/InteractionManager.h"

#include <string>
#include <functional>

namespace ss
{
	class CustomButton
	{
	public:
		CustomButton() = default;
		CustomButton(
			const sf::Vector2f& rectPos,
			const sf::Vector2f& rectSize,
			const std::string& text,
			sf::Font* font,
			const int textSize,
			InteractionManager* im,
			const sf::Color& sColor = sf::Color::White,
			const sf::Color& cColor = sf::Color::Cyan
		);
		CustomButton(
			const sf::Vector2f& rectPos,
			const sf::Vector2f& rectSize,
			const std::string& text,
			sf::Font* font,
			const int textSize,
			InteractionManager* im,
			sf::Texture* sTexture,
			sf::Texture* cTexture
		);
		CustomButton(const CustomButton& b);
		~CustomButton();
		
		void setFont(const sf::Font* font);
		void setTextures(sf::Texture* sTex, sf::Texture* cTex);
		void setStyle(const sf::Text::Style& style);
		void setColors(const sf::Color& sColor, const sf::Color& cColor);

		void update(sf::RenderWindow& win);
		void draw(sf::RenderWindow& win);

		sf::RectangleShape& getRect();
		sf::Text& getText();

		bool wasClicked(const sf::Mouse::Button& btn, sf::RenderWindow& win);
	private:
		void setTextPosition();

		sf::Text text;
		sf::RectangleShape rect;
		
		InteractionManager* iMan;

		sf::Texture* sTex; // Starting texture.
		sf::Texture* cTex; // Texture change after mouse over it.
		sf::Color sCol; // Starting color
		sf::Color cCol; // Changed color

		bool _hasColor;
	};
}

