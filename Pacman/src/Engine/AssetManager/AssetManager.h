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

		sf::Font* getFont(const std::string& name);
		sf::Font* getFont(const std::string& name, const std::string& fileName);

		sf::Texture* getTexture(const std::string& name);
		sf::Texture* getTexture(const std::string& name, const std::string& fileName);
	private:
		template<class T> inline bool hasElement(const std::string& name, const std::map<std::string, T>& map);

		void loadTexture(const std::string& name, const std::string& fileName);
		void loadFont(const std::string& name, const std::string& fileName);

		std::map<std::string, sf::Texture*> _textures;
		std::map<std::string, sf::Font*> _fonts;
	};

	template<class T>
	inline bool AssetManager::hasElement(const std::string & name, const std::map<std::string, T>& map)
	{
		return map.find(name) != map.end();
	}
}

