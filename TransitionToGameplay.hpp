#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Gl
{
	class TransitionToGameplay : public State
	{
	public:
		TransitionToGameplay(GameDataRef data) :_data(data) { }

		void Init()
		{
			_heart.setTexture(_data->assets.GetTexture("heart"));
			_heart.setPosition(50, (SCREEN_HEIGHT / 2) - 10);

			_SansHead.setTexture(_data->assets.GetTexture("Sans Start Head"));
			_SansHead.setPosition(150, SCREEN_HEIGHT / 2 - 160);

			_SansHead.setOrigin(
			_SansHead.getLocalBounds().width / 2, _SansHead.getLocalBounds().height / 2);
			_SansHead.setScale(1.5f,1.5f);

			buffer1.loadFromFile(BATTLE_START_SOUND_FILE_PATH);
			_BattleStart.setBuffer(buffer1);
			_BattleStart.play();

			buffer2.loadFromFile(SANS_SOUND_FILE_PATH);
			_SansSound.setBuffer(buffer2);

			SansDialogue.setSize(sf::Vector2f(700.0f, 200.0f));
			SansDialogue.setFillColor(sf::Color::Black);
			SansDialogue.setOutlineThickness(5.0f);
			SansDialogue.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 150);
			SansDialogue.setOrigin(
			SansDialogue.getLocalBounds().width/2, SansDialogue.getLocalBounds().height/2 );
		}

		void HandleInput()
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

		void Update(float dt)
		{
			if (_clock.getElapsedTime().asMilliseconds() >= 500)
			{
				_heart.setPosition(50 + x, (SCREEN_HEIGHT / 2) - 10);
				x += 7;
				if (x > 161) x -= 7;
			}
			if (_clock.getElapsedTime().asMilliseconds() >= 1800)
			{
				SoundTime = _SansSound.getPlayingOffset();
				_SansSound.play();
				_SansSound.setPlayingOffset(SoundTime);
			}
		}

		void Draw(float dt)
		{
			_data->window.clear();
			if (_clock.getElapsedTime().asMilliseconds() <= 1100)
			{
				if (_clock.getElapsedTime().asMilliseconds() >= 350)
				{
					if (_clock.getElapsedTime().asMilliseconds() <= 400)
					_data->window.draw(_heart);
				}
				if (_clock.getElapsedTime().asMilliseconds() >= 500)
				_data->window.draw(_heart);
			}
			if (_clock.getElapsedTime().asMilliseconds() >= 1800)
			{
				_data->window.draw(SansDialogue);
				_data->window.draw(_SansHead);
			}
			_data->window.display();
		}

	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _heart, _SansHead;
		sf::SoundBuffer buffer1, buffer2;
		sf::Sound _BattleStart, _SansSound;
		sf::RectangleShape SansDialogue;
		int x = 0;
		sf::Time SoundTime;
	};
}

