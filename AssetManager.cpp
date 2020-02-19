#include "AssetManager.hpp"

namespace Gl
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture text;

		if (text.loadFromFile(fileName))
		{
			_textures[name] = text;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return _textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		return _fonts.at(name);
	}

	void AssetManager::LoadBuffer(std::string name, std::string fileName)
	{
		sf::SoundBuffer buffer;

		if (buffer.loadFromFile(fileName))
		{
			_buffer[name] = buffer;
		}
	}

	sf::SoundBuffer& AssetManager::GetBuffer(std::string name)
	{
		return _buffer.at(name);
	}
}