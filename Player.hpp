#pragma once
#include <sfml/Graphics.hpp>
#include <Textures.hpp>
class Player: public sf::Drawable, public sf::Transformable  {
public:
	Player();
	~Player();
	bool isDead;
	void loadTextures();
	void playerInput();
	void PlayerInit();
	float getRot();
	bool asteroidHit(sf::Sprite* Asteroid);
	sf::Vector2f CheckPosition();
private:
	Texture txmgr;
	int lives;
	float speedX; //Speed which will bet set in the constructor
	float speedY; //same as the speedX
	sf::Sprite player; //Player is the ship sprite which will be controlled by the player.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= getTransform();
		target.draw(player, states);
	}
	
};