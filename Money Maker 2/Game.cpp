#include "Game.h"

Game::Game()
	:mEvent(sf::Event())
{
	mWindow = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Clicker!", sf::Style::Titlebar | sf::Style::Close);
	mWindow->setMouseCursorVisible(false);
}

Game::~Game()
{
	delete mWindow;
}

void Game::Run()
{
	while (mWindow->isOpen())
	{
		Update();
		Render();
	}
}

void Game::PollEvent()
{
	while (mWindow->pollEvent(mEvent))
	{
		switch (mEvent.type)
		{
		case sf::Event::Closed:
			mWindow->close();
			break;
		case sf::Event::KeyPressed:
			if (mEvent.key.code == sf::Keyboard::Key::Escape)
				mWindow->close();
			break;
		}
	}
}

void Game::Update()
{
	PollEvent();
	player.Update(mWindow);
}

void Game::Render()
{
	mWindow->clear();
	player.Render(*mWindow);
	mWindow->display();
}
