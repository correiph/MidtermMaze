#include "Map.h"
#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include "tinyxml2.h"

Map::Map() : m_width(0), m_height(0), m_tileWidth(0), m_tileHeight(0)
{
}


Map::~Map()
{
}

bool Map::loadFromFile(std::string file) {
	tinyxml2::XMLDocument doc;
	doc.LoadFile(file.c_str());
	tinyxml2::XMLElement *mapEl = doc.FirstChildElement("map");
	if (mapEl == NULL) {
		std::cout << "Error, cannot find Map Element in " << file << std::endl;
		return false;
	}
	m_width = mapEl->IntAttribute("width");
	m_height = mapEl->IntAttribute("height");
	m_tileWidth = mapEl->IntAttribute("tilewidth");
	m_tileHeight = mapEl->IntAttribute("tileheight");
	tinyxml2::XMLElement *tilesetEl = mapEl->FirstChildElement("tileset");
	m_tileset.loadFromXML(tilesetEl);

	tinyxml2::XMLElement *layerEl = mapEl->FirstChildElement("layer");
	while (layerEl != NULL) {
		m_layers.push_back(Layer(layerEl->Attribute("name")));
		m_layers.back().loadFromXML(layerEl);
		m_layers.back().SetTileSet(m_tileset);
		layerEl = layerEl->NextSiblingElement("layer");
	}
	return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (std::size_t i = 0; i < m_layers.size(); i++) {
		target.draw(m_layers[i], states);

	}
}
