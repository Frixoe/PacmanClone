#pragma once

#include <SFML/Graphics.hpp>

namespace ss
{
	class Animation
	{
	public:
		Animation(int sX, int sY, int width, int height, const int tFrames);
		~Animation();

		std::vector<sf::IntRect>& getFrames();
		sf::IntRect& getFrame(const int);
		sf::IntRect& getCFrame();

		void update(float dt);

	private:
		static constexpr float holdTime = 0.1f;
		std::vector<sf::IntRect> frames;

		float tt;
		int cFrame; // The current frame of the animation. 0 INDEXED.
		int tFrames; // The total frames in the animation. NOT 0 INDEXED.
	};
}

