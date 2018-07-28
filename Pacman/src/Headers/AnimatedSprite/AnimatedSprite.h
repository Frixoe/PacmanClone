#pragma once
#include <SFML/Graphics.hpp>
#include "../Animation/Animation.h"

#include <vector>

namespace ss
{
	class AnimatedSprite : public sf::Sprite
	{
	public:
		AnimatedSprite() = default;
		AnimatedSprite(
			sf::Texture* tex,
			const sf::Vector2f& size,
			const sf::Vector2f& sTexCoords,
			const sf::Vector2f& sPosCoords,
			const sf::Vector2f& tFrames,
			const sf::Vector2u& winBounds);
		AnimatedSprite(const AnimatedSprite& a);
		~AnimatedSprite();

		void update(float dt);
		void setAnimationIndex(const int);
		void addToDir(const sf::Vector2f&);
		void setDir(const sf::Vector2f&);

		sf::Vector2f& getWindowBounds();
		sf::Vector2f& getFrameSize();
		sf::Vector2f& getDir();
		sf::Texture* getTexture() const;
		std::vector<Animation>& getAnimations();

	private:
		void setSpriteRect();

		sf::Vector2f winBounds;
		sf::Vector2f fSize;
		sf::Vector2f dir;
		sf::Texture* tex;

		std::vector<Animation> anims;
		int cAnim;

		static constexpr float _vel = 100.0f;
	};
}

