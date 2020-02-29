#include "Game.h"

Game::Game()
	:mEvent(sf::Event()), button(sf::Vector2f(20, 300), "Reborn", sf::Color::Blue, sf::Vector2f(25.f, 25.f)),
	changeFont(sf::Vector2f(20, 350), "Change Font(Right click for normal)", sf::Color::Yellow, sf::Vector2f(25.f, 25.f))
{
	mWindow = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Money Maker 2!", sf::Style::Titlebar | sf::Style::Close);
	mWindow->setMouseCursorVisible(false);

	mWindow->setFramerateLimit(60);
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
		player.Reborn();
	} 
	
	if (changeFont.IsClicked(player.getSprite()))
	{
		std::cout << "Font changed! \n";
		player.ChangeFont("Font/times-new-roman.ttf");
		button.ChangeedFont("Font/times-new-roman.ttf");
		changeFont.ChangeedFont("Font/times-new-roman.ttf");
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		std::cout << "Font changed! \n";
		player.ChangeFont("Font/fast_money.ttf");
		button.ChangeedFont("Font/fast_money.ttf");
		changeFont.ChangeedFont("Font/fast_money.ttf");
	}


}

void Game::Render()
{
	mWindow->clear();
	player.Render(*mWindow);
	button.Draw(*mWindow);
	changeFont.Draw(*mWindow);
	mWindow->display();
}
