#pragma once
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "bat.h"
#include "ball.h"
void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}



void checkCollisions() {

}

void drawGame(sf::RenderWindow& window, Bat bat, Ball ball) {
	window.clear();
	window.draw(bat.shape);
	window.draw(ball.shape);
	window.display();

}
//палка


void updateGame(Bat& bat, Ball& ball) {
	batUpdate(bat);
	ballUpdate(ball);

}

bool pointInRect(const Bat& bat, sf::Vector2f point) {
	return (point.x >= bat.shape.getPosition().x && point.x <= bat.shape.getPosition().x + BAT_WIDTH) &&
		(point.y >= bat.shape.getPosition().y && point.y <= bat.shape.getPosition().y + BAT_HEIGHT);
}