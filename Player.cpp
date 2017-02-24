#include <Player.hpp>
#include <Constants.hpp>
#include <Textures.hpp>
#include <Bullet.hpp>
#include <iostream>

Player::Player(){
	isDead = false;
	this->PlayerInit();
}
Player::~Player(){
	
}
void Player::loadTextures(){
	txmgr.loadTexture("Ship","Ship.png");
}
float Player::getRot(){
	float Rotation;
	Rotation = this->player.getRotation();
	return Rotation;
}
sf::Vector2f Player::CheckPosition(){
	float xPos, yPos; //Initialization of the variables xPos and yPos. 
	xPos = this->player.getPosition().x;
	yPos = this->player.getPosition().y;
	sf::Vector2f playerPos(player.getPosition().x, player.getPosition().y);
	if(yPos <= -50){
		this->player.setPosition(xPos,yPos + WINDOW_HEIGHT );
	}else if(yPos >= WINDOW_HEIGHT){
		this->player.setPosition(xPos,yPos - (WINDOW_HEIGHT + 60));
	}
	if(xPos >= WINDOW_WIDTH){
		this->player.setPosition(xPos-(WINDOW_WIDTH+60), yPos);
	}else if(xPos <= -60){
		this->player.setPosition(xPos + WINDOW_WIDTH, yPos);
	}
	return playerPos;
}
void Player::PlayerInit(){
	this->loadTextures();
	this->player.setTexture(txmgr.getRef("Ship"));
	this->player.setPosition(sf::Vector2f(WINDOW_HEIGHT/2,WINDOW_WIDTH/2)); //Setting the position of the player.
	this->speedX = 0; //The speed is set to zero as it will increase due to the velocity value I will be adding.
	this->speedY = 0;
	this->player.setOrigin(sf::Vector2f(50.f,50.f)); //Origin of the sprite which is where the sprite will rotate from.
}
bool Player::asteroidHit(sf::Sprite* Asteroid){
	bool hit = false;
	sf::FloatRect pRect;
	pRect.height = this->player.getGlobalBounds().height;
	pRect.left = this->player.getGlobalBounds().left;
	pRect.top = this->player.getGlobalBounds().top;
	pRect.width = this->player.getGlobalBounds().width;
	if(pRect.intersects(Asteroid->getGlobalBounds())){
		hit = true;
		lives--;
	}
	return hit;
}

void Player::playerInput(){
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		while(speedX <= 10.5f || speedY >= -10.5f){
			this->speedX += 0.01f;
			this->speedY -= 0.01f;
			if(this->speedX == 12.5f){
				this->speedX = 12.5f;
			}
			else if(speedY == -12.5f){
				this->speedY = -12.5f;
			}
		}
		
	}
	else {
		if(abs(this->speedX) <= 0.2f){
			this->speedX = 0;
		}else{
			this->speedX -= 0.075f;
		}
		if(abs(speedY) <= 0.2f ){
			this->speedY = 0;
		}else{
			this->speedY += 0.075f;
		}
		
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		while (this->speedY <= -0.1 || speedX >= 0.1){
			this->speedX -= 0.1f;
			this->speedY += 0.1f;
			if(this->speedX >= 0.1f || this->speedY <= -0.1f){
					break;
				} 
			}
		}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			this->player.rotate(-3.75f);
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			this->player.rotate(3.75f);
		}
		this->player.move(sin(PI*this->player.getRotation()/180)*speedX ,cos(PI*this->player.getRotation()/180)* speedY); 
}
