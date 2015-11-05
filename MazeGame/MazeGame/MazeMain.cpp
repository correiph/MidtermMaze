#include <iostream>

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Level.h"
int main(int argc, char *argv[]) {
	std::cout << "Loading Maze Game" << std::endl;

	sf::RenderWindow window(sf::VideoMode(800, 600), "a-Maze'n Game");
	sf::Clock gameClock;
	float gameTime = 0.0f;
	float currentTime = 0.0f;
	float delta = 1.0f / 30.0f;
	bool running = true;
	Level *l1 = new Level();
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
			//Update the game.
			l1->Update(delta);
		}

		//Draw
		if (drawRequested) {
			window.clear();
			window.draw(*l1);
			window.display();
		}
	}

	window.close();
	return 0;
}