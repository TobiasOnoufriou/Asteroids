#include <sfml/Graphics.hpp>
#include <map>
#pragma once

class Texture {
private:
	 std::map<std::string, sf::Texture> textures;
public:
	void loadTexture(const std::string& name, const std::string &filename);
	sf::Texture& getRef(const std::string& texture);
};