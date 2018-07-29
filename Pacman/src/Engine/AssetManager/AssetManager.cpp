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

	sf::Font * AssetManager::getFont(const std::string & name)
	{
		return this->hasElement(name, this->_fonts) ? this->_fonts.at(name) : nullptr;
	}

	sf::Font * AssetManager::getFont(const std::string & name, const std::string & fileName)
	{
		this->loadFont(name, fileName);
		return this->getFont(name);
	}

	sf::Texture * AssetManager::getTexture(const std::string & name)
	{
		return this->hasElement(name, this->_textures) ? this->_textures.at(name) : nullptr;
	}

	sf::Texture * AssetManager::getTexture(const std::string & name, std::string & fileName)
	{
		this->loadTexture(name, fileName);
		return this->getTexture(name);
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
}