#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include <sstream>
#include "Rocket.hpp"


using namespace std;


int main(){
    //Loading Assets
    sf::Texture rocketOff;
    sf::Texture rocketOn;
    rocketOff.loadFromFile("rocket.png");
    rocketOn.loadFromFile("rocketOn.png");
    //Initializing Game Objects
    Rocket rocket;
    rocket.sprite.setTexture(rocketOff);
    rocket.sprite.setPosition(400,300);
    rocket.sprite.setOrigin(rocket.baseWidth / 2, rocket.baseHeight / 2);
    //Set Video Mode
    sf::RenderWindow window(sf::VideoMode(800, 600), "Vector Rocket");
    window.setFramerateLimit(30);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();

            }
            rocket.processEvent(event);

        }

        //Type Conversions


        //Update State
        rocket.updateState();
        if(rocket.spacePressed){rocket.sprite.setTexture(rocketOn);}else{rocket.sprite.setTexture(rocketOff);}
        rocket.sprite.move(rocket.vector);

        window.clear();
        //Draw Stuff Here
        window.draw(rocket.sprite);


        //Display The Buffer
        window.display();
    }
}