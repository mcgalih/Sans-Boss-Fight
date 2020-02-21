#include "MainMenu.hpp"
#include "DEFINITIONS.hpp"
#include "TransitionToGameplay.hpp"

namespace Gl
{
	MainMenu::MainMenu(GameDataRef data) :_data(data)
	{

	}

	void MainMenu::Init()
	{
		_background.setTexture(_data->assets.GetTexture(MAIN_MENU_SPRITE));

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
		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ))
		{
			_data->machine.RemoveState();
			_data->machine.AddState(StateRef(new TransitionToGameplay(_data)));
		}
	}
	void MainMenu::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.display();
	}

}