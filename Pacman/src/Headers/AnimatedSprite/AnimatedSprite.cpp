#include "AnimatedSprite.h"

namespace ss
{
	AnimatedSprite::AnimatedSprite(sf::Texture* tex, const sf::Vector2f & size, const sf::Vector2f& sTexCoords, const sf::Vector2f& sPosCoords, const sf::Vector2f& tFrames, const sf::Vector2u& winBounds)
		: winBounds((float) winBounds.x, (float) winBounds.y),
		fSize(size),
		dir(0.0f, 0.0f),
		tex(tex),
		cAnim(0)
	{
		/*
		PARAMS:
			tex: The texture to be used for the animation.
			size: The size of each animated frame.
			sTexCoords: The starting coordinates of the animation,
				i.e, which frame of which animation(from the anims vector) to play first.
				FORMAT: (COORD of animation frame, COORD of animation to play from anims vector)
			sPosCoords: Starting coords of the sprite.
			tFrames: Total frames in each animation.
				FORMAT: (Total FRAMES, Total ANIMATIONS) Assuming that there are equal
					amount of frames in each animation.
			winBounds: The size of the window.
		*/

		this->setTexture(*this->tex);
		this->setPosition(sPosCoords);

		this->anims.reserve((int)tFrames.y);
		for (int i = 0; i < tFrames.y; ++i)
		{
			this->anims.emplace_back(
				sTexCoords.x,
				sTexCoords.y + (i * this->fSize.y),
				this->fSize.x,
				this->fSize.y,
				tFrames.x
			);
		}
	}

	AnimatedSprite::AnimatedSprite(const AnimatedSprite & a)
		: winBounds(a.winBounds),
		fSize(a.fSize),
		dir(a.dir),
		tex(a.tex),
		anims(a.anims)
	{
		this->setTexture(*this->tex);
	}

	AnimatedSprite::~AnimatedSprite()
	{
	}

	void AnimatedSprite::update(float dt)
	{
		this->anims.at(this->cAnim).update(dt);
		this->setSpriteRect();

		this->move(
			this->_vel * dt * this->dir.x,
			this->_vel * dt * this->dir.y
		);

		sf::Vector2f pos = this->getPosition();

		if (pos.x + (this->fSize.x * this->getScale().x) > this->winBounds.x)
			pos.x = this->winBounds.x - (this->fSize.x * this->getScale().x);
		else if (pos.x < 0) pos.x = 0.0f;

		if (pos.y + (this->fSize.y * this->getScale().y) > this->winBounds.y)
			pos.y = this->winBounds.y - (this->fSize.y * this->getScale().y);
		else if (pos.y < 0) pos.y = 0.0f;

		this->setPosition(pos);
	}

	void AnimatedSprite::setAnimationIndex(const int anim)
	{
		this->cAnim = anim;
	}

	void AnimatedSprite::addToDir(const sf::Vector2f & dir)
	{
		this->dir += dir;
	}

	void AnimatedSprite::setDir(const sf::Vector2f &dir)
	{
		this->dir = dir;
	}

	sf::Vector2f& AnimatedSprite::getWindowBounds()
	{
		return this->winBounds;
	}

	sf::Vector2f& AnimatedSprite::getFrameSize()
	{
		return this->fSize;
	}

	sf::Vector2f& AnimatedSprite::getDir()
	{
		return this->dir;
	}

	sf::Texture* AnimatedSprite::getTexture() const
	{
		return this->tex;
	}

	std::vector<Animation>& AnimatedSprite::getAnimations()
	{
		return this->anims;
	}

	void AnimatedSprite::setSpriteRect()
	{
		this->setTextureRect(this->anims[this->cAnim].getCFrame());
	}
}
