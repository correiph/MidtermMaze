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
<<<<<<< HEAD
	m_drawShape.setPosition(m_position);
	if (frame_tick < 14)
	{
		//if (walking_dir != PLAYER_DIRECTION::IDLE)
		frame_tick += 1;
	}
	
	else
	{
		if (walking_frame < 3){
			walking_frame += 1;
		}
		else {
			walking_frame = 0;
		}
		frame_tick = 0;
		//if (walking_dir != PLAYER_DIRECTION::IDLE)
		m_drawShape.setTextureRect(sf::IntRect(walking_frame * 32, 32 * walking_dir, 32, 32));
	}
=======
	sprite.setPosition(m_position);
>>>>>>> master
}

void Player::SetDirection(sf::Vector2f newDir) {
	m_direction = newDir;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(sprite, states);
}