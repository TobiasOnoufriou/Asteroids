#include <Bullet.hpp>
#include <Textures.hpp>
#include <iostream>
Bullet::Bullet(){
	//this->loadTexture(); //Calling loadTexture to run the procedure and intialize the name of the texture and to set it in the texture manager.
	//this->bullet.setTexture(this->txmgr.getRef("Bullet")); //Pointer which will refer to the bullet and will refer to get ref
	//so no data is lost.
	speedX = 0;
	speedY = 0;
}
Bullet::~Bullet(){//Deconstructor
}
sf::Sprite Bullet::NewBullet(sf::Vector2f playerPos, float Rotation){
	txmgr.loadTexture("Bullet","Bullet.gif"); //In a vector list the texture file Bullet.gif will be set as Bullet
	this->bullet.setTexture(txmgr.getRef("Bullet"));
	this->bullet.setPosition(playerPos);
	this->bullet.setRotation(Rotation);
	return this->bullet;
}
void Bullet::bMove(sf::Sprite* bulletVec){
	bulletVec->move(sin((PI*bulletVec->getRotation())/180)*speedX,-cos((PI*bulletVec->getRotation())/180)*speedY);
	this->speedX += 1.5;
	this->speedY += 1.5;
	if(this->speedX >= 20 || this->speedY >= 20){
		this->speedX = 20;
		this->speedY = 20;
	}
}
sf::Vector2f Bullet::bulletPos(){
	return this->bullet.getPosition();
}
void Bullet::deleteBullet(int n_delete){
	BulletVec.erase(BulletVec.begin() + n_delete);
}
bool Bullet::CheckHit(sf::Sprite* Asteroid,sf::Sprite* bullets){
	sf::FloatRect rect;
	rect.height = bullets->getGlobalBounds().height;
	rect.width = bullets->getGlobalBounds().width;
	rect.left = bullets->getGlobalBounds().left;
	rect.top = bullets->getGlobalBounds().top;
	bool hit = false;
	if(rect.intersects(Asteroid->getGlobalBounds())){
		hit = true;
	}
	return hit;
}