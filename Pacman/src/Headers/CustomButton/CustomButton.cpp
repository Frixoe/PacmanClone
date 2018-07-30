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
		bool onlyText,
		const sf::Color & sColor,
		const sf::Color & cColor
	) :
		iMan(im),
		rect(rectSize),
		text(text, *font, textSize),
		textSize(textSize),
		_hasRectColor(true),
		_changesTextColor(false),
		_onlyText(onlyText)
	{
		this->rect.setPosition(rectPos);

		if (this->_onlyText)
		{
			this->sTCol = sColor;
			this->cTCol = cColor;
			this->_changesTextColor = true;

			this->rect.setSize({ this->text.getGlobalBounds().width, this->text.getGlobalBounds().height });
		}
		else
		{
			this->sCol = sColor;
			this->cCol = cColor;
		}

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
		textSize(textSize),
		_hasRectColor(false),
		_changesTextColor(false),
		_onlyText(false)
	{
		this->rect.setPosition(rectPos);

		// Figure out the text position.
		this->setTextPosition();
	}

	CustomButton::CustomButton(const CustomButton & b)
		: 
		iMan(b.iMan),
		rect(b.rect),
		text(b.text),
		textSize(b.textSize),
		_hasRectColor(b._hasRectColor),
		_changesTextColor(b._changesTextColor),
		_onlyText(b._onlyText)
	{
		if (b._hasRectColor)
		{
			this->sCol = b.sCol;
			this->cCol = b.cCol;
		}
		else
		{
			this->sTex = b.sTex;
			this->cTex = b.cTex;
		}

		if (b._changesTextColor)
		{
			this->sTCol = b.sTCol;
			this->cTCol = b.cTCol;
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

		if (this->_hasRectColor) this->_hasRectColor = false;
	}

	void CustomButton::setStyle(const sf::Text::Style & style)
	{
		this->text.setStyle(style);
	}

	void CustomButton::setColors(const sf::Color & sColor, const sf::Color & cColor)
	{
		this->sCol = sColor;
		this->cCol = cColor;

		if (!this->_hasRectColor) this->_hasRectColor = true;
	}

	void CustomButton::setTextColors(const sf::Color & sColor, const sf::Color & cColor)
	{
		this->_changesTextColor = true;

		this->sTCol = sColor;
		this->cTCol = cColor;
	}

	void CustomButton::setPosition(const sf::Vector2f & pos)
	{
		this->rect.setPosition(pos);
		this->setTextPosition();
	}

	void CustomButton::update(sf::RenderWindow & win)
	{
		if (this->_hasRectColor)
		{
			if (this->iMan->mouseOverShape(this->rect, win)) this->rect.setFillColor(this->cCol);
			else this->rect.setFillColor(this->sCol);
		}
		else
		{
			if (this->iMan->mouseOverShape(this->rect, win)) this->rect.setTexture(this->cTex);
			else this->rect.setTexture(this->sTex);
		}

		if (this->_onlyText) this->rect.setFillColor(sf::Color(0, 0, 0, 0));

		if (
			this->_changesTextColor &&
			(this->iMan->mouseOverBounds(this->text.getGlobalBounds(), win) || 
			this->iMan->mouseOverShape(this->rect, win)) this->text.setFillColor(this->cTCol);
		else this->text.setFillColor(this->sTCol);
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
