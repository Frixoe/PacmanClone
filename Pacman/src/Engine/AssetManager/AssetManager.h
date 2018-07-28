#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>

namespace ss
{
	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		void loadTexture(const std::string& name, const std::string& fileName);
		void loadFont(const std::string& name, const std::string& fileName);

		sf::Font* getFont(const std::string& name);
		sf::Texture* getTexture(const std::string& name);

	private:
		std::map<std::string, sf::Texture*> _textures;
		std::map<std::string, sf::Font*> _fonts;
	};
}

