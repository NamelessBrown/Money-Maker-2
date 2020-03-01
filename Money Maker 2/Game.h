#pragma once

#include "Player.h"
#include "Button.h"
#include "Music.h"

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
	Music music;

	Button button;
	Button changeFont;
	Button musicButton;
	Button quitButton;

	void PollEvent();
	void Update();
	void ButtonAction();
	void Render();
};

