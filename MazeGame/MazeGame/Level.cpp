#include "Level.h"
#include "Layer.h"
#include "Tile.h"
#include <iostream>
Level::Level()
{
	player_texture.loadFromFile("Player_Sprite_Sheet_32_32.png");
	m_player = new Player(sf::Vector2f(0,0), sf::Vector2f(32, 32), 100.0f, player_texture);
	//m_player->sprite.
	m.loadFromFile("level1.tmx");
	//player_texture.loadFromFile("playersprite.png");
	//m_player->sprite.setTexture();
	//m_player->sprite.
}


Level::~Level()
{
}
void Level::Update(float delta){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_player->SetDirection(sf::Vector2f(-1, -1));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::UPLEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_player->SetDirection(sf::Vector2f(1, -1));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::UPRIGHT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_player->SetDirection(sf::Vector2f(-1, 1));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::DOWNLEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_player->SetDirection(sf::Vector2f(1, 1));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::DOWNRIGHT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_player->SetDirection(sf::Vector2f(0, -1));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::UP);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_player->SetDirection(sf::Vector2f(0, 1));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::DOWN);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_player->SetDirection(sf::Vector2f(-1, 0));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::LEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_player->SetDirection(sf::Vector2f(1, 0));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::RIGHT);
	}
	else {
		m_player->SetDirection(sf::Vector2f(0, 0));
		m_player->SetAnimDirection(Player::PLAYER_DIRECTION::IDLE);
	}
	m_player->Move(delta);
	if (m_player->Right()>320){
		sf::Vector2f dir = *m_player->GetDirection();
		dir.x *= -1;
		dir.y *= -1;
		m_player->SetDirection(dir);
		m_player->Move(delta);
	}
	if (m_player->Left() < 0){
		sf::Vector2f dir = *m_player->GetDirection();
		dir.x *= -1;
		dir.y *= -1;
		m_player->SetDirection(dir);
		m_player->Move(delta);
	}
	if (m_player->Top() < 0){
		sf::Vector2f dir = *m_player->GetDirection();
		dir.x *= -1;
		dir.y *= -1;
		m_player->SetDirection(dir);
		m_player->Move(delta);
	}
	if (m_player->Bottom() > 320){
		sf::Vector2f dir = *m_player->GetDirection();
		dir.x *= -1;
		dir.y *= -1;
		m_player->SetDirection(dir);
		m_player->Move(delta);
	}
	std::vector<Layer>* map_layers = m.GetLayers();
	for each (Layer l in *map_layers)
	{
		if (l.name == "Walls"){
			std::vector<std::vector<Tile>> wallTiles = *l.GetTiles();
			for (int y = 0; y < wallTiles.size(); y++){
				for (int x = 0; x < wallTiles[0].size(); x++) {
					gid id = wallTiles[y][x].GID;
					if (id == 86){
						if (m_player->GetBoundingBox().intersects(sf::FloatRect(x*16, y*16, 16, 16))){
							sf::Vector2f dir = *m_player->GetDirection();
							dir.x *= -1;
							dir.y *= -1;
							m_player->SetDirection(dir);
							m_player->Move(delta);
						}
					}
				}
			}
		}
	}
	//m_player->GetBoundingBox().intersects()
}
void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m, states);
	for (std::size_t i = 0; i < m_enemies.size(); i++) {
		target.draw(*m_enemies[i], states);
	}
	target.draw(*m_player, states);
}