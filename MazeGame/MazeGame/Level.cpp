#include "Level.h"
#include <iostream>

Level::Level(std::string levelName) : window(sf::VideoMode(800, 600), "Midterm Maze Game")
{
	
	sf::Clock gameClock;
	gameTime = 0.0f;
	currentTime = 0.0f;
	delta = 1.0f / 30.0f;
	running = true;

	std::cout << "Loading Level" << std::endl;
	m.loadFromFile(levelName);

	player_texture.loadFromFile("Player_Sprite_Sheet_32_32.png");
	m_player = new Player(sf::Vector2f(0,0), sf::Vector2f(16, 16), 100.0f, player_texture);
}

Level::~Level()
{
}

void Level::run()
{
	while (gameInPlay())
	{
		Update(delta);
	}
}

void Level::Update(float delta){
	
	while (running) {
		bool drawRequested = false;
		//Events
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				running = false;
			}
		}

		//Game Update
		while ((currentTime = gameClock.getElapsedTime().asSeconds()) > gameTime) {
			gameTime += delta;
 			drawRequested = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				m_player->SetDirection(sf::Vector2f(-1, -1));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				m_player->SetDirection(sf::Vector2f(1, -1));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				m_player->SetDirection(sf::Vector2f(-1, 1));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				m_player->SetDirection(sf::Vector2f(1, 1));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				m_player->SetDirection(sf::Vector2f(0, -1));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				m_player->SetDirection(sf::Vector2f(0, 1));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				m_player->SetDirection(sf::Vector2f(-1, 0));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				m_player->SetDirection(sf::Vector2f(1, 0));
			}
			else {
				m_player->SetDirection(sf::Vector2f(0, 0));
			}
			m_player->Move(delta);
		}

		//Draw
		if (drawRequested) {
			window.clear();
			window.draw(*this);
			window.display();
		}
	}
		window.close();
		return;
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m);
	/*
	for (std::size_t i = 0; i < m_enemies.size(); i++) {
		target.draw(*m_enemies[i], states);
	}
	*/
	target.draw(*m_player, states);
}


// check if the level is complete
bool Level::gameInPlay()
{
	//////////////////////////////////////////////////////////////////////////////////////////please fill me in with the second exit stairwell collisions check
	return true;
}