#include "Player.h"


Player::Player(sf::Vector2f pos, sf::Vector2f size, float speed, sf::Texture tex)
	: Entity(pos, size), m_drawShape(size), m_speed(speed)
{
	player_tex = tex;
	sprite.setTexture(player_tex);
	sprite.setTextureRect(sf::IntRect(128,0,32,32));
	sprite.setPosition(m_position);
	//m_drawShape.setFillColor(sf::Color::White);
}


Player::~Player()
{
}

void Player::Move(float delta) {
	m_position += m_direction * m_speed * delta;
	sprite.setPosition(m_position);
}

void Player::SetDirection(sf::Vector2f newDir) {
	m_direction = newDir;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(sprite, states);
}