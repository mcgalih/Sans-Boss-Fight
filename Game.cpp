#include "Game.hpp"
#include "MainMenu.hpp"

namespace Gl
{
	Game::Game(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new MainMenu(_data)));

		Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = _clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (_data->window.isOpen())
		{
			_data->machine.ProcessStateChanges();

			newTime = _clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				_data->machine.GetActiveState()->HandleInput();
				_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}