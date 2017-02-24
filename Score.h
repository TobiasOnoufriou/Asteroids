#include <SFML/Graphics.hpp>
#include <Constants.hpp>

class Score: public sf::Drawable, public sf::Transformable {
private:
	 sf::Font font;
	 sf::Text text;
	 std::string score;
	 int scoreInt;
public:
	Score(){
		scoreInt = 0;
		score = "0";
		font.loadFromFile("font.ttf");
		text.setPosition(WINDOW_WIDTH - 150, (WINDOW_HEIGHT - WINDOW_HEIGHT) + 10);
		text.setFont(font);
		text.setColor(sf::Color::White);
		text.setCharacterSize(30);
		text.setString(score);
	}
	void changeScore(const int& addedScore){
		this->scoreInt += addedScore;
		this->score = std::to_string(scoreInt);
		this->text.setString(score);
	}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= getTransform();
		target.draw(text, states);
	}

};