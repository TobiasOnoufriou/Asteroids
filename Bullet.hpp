#include <sfml/Graphics.hpp>
#include <Player.hpp>

#include <Constants.hpp>
#include <vector>

class Bullet: public sf::Drawable, public sf::Transformable {
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states ) const {
		states.transform *= getTransform();
		target.draw(bullet, states);
	}
	int speedX, speedY;
	sf::IntRect bRect;
	sf::Clock clock;
	sf::Sprite bullet;
	Texture txmgr;
public:
	void bMove(sf::Sprite* bulletVec);
	sf::Vector2f bulletPos();
	std::vector<sf::Sprite> BulletVec;
	void deleteBullet(int n_delete);
	bool CheckHit(sf::Sprite* AsteroidPos, sf::Sprite* bullets);
	sf::Sprite NewBullet(sf::Vector2f playerPos, float Rotation);
	Bullet();
	~Bullet();
};