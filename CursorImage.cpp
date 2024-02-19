// CursorImage.cpp: определяет точку входа для приложения.
//

#include "CursorImage.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
using namespace std;

int main()
{
	sf::RenderWindow win(sf::VideoMode(640,480),"CursorImage");
	sf::Texture img;
	if (!img.loadFromFile("C:/Users/Роман/Pictures/РОФЛЫ/wtf.jpg")) {
		
	}
	sf::Sprite sprite;
	sprite.setTexture(img);
	sprite.setScale(sf::Vector2f(0.1,0.1)); 
	sprite.setPosition(0, 0);
	img.setSmooth(true);
	win.setPosition(sf::Vector2i(640, 300));
	win.setVerticalSyncEnabled(true);

	sf::Clock timer;
	sf::Time tickRate;
	
	sf::Vector2f movement;
	while (win.isOpen()) {
		tickRate = timer.restart();
		sf::Event event;
		while (win.pollEvent(event)){
			if (event.type == sf::Event::Closed) {
				win.close();
			}
			if (event.key.code == sf::Keyboard::Space) {

			}
			if (event.type == sf::Event::MouseMoved) {
				
				movement.x = event.mouseMove.x;
				movement.y = event.mouseMove.y;
				//std::cout <<" MX = " << movement.x << std::endl;
				//std::cout <<" MY = " << movement.y << std::endl;
			}
		}
	
		win.clear();
		sprite.setPosition(movement);
		
		//sprite.move(movement * ((float)tickRate.asMilliseconds() / 1000));
		//sprite.move(movement);
		//win.draw(sf::CircleShape(20));
		//gisprite.setPosition(movement * ((float)tickRate.asMilliseconds() / 1000));
		win.draw(sprite);
		win.display();
	}
	return 0;
}
