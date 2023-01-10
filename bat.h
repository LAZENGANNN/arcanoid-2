#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
struct Bat {
	sf::RectangleShape shape;
	float speedx;
};

void initbat(Bat& bat) {
	bat.shape.setSize(BAT_SIZE);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
	bat.speedx = 0.f;
}

void batControl(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) bat.speedx = -BAT_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) bat.speedx = BAT_SPEED;
	bat.shape.move(bat.speedx, 0.f);
	bat.speedx = 0.f;
}

void batReboundAges(Bat& bat) {
	float batx = bat.shape.getPosition().x;
	float baty = bat.shape.getPosition().y;
	if (batx <= 0) bat.shape.setPosition(0.f, baty);
	if (batx >= WINDOW_WIDTH - BAT_WIDTH) bat.shape.setPosition(WINDOW_WIDTH - BAT_WIDTH, baty);
}

void batDraw(sf::RenderWindow& window, Bat& bat){
	window.draw(bat.shape);
}

void batUpdate(Bat& bat) {
	batControl(bat);
	batReboundAges(bat);
}






