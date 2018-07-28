#include "AssetManager.h"

namespace ss
{
	AssetManager::AssetManager()
	{
	}


	AssetManager::~AssetManager()
	{
		if (!this->_textures.empty())
			for (auto x : this->_textures) delete x.second;

		if (!this->_fonts.empty())
			for (auto y : this->_fonts) delete y.second;
	}

	void AssetManager::loadTexture(const std::string & name, const std::string & fileName)
	{
		sf::Texture* tex = new sf::Texture();

		if (tex->loadFromFile(fileName)) this->_textures[name] = tex;
		else std::cout << "Could not load texture at: " << fileName << std::endl;
	}

	void AssetManager::loadFont(const std::string & name, const std::string & fileName)
	{
		sf::Font* font = new sf::Font();

		if (font->loadFromFile(fileName)) this->_fonts[name] = font;
		else std::cout << "Could not load font at: " << fileName << std::endl;
	}

	sf::Font * AssetManager::getFont(const std::string & name)
	{
		return this->_fonts.find(name) != this->_fonts.end() ? this->_fonts.at(name) : nullptr;
	}

	sf::Texture * AssetManager::getTexture(const std::string & name)
	{
		return this->_textures.find(name) != this->_textures.end() ? this->_textures.at(name) : nullptr;
	}
}