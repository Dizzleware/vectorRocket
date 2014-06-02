#include "Rocket.hpp"

sf::Vector2f Rocket::updateVector(float rotation, float speed, sf::Vector2f vector){

    vector.x += sin(degToRad(rotation)) * speed;
    vector.y -= cos(degToRad(rotation)) * speed;
    return vector;
}

float Rocket::degToRad(float degrees){
    float rad;

    rad = degrees * (3.14259 / 180.0);
    return rad;
}

sf::Sprite Rocket::getSprite(){
	return this -> sprite;
}

sf::Vector2f Rocket::getVector(){
	return this -> vector;
}

void Rocket::processEvent(sf::Event event){
	    resetEvent();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            this -> leftPressed = true;
        }else{leftPressed = false;}

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            this -> rightPressed = true;
        }else{rightPressed = false;}

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            this -> spacePressed = true;
        }else{spacePressed = false;}

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            this -> vector.x = 0;
            this -> vector.y = 0;

            this -> sprite.setPosition(400,300);
            this -> sprite.setRotation(0);
        }


}

void Rocket::resetEvent(){
    leftPressed = false;
    rightPressed = false;
    spacePressed = false;
}

void Rocket::updateState(){
    if(this-> leftPressed){
        this-> sprite.rotate(-1 * rotSpeed);
    }

    if(this -> rightPressed){
        this-> sprite.rotate(rotSpeed);
    }

    if(this -> spacePressed){
        this-> vector = updateVector(sprite.getRotation(), speed, vector);
    }
}