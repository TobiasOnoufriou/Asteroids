#include <sfml/Graphics.hpp>
#include <iostream>

	class VectorMath {
	public:
	//works out normalization for the x co-ord of the vector
	static float normalizeX(sf::Vector2f endVec, sf::Vector2f startVec){
		return (endVec.x - startVec.x) / length(endVec,startVec);
	}
	//works out normalization for the y co-ord of the vector
	static float normalizeY(sf::Vector2f endVec, sf::Vector2f startVec){
		return (endVec.y - startVec.y) / length(endVec,startVec);
	}
	//Works out length/magnitude
	static float length(sf::Vector2f endVec, sf::Vector2f startVec){ 
		return sqrt(pow(endVec.x-startVec.x,2)+pow(endVec.y-startVec.y,2));;
	}
};
