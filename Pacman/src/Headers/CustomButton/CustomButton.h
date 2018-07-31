#pragma once

#include <SFML/Graphics.hpp>

#include "../../Engine/InteractionManager/InteractionManager.h"

#include <string>

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
			bool onlyText,
			const int id,
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
			const int id,
			sf::Texture* sTexture,
			sf::Texture* cTexture
		);
		CustomButton(const CustomButton& b);
		~CustomButton();
		
		void setFont(const sf::Font* font);
		void setTextures(sf::Texture* sTex, sf::Texture* cTex);
		void setStyle(const sf::Text::Style& style);
		void setColors(const sf::Color& sColor, const sf::Color& cColor);
		void setTextColors(const sf::Color& sColor, const sf::Color& cColor);
		void setPosition(const sf::Vector2f& pos);

		void update(sf::RenderWindow& win, const int id);
		void draw(sf::RenderWindow& win);

		sf::RectangleShape& getRect();
		sf::Text& getText();

		bool wasClicked(const sf::Mouse::Button& btn, sf::RenderWindow& win);
		bool idMatch(const int id);

		bool wasClickedOrPressed(const sf::Mouse::Button& btn, sf::RenderWindow& win, const int id);
	private:
		void setTextPosition();

		sf::Text text;
		sf::RectangleShape rect;
		
		InteractionManager* iMan;

		sf::Texture* sTex; // Starting texture of the rect.
		sf::Texture* cTex; // Texture change after mouse over it(RECT).

		sf::Color sCol; // Starting color of the rect.
		sf::Color cCol; // Changed color of the rect.

		sf::Color sTCol; // Starting text color.
		sf::Color cTCol; // Changed text color.

		int id;

		int textSize;

		bool _hasRectColor;
		bool _changesTextColor;
		bool _onlyText;
	};
}

