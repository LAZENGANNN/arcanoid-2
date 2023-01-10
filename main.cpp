#include "SFML/Graphics.hpp"
#include "settings.h"
#include "functions.h"
#include "bat.h"
#include "ball.h"

using namespace sf;

int main()
{
	Bat bat;
	initbat(bat);

	Ball ball;
	initBall(ball);

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		checkEvents(window);

		updateGame(bat, ball);

		checkCollisions();

		Vector2f midLeft{
			ball.shape.getPosition().x,
			ball.shape.getPosition().y + BALL_RADIUS
		};
		Vector2f midTop{
			ball.shape.getPosition().x + BALL_RADIUS,
			ball.shape.getPosition().y
		};
		Vector2f midRight{
			ball.shape.getPosition().x + 2 * BALL_RADIUS,
			ball.shape.getPosition().y + BALL_RADIUS
		};
		Vector2f midBottom{
			ball.shape.getPosition().x + BALL_RADIUS,
			ball.shape.getPosition().y + 2 * BALL_RADIUS
		};

		if (pointInRect(bat, midBottom))
			ball.speedy = -ball.speedy;

		ballOut(ball, window);

		drawGame(window, bat, ball);
	}

	return 0;
}