#include "MainMenu.hpp"
#include <sstream>
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
		if (_clock.getElapsedTime().asSeconds() > 5)
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