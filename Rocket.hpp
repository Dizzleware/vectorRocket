#ifndef ROCKET_HPP
#define ROCKET_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include <sstream>

class Rocket{
	private:

	public:
		sf::Vector2f updateVector(float rotation, float speed, sf::Vector2f vector);
		float degToRad(float degrees);
		sf::Sprite getSprite();
		sf::Vector2f getVector();

		void processEvent(sf::Event event);
		void resetEvent();
		void updateState();
		//Properties
		sf::Sprite sprite;
		sf::Vector2f vector;

		float rotSpeed = 10;
		float speed = 1;
		float baseWidth = 110;
		float baseHeight = 177;

		//Event Handling
		bool leftPressed, rightPressed, spacePressed;
		Rocket(){

		}

};

#endif