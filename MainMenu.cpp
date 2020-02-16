#include "MainMenu.hpp"
#include <iostream>
#include "DEFINITIONS.hpp"

namespace Gl
{
	MainMenu::MainMenu(GameDataRef data) :_data(data)
	{

	}

	void MainMenu::Init()
	{
		_data->assets.LoadTexture("Main Menu", MAIN_MENU_FILE_PATH);
		_background.setTexture(_data->assets.GetTexture("Main Menu"));

		_background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		_background.setOrigin(sf::Vector2f
		(_background.getLocalBounds().width / 2, _background.getLocalBounds().height / 2));
		
	}

	void MainMenu::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}
	void MainMenu::Update(float dt)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			//switch to the game
			std::cout << "switch to game" << std::endl;
		}
	}
	void MainMenu::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.display();
	}

}