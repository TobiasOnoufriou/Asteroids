
#include <Textures.hpp>
#include <map>

void Texture::loadTexture(const std::string& name, const std::string& filename)
{
	sf::Texture tex;
	tex.loadFromFile(filename);

	textures[name] = tex;
	return;
}
sf::Texture& Texture::getRef(const std::string& texture)
{
	return textures.at(texture);
}