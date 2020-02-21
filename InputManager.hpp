#pragma once

#include <SFML/Graphics.hpp>

namespace Gl
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

		bool IsKeyPressed(sf::Keyboard::Key button);

		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};
}