#include "CustomButton.h"

namespace ss
{
	CustomButton::CustomButton(
		const sf::Vector2f & rectPos,
		const sf::Vector2f & rectSize,
		const std::string & text,
		sf::Font* font,
		const int textSize,
		InteractionManager * im,
		const sf::Color & sColor,
		const sf::Color & cColor
	) : 
		iMan(im),
		rect(rectSize),
		sCol(sColor),
		cCol(cColor),
		text(text, *font, textSize),
		_hasColor(true)
	{
		this->rect.setPosition(rectPos);

		// Figure out the text position.
		this->setTextPosition();
	}

	CustomButton::CustomButton(
		const sf::Vector2f & rectPos,
		const sf::Vector2f & rectSize,
		const std::string & text,
		sf::Font * font,
		const int textSize,
		InteractionManager * im,
		sf::Texture * sTexture,
		sf::Texture * cTexture
	) :
		iMan(im),
		rect(rectSize),
		sTex(sTexture),
		cTex(cTexture),
		text(text, *font, textSize),
		_hasColor(false)
	{
		this->rect.setPosition(rectPos);

		// Figure out the text position.
		this->setTextPosition();
	}

	CustomButton::CustomButton(const CustomButton & b)
		: iMan(b.iMan), rect(b.rect), text(b.text), _hasColor(b._hasColor)
	{
		if (b._hasColor)
		{
			this->sCol = b.sCol;
			this->cCol = b.cCol;
		}
		else
		{
			this->sTex = b.sTex;
			this->cTex = b.cTex;
		}
	}

	CustomButton::~CustomButton()
	{
	}

	void CustomButton::setFont(const sf::Font * font)
	{
		this->text.setFont(*font);
	}

	void CustomButton::setTextures(sf::Texture * sTex, sf::Texture * cTex)
	{
		this->sTex = sTex;
		this->cTex = cTex;

		if (this->_hasColor) this->_hasColor = false;
	}

	void CustomButton::setStyle(const sf::Text::Style & style)
	{
		this->text.setStyle(style);
	}

	void CustomButton::setColors(const sf::Color & sColor, const sf::Color & cColor)
	{
		this->sCol = sColor;
		this->cCol = cColor;

		if (!this->_hasColor) this->_hasColor = true;
	}

	void CustomButton::update(sf::RenderWindow & win)
	{
		if (this->_hasColor)
		{
			if (this->iMan->mouseOverShape(this->rect, win)) this->rect.setFillColor(this->cCol);
			else this->rect.setFillColor(this->sCol);
		}
		else
		{
			if (this->iMan->mouseOverShape(this->rect, win)) this->rect.setTexture(this->cTex);
			else this->rect.setTexture(this->sTex);
		}
	}

	void CustomButton::draw(sf::RenderWindow & win)
	{
		win.draw(this->rect);
		win.draw(this->text);
	}
	
	sf::RectangleShape & CustomButton::getRect()
	{
		return this->rect;
	}

	sf::Text & CustomButton::getText()
	{
		return this->text;
	}

	bool CustomButton::wasClicked(const sf::Mouse::Button& btn, sf::RenderWindow & win)
	{
		return sf::Mouse::isButtonPressed(btn) && this->iMan->mouseOverShape(this->rect, win);
	}

	void CustomButton::setTextPosition()
	{
		// Get the width and heigth of the text.
		// Set the origin to the half of the width and the height.
		// Set the position of the text to: rect pos + (half of rect width and height)
		
		sf::FloatRect textBounds = this->text.getGlobalBounds();
		this->text.setOrigin({ textBounds.width / 2.0f, textBounds.height / 2.0f });
		this->text.setPosition(
			this->rect.getPosition() + (this->rect.getSize() / 2.0f)
		);
	}
}
