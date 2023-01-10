#pragma once
#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"


struct Ball {
	sf::CircleShape shape;
	float speedx;
	float speedy;
};

void initBall(Ball& ball) {
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	ball.speedx = 2.f;
	ball.speedy = 2.f;
}

void ballReboundAges(Ball& ball) {
	if (ball.shape.getPosition().x <= 0 || ball.shape.getPosition().x >= WINDOW_WIDTH - BALL_RADIUS * 2) {
		ball.speedx = -ball.speedx;		
	}

	if (ball.shape.getPosition().y <= 0) {
		ball.speedy = -ball.speedy;
	}
}
void ballOut(Ball& ball, sf::RenderWindow& window) {
	if(ball.shape.getPosition().y >= (WINDOW_HEIGHT - BALL_RADIUS * 2)) window.close();
}

void ballMove(Ball& ball) {
	ball.shape.move(ball.speedx, ball.speedy);
}

void ballUpdate(Ball& ball) {
	ballReboundAges(ball);
	ballMove(ball);
}

