#include <Asteroid.hpp>
#include <Constants.hpp>
#include <iostream>
Asteroid::Asteroid(){
}
Asteroid::~Asteroid(){
}
//Random Spawn Point for the asteroid.
void Asteroid::SpawnPoint(){
	
	int HxPos, HyPos, LxPos, LyPos,MxPos,MyPos,rX, rY;
	rX = 0;
	rY = 0;
	MxPos = WINDOW_WIDTH / 2 - 100;
	MyPos = WINDOW_HEIGHT / 2 - 100;
	HxPos = WINDOW_HEIGHT + 100;
	HyPos = WINDOW_WIDTH + 100;
	LxPos = (WINDOW_HEIGHT - WINDOW_HEIGHT) - 100 ;
	LyPos = (WINDOW_WIDTH - WINDOW_WIDTH) - 100;
	int SpawnPoints[3][3] = {
		{LxPos,MxPos,HxPos},
		{HyPos,MyPos,LyPos}
	};
	 

	
	srand (std::rand());
	std::mt19937 rng(std::rand());
	std::uniform_int_distribution<int> genX(0,2);
	std::uniform_int_distribution<int> genY(0,2);
	rX = genX(rng);
	rY = genY(rng);
	//Delete after finished.
	spawnPosition.x = SpawnPoints[rX][NULL];
	spawnPosition.y = SpawnPoints[NULL][rY];
	
	std::cout << "xPos :" << rX << std::endl;
	std::cout << "yPos :" << rY << std::endl;

	
}
void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform *= getTransform();
	target.draw(this->aster,states);
}
void Asteroid::deleteAsteroid(int n_delete){
	asteroidVector.erase(asteroidVector.begin() + n_delete);
}
void Asteroid::NewAsteroid(sf::Vector2f playerPosition){
	
	SpawnPoint();
	std::cout << "Spawn x: " << spawnPosition.x << std::endl;
	std::cout << "spawn y: " << spawnPosition.y << std::endl;
	this->aster.setOrigin(72.5f,72.5f);
	this->aster.setPosition(spawnPosition);
	txmgr.loadTexture("Asteroid","Astroid-Large.gif");
	this->aster.setTexture(txmgr.getRef("Asteroid"));
	this->asteroidVector.push_back(aster);
}

void Asteroid::Movement(sf::Vector2f PlayerPosition,sf::Sprite* asteroid){
	asteroid->move(VectorMath::normalizeX(PlayerPosition,asteroid->getPosition())*0.75f,VectorMath::normalizeY(PlayerPosition,asteroid->getPosition())*0.75f);
	//asteroid->move(-sin((PI*asteroid->getRotation())/180)*0.5f,-cos((PI*asteroid->getRotation())/180)*0.5f);
}
