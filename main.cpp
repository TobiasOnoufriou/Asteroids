#include <iostream>
#include <Asteroid.hpp>
#include <Starfield.h>
#include <SFML\Graphics.hpp>
#include <Score.h>
#include <Player.hpp>
#include <Bullet.hpp>
#include <vector>


int main() {
	const int aSize = 5;
	bool isDead = false;
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Game");
	Score score;
	Player* player = new Player();
	Asteroid aster;
	Bullet bullet;
	Starfield* star[250];
	float speedX,speedY,newPlayerRotation,playerRotation;
	sf::Vector2f playerPos;
	playerPos = player->CheckPosition();
	
	sf::Shader shader;
	if(!shader.loadFromFile("colorShader.frag","vertexShader.vert")){
		std::cout << "File could not be found" << std::endl;
	}
	shader.setParameter("my_color_texture",sf::Shader::CurrentTexture);

	for(int l = 0; l < aSize; l++){
		aster.NewAsteroid(playerPos);
	}
	for (int i = 0; i < 250; i++) {
		star[i] = new Starfield();
	}
	speedX = 0;
	speedY = 0;
	
	while (window->isOpen()){
		sf::Event event;
		while (window->pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window->close();
			float Rotation;
			if(event.type == sf::Event::Resized){
				sf::FloatRect visableArea(0,0,event.size.width,event.size.height);
				window->setView(sf::View(visableArea));
			}
			if(event.type == sf::Event::KeyReleased ){
				if(event.key.code == sf::Keyboard::Space && !isDead){
						Rotation = player->getRot();	
						bullet.BulletVec.push_back(bullet.NewBullet(playerPos,Rotation));
						newPlayerRotation = player->getRot();
						break; 
					}
				}
			}
		//Player Intialization
		if(!isDead){
			player->playerInput();
			playerRotation = player->getRot();
			playerPos = player->CheckPosition();
		}	
		//AsteroidSetup

	
  		window->clear();
		
		for(int i = 0;i < aster.asteroidVector.size(); i++){
			aster.Movement(playerPos,&aster.asteroidVector[i]);
			
			window->draw(aster.asteroidVector[i]);
		}
		if(aster.asteroidVector.empty() == true){
			for(int l = 0; l < aSize; l++){
				aster.NewAsteroid(playerPos);
			}
		}
		for(int a = 0; a < bullet.BulletVec.size();a++){
			bullet.bMove(&bullet.BulletVec[a]);
			window->draw(bullet.BulletVec[a]);
			std::cout << a << std::endl;
			int n_delete = a;
			if(bullet.BulletVec[a].getPosition().y > WINDOW_HEIGHT || bullet.BulletVec[a].getPosition().y < WINDOW_HEIGHT - WINDOW_HEIGHT || bullet.BulletVec[a].getPosition().x > WINDOW_WIDTH || bullet.BulletVec[a].getPosition().x < WINDOW_WIDTH - WINDOW_WIDTH){
				bullet.deleteBullet(n_delete);				
			}
		}
		for (int i = 0; i < 250 ; i++) {
			star[i]->update();
			star[i]->draw();
			window->draw(*star[i],&shader);
		}
		//Collision Detection Validation.
		for(int a = 0; a < bullet.BulletVec.size();a++){
			for(int c = 0; c < aster.asteroidVector.size(); c++){
				if(bullet.CheckHit(&aster.asteroidVector[c],&bullet.BulletVec[a])){
					score.changeScore(75);
					bullet.deleteBullet(a);
					aster.deleteAsteroid(c);
					break;
				}	
			}
		}
		for(int l = 0;l < aster.asteroidVector.size(); l++){
			if(player->asteroidHit(&aster.asteroidVector[l])){
					player->PlayerInit();
					for(int k = 0; k < aster.asteroidVector.size();k++){
						aster.deleteAsteroid(k);
						aster.NewAsteroid(playerPos);
					}
				}
			}

		//Player render.
		if(!isDead){
			window->draw(*player,&shader);
		}
		//Bullet for loop render.
		
		window->draw(score);
		window->setKeyRepeatEnabled(false);
		window->setFramerateLimit(60);	
		window->display();
	}

	return EXIT_SUCCESS;
}