#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Map.h"
#include <vector>

#include <SFML\Graphics\Drawable.hpp>
class Level :
	public sf::Drawable
{
public:
	virtual void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Level::Update(float delta);
	Map m;
	std::vector<Enemy *> m_enemies;
	Player *m_player;
	Level();
	~Level();
private:
	sf::Texture player_texture;
};

