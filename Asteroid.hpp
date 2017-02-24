#include <sfml/Graphics.hpp>
#include <VectorMath.h>
#include <vector>
#include <random>
#include <Textures.hpp>

class Asteroid: public sf::Drawable, public sf::Transformable{
public:
	Asteroid();
	~Asteroid();
	
	void Movement(sf::Vector2f PlayerPosition,sf::Sprite* asteroid);
	void NewAsteroid(sf::Vector2f playerPos);
	void deleteAsteroid(int n_delete);
	std::vector<sf::Sprite> asteroidVector;
	void SpawnPoint();
	sf::FloatRect asteroidBox(sf::Sprite asteroid);
	
	
private:
	Texture txmgr;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states )const;
	int Asteroids;
	sf::Sprite aster;
	sf::Vector2f spawnPosition;
	bool isAlive;
};