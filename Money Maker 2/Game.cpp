#include "Game.h"

Game::Game()
{
	mWindow = new sf::RenderWindow(sf::VideoMode(500, 500), "Clicker!", sf::Style::Titlebar | sf::Style::Close);
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
		}
	}
}

void Game::Update()
{
	PollEvent();
}

void Game::Render()
{
}
