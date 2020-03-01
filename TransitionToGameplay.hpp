#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Gameplay.hpp"
#include "Objects.hpp"

namespace Gl
{
	class TransitionToGameplay : public State
	{
	public:
		TransitionToGameplay(GameDataRef data) :_data(data) { }

		void Init()
		{
			////////////////////////////////sprite/////////////////////////////////
			_heart.setTexture(_data->assets.GetTexture(HEART_SPRITE));
			_heart.setPosition(50, (SCREEN_HEIGHT / 2) - 10);

			_SansHead.setTexture(_data->assets.GetTexture(SANS_START_HEAD_SPRITE));
			_SansHead.setPosition(150, SCREEN_HEIGHT / 2 - 160);

			_SansHead.setOrigin(
			_SansHead.getLocalBounds().width / 2, _SansHead.getLocalBounds().height / 2);
			_SansHead.setScale(1.5f,1.5f);

			/////////////////////////////////sound////////////////////////////////
			_BattleStart.setBuffer(_data->assets.GetBuffer(BATTLE_START_SOUND));
			_BattleStart.play();

			_SansSound.setBuffer(_data->assets.GetBuffer(SANS_SOUND));
			SoundStatus = true;

			//////////////////////////////////font////////////////////////////////
			_DialogueFont.setFont(_data->assets.GetFont(DIALOG_FONT));
			_DialogueFont.setString("* Let's just get to\n  the point.");
			_DialogueFont.setLetterSpacing(2.3f);
			_DialogueFont.setCharacterSize(25);
			_DialogueFont.setPosition(300, 100);

			/////////////////////////////////shape////////////////////////////////
			DialogueBox.setSize(sf::Vector2f(700.0f, 200.0f));
			DialogueBox.setFillColor(sf::Color::Black);
			DialogueBox.setOutlineThickness(5.0f);
			DialogueBox.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 150);
			DialogueBox.setOrigin(
			DialogueBox.getLocalBounds().width/2, DialogueBox.getLocalBounds().height/2 );

			width = 300.0f;
			height = 35.0f;
			TypingMove1 = 0.0f;
			TypingMove2 = 0.0f;
			Typing1.setPointCount(4);
			Typing1.setPosition(330, 100);
			Typing1.setFillColor(sf::Color::Black);

			Typing2.setPointCount(4);
			Typing2.setPosition(330, 135);
			Typing2.setFillColor(sf::Color::Black);
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
			if (_clock.getElapsedTime().asMilliseconds() >= 2000)
			{
				Typing1.setPoint(0, sf::Vector2f(TypingMove1, 0.0f));
				Typing1.setPoint(1, sf::Vector2f(width, 0.0f));
				Typing1.setPoint(2, sf::Vector2f(width, height));
				Typing1.setPoint(3, sf::Vector2f(TypingMove1, height));

				Typing2.setPoint(0, sf::Vector2f(TypingMove2, 0.0f));
				Typing2.setPoint(1, sf::Vector2f(width, 0.0f));
				Typing2.setPoint(2, sf::Vector2f(width, height));
				Typing2.setPoint(3, sf::Vector2f(TypingMove2, height));
	
				TypingMove1 += 6.0f;
				if (TypingMove1 > width)
				{
					TypingMove1 -= 6.0f;
					TypingMove2 += 6.0f;
					if (TypingMove2 > width/2 + 25)
					{
						SoundStatus = false;
						TypingMove2 -= 6.0f;
					}
				}

				if (SoundStatus == false)
				{
					_SansSound.stop();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						_data->machine.RemoveState();
						_data->machine.AddState(StateRef(new Gameplay(_data)));
					}
				}
				else
				{
					SoundTime = _SansSound.getPlayingOffset();
					_SansSound.play();
					_SansSound.setPlayingOffset(SoundTime);
				}
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
				_data->window.draw(DialogueBox);
				_data->window.draw(_SansHead);
			}
			if (_clock.getElapsedTime().asMilliseconds() >= 2000)
			{
				_data->window.draw(_DialogueFont);
				_data->window.draw(Typing1);
				_data->window.draw(Typing2);
			}
			_data->window.display();
		}

	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _heart, _SansHead;
		sf::Sound _BattleStart, _SansSound;
		sf::RectangleShape DialogueBox;
		sf::ConvexShape Typing1, Typing2;
		float width, height, TypingMove1, TypingMove2;
		int x = 0;
		sf::Time SoundTime;
		sf::Text _DialogueFont;
		bool SoundStatus;
	};
}

