#include "Layer.h"
#include <SFML/Graphics/RenderTarget.hpp>

Layer::Layer(std::string name) : m_width(0), m_height(0), name(name)
{
}


Layer::~Layer()
{
}

bool Layer::loadFromXML(tinyxml2::XMLElement *el) {
	m_width = el->IntAttribute("width");
	m_height = el->IntAttribute("height");
	tinyxml2::XMLElement *dataEl = el->FirstChildElement("data");
	tinyxml2::XMLElement *tileEl = dataEl->FirstChildElement("tile");
	for (int i = 0; i < m_height; i++) {
		m_tiles.push_back(std::vector<Tile>());
	}
	int x = 0;
	int y = 0;
	while (tileEl != NULL) {
		gid id = tileEl->IntAttribute("gid");
		m_tiles[y].push_back(Tile(id));
		x++;
		if (x >= m_width) {
			x = 0;
			y++;
		}
		tileEl = tileEl->NextSiblingElement("tile");
	}
	//y then x.
	return true;
}

void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Vector2i tilesize = m_tileSet->getTileSize();
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			gid id = m_tiles[y][x].GID;
			if (id > 0) {
				sf::Sprite &s = m_tileSet->getSprite(id);
				s.setPosition(tilesize.x * x, tilesize.y * y);
				target.draw(s, states);
			}
		}
	}
}
