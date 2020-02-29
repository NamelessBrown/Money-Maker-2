#pragma once

#include "Player.h"
#include "Button.h"

class Game
{
public:
	Game();
	Game(const Game&) = delete;
	Game operator=(const Game&) = delete;

	virtual ~Game();

	void Run();
private:
	sf::RenderWindow* mWindow;
	sf::Event mEvent;


	Player player;
	Button button;
	Button changeFont;

	void PollEvent();
	void Update();
	void Render();
};

