#include "Game.hpp"
#include "MainMenu.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	Game::Game(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new MainMenu(_data)));

		//load Sprite
		_data->assets.LoadTexture(MAIN_MENU_SPRITE, MAIN_MENU_FILE_PATH);
		_data->assets.LoadTexture(HEART_SPRITE, HEART_FILE_PATH);
		_data->assets.LoadTexture(SANS_START_HEAD_SPRITE, SANS_START_HEAD_FILE_PATH);
		_data->assets.LoadTexture(SANS_BODY, SANS_BODY_FILE_PATH);

		//load Sound
		_data->assets.LoadBuffer(SANS_SOUND, SANS_SOUND_FILE_PATH);
		_data->assets.LoadBuffer(BATTLE_START_SOUND, BATTLE_START_SOUND_FILE_PATH);
		_data->assets.LoadBuffer(GASTER_BLASTER_SOUND, GASTER_BLASTER_SOUND_FILE_PATH);

		//load Font
		_data->assets.LoadFont(HUD_FONT, FONT_HUD_FILE_PATH);
		_data->assets.LoadFont(DIALOG_FONT, DIALOG_FONT_FILE_PATH);

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