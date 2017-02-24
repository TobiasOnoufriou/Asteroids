#pragma once
#include <SFML\Graphics.hpp>
#include <Constants.hpp>
#include <random>


class Starfield: public sf::Transformable, public sf::Drawable {
public:
	
	Starfield() {
		std::srand(std::rand() % 3000);
		shape.setRadius(2.0f);
		shape.setFillColor(sf::Color::White);
		x = std::rand() % WINDOW_WIDTH;
		y = std::rand() % WINDOW_HEIGHT;
		z = std::rand() % 2000;
		shape.setPosition(x, y);
	}
	void update() {
		z -= 10;
		if (z <= 0.0)
			reset();
	}
	void reset() {
		x = std::rand() % WINDOW_WIDTH;
		y = std::rand() % WINDOW_HEIGHT;
		shape.setPosition(x, y);

		z = 2000.0;
	}
	
	void draw() {
		float offsetX = 50.0 *(x / z);
		float offsetY = 50.0 *(y / z);
		float scaleZ = 0.001*(2000.0 - z);
		shape.move(offsetX, offsetY);
		shape.setRadius(scaleZ * 2.0f);
		
	}
	sf::CircleShape shape;
private:
	float x;
	float y;
	float z;
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		target.draw(shape);
	
		
	}
};