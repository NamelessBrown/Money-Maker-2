#pragma once

#include <SFML/Graphics.hpp>

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

	void PollEvent();
	void Update();
	void Render();
};

