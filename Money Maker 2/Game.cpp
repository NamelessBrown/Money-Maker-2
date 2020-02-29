#include "Game.h"

Game::Game()
	:mEvent(sf::Event()), button(sf::Vector2f(50, 500), "Upgrade Money", sf::Color::Blue, sf::Vector2f(50.f, 50.f))
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

	if (button.IsClicked(player.getSprite()))
	{
		std::cout << "Hit! \n";
		player.UpgradeMoneyMax();
	} 
	
}

void Game::Render()
{
	mWindow->clear();
	player.Render(*mWindow);
	button.Draw(*mWindow);
	mWindow->display();
}
