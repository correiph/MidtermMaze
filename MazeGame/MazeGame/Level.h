#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Map.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Graphics\Drawable.hpp>

/* This class is reponsible for holding the current game at play including:
-the map
-the game updates polled from keyboard events
-the game updates determined from collisions
-the check for winning
-the rendering visually of the game
-the game window
-initializing the ai and level to play (initialization of things)
*/

class Level :
	public sf::Drawable
{
public:
	
	Map m;
	sf::RenderWindow window;

	Level(std::string leveName);
	~Level();

	std::vector<Enemy *> m_enemies;
	Player *m_player;

	virtual void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Level::Update(float delta);
	void run();

private:

	bool gameInPlay(); // check for the level win

	sf::Texture player_texture;

	sf::Clock gameClock;
	float gameTime;
	float currentTime;
	float delta;
	bool running = true;
};

