#include "Animation.h"

namespace ss
{
	Animation::Animation(int sX, int sY, int width, int height, const int tFrames)
		: tt(0.0f), cFrame(0), tFrames(tFrames)
	{
		this->frames.reserve(tFrames);
		for (int i = 0; i < tFrames; ++i)
		{
			this->frames.emplace_back(
				sX + (i * width),
				sY,
				width,
				height
			);
		}
	}

	Animation::~Animation()
	{
	}

	std::vector<sf::IntRect>& Animation::getFrames()
	{
		return this->frames;
	}

	sf::IntRect & Animation::getFrame(const int idx)
	{
		return this->frames[idx];
	}

	sf::IntRect & Animation::getCFrame()
	{
		return this->frames[this->cFrame];
	}

	void Animation::update(float dt)
	{
		tt += dt;
		while (tt >= this->holdTime)
		{
			tt -= this->holdTime;

			this->cFrame++;
			if (this->cFrame > this->tFrames - 1) this->cFrame = 0;
		}
	}
}
