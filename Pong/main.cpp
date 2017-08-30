#include <SFML\Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <sstream>

bool Play = false;
bool Menu =	true;
bool Win = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong!", sf::Style::Default);

	sf::RectangleShape player1;
	player1.setSize(sf::Vector2f(25.0f, 100.0f));
	player1.setFillColor(sf::Color::White);
	player1.setPosition(sf::Vector2f(203.5f, 310.0f));

	sf::RectangleShape player2;
	player2.setSize(sf::Vector2f(25.0f, 100.0f));
	player2.setFillColor(sf::Color::White);
	player2.setPosition(sf::Vector2f(1051.5f, 310.0f));

	sf::RectangleShape line1; //Middle
	line1.setFillColor(sf::Color::White);
	line1.setSize(sf::Vector2f(5.0f, 720.0f));
	line1.setPosition(sf::Vector2f(637.5f, 0.0f));

	sf::CircleShape ball(15.0f);
	ball.setOrigin(15.0f, 15.0f);
	ball.setPosition(640.0f, 360.0f);
	ball.setFillColor(sf::Color::Yellow);

	sf::RectangleShape line2;   //Under Scores
	line2.setFillColor(sf::Color::White);
	line2.setSize(sf::Vector2f(1280.0f, 5.0f));
	line2.setPosition(sf::Vector2f(0.0f, 35.0f));

	sf::Font font;
	font.loadFromFile("Pixeled.ttf");

	int randomx = rand() % 2 + 1;
	int randomy = rand() % 2 + 1;
	
	sf::Vector2f ballSpeed(0.0f, 0.0f);

	if (randomx == 1)
	{
		if (randomy == 1)
		{
			ballSpeed.x = -0.7f;
			ballSpeed.y = -0.3f;
		}
		else if (randomy == 2)
		{
			ballSpeed.x = -0.7f;
			ballSpeed.y = 0.3f;
		}
	}
	else if (randomx == 2)
	{
		if (randomy == 1)
		{
			ballSpeed.x = 0.7f;
			ballSpeed.y = -0.3f;
		}
		else if (randomy == 2)
		{
			ballSpeed.x = 0.7f;
			ballSpeed.y = 0.3f;
		}
	}

	sf::Vector2f Start1(203.5f, 35.0f); //Player1 Top
	sf::Vector2f Start2(203.5f, 620.0f); //Player1 Bottom
	sf::Vector2f Start3(1051.5f, 35.0f); //Player2 Top
	sf::Vector2f Start4(1051.5f, 620.0f); //Player2 Bottom

	sf::RectangleShape wall1;   //Right
	wall1.setSize(sf::Vector2f(1.0f, 720.0f));
	wall1.setPosition(sf::Vector2f(-1.0f, 0.0f));

	sf::RectangleShape wall2;   //Left
	wall2.setSize(sf::Vector2f(1.0f, 720.0f));
	wall2.setPosition(sf::Vector2f(1280.0f, 0.0f));

	sf::RectangleShape wall3;   //Top
	wall3.setSize(sf::Vector2f(1280.0f, 1.0f));
	wall3.setPosition(sf::Vector2f(0.0f, 34.0f));
	sf::RectangleShape wall4;   //Bottom
	wall4.setSize(sf::Vector2f(1280.0f, 1.0f));
	wall4.setPosition(sf::Vector2f(0.0f, 720.0f));

	sf::Text score1;
	score1.setFont(font);
	score1.setString(sf::String("Player 1: "));
	score1.setCharacterSize(20U);
	score1.setFillColor(sf::Color::Green);
	score1.setPosition(sf::Vector2f(203.5f, 10.0f));

	sf::Text score2;
	score2.setFont(font);
	score2.setString(sf::String("Player 2: "));
	score2.setCharacterSize(20U);
	score2.setFillColor(sf::Color::Red);
	score2.setPosition(sf::Vector2f(841.0f, 10.0f));

	int points1 = 0;
	int points2 = 0;

	std::stringstream out1;
	out1 << points1;

	std::string p1;
	p1 = out1.str();

	sf::Text pts1(p1, font, 20U);
	pts1.setFillColor(sf::Color::Green);
	pts1.setPosition(sf::Vector2f(350.0f, 10.0f));

	std::stringstream out2;
	out2 << points2;

	std::string p2;
	p2 = out2.str();

	sf::Text pts2(p2, font, 20U);
	pts2.setFillColor(sf::Color::Red);
	pts2.setPosition(sf::Vector2f(1000.0f, 10.0f));


	while (window.isOpen())
	{
		
		while (Menu == true)
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}

			}

			sf::Text title(sf::String("Pong!"), font, 50U);
			title.setFillColor(sf::Color::White);
			title.setPosition(sf::Vector2f(520.0f, 50.0f));

			sf::Text playbutt(sf::String("Play!"), font, 30U);
			playbutt.setFillColor(sf::Color::White);
			playbutt.setPosition(sf::Vector2f(550.0f, 400.0f));

			sf::Text exitbutt(sf::String("Exit!"), font, 30U);
			exitbutt.setFillColor(sf::Color::White);
			exitbutt.setPosition(sf::Vector2f(550.0f, 500.0f));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				// transform the mouse position from window coordinates to world coordinates
				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

				// retrieve the bounding box of the sprite
				sf::FloatRect playbounds = playbutt.getGlobalBounds();
				sf::FloatRect exitbounds = exitbutt.getGlobalBounds();

				// hit test
				if (playbounds.contains(mouse))
				{
					Menu = false;
					Play = true;
					
					// mouse is on sprite!
				}
				if (exitbounds.contains(mouse))
				{
					window.close();

					// mouse is on sprite!
				}
				
				

			}
			
			
			window.clear(sf::Color::Black);
			window.draw(title);
			window.draw(playbutt);
			window.draw(exitbutt);
			window.display();

		}
		
		
		
		while (Play == true)
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}

			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				player1.move(0.0f, -0.5f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				player1.move(0.0f, 0.5f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				player2.move(0.0f, -0.5f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				player2.move(0.0f, 0.5f);
			}

			if (player1.getPosition().y < 35.0f)
			{
				player1.setPosition(Start1);
			}
			if (player1.getPosition().y > 620.0f)
			{
				player1.setPosition(Start2);
			}
			if (player2.getPosition().y < 35.0f)
			{
				player2.setPosition(Start3);
			}
			if (player2.getPosition().y > 620.0f)
			{
				player2.setPosition(Start4);
			}

			int random = rand() % 2 + 1;
			
			ball.move(ballSpeed.x, ballSpeed.y);

			std::stringstream out2;
			out2 << points2;

			std::string p2;
			p2 = out2.str();
			pts2.setString(p2);

			std::stringstream out1;
			out1 << points1;

			std::string p1;
			p1 = out1.str();
			pts1.setString(p1);

			if (wall1.getGlobalBounds().intersects(ball.getGlobalBounds()))
			{
				points2++;
				ball.setPosition(640.0f, 360.0f);
				ballSpeed.x = -1.0f;
				ballSpeed.y = 0.3f;

			}
			if (wall2.getGlobalBounds().intersects(ball.getGlobalBounds()))
			{
				points1++;

				ball.setPosition(640.0f, 360.0f);
				ballSpeed.x = 1.0f;
				ballSpeed.y = 0.3f;


			}
			if (wall3.getGlobalBounds().intersects(ball.getGlobalBounds()))
			{

				ballSpeed.y = -(ballSpeed.y);
			}
			if (wall4.getGlobalBounds().intersects(ball.getGlobalBounds()))
			{

				ballSpeed.y = -(ballSpeed.y);
			}
			if (player1.getGlobalBounds().intersects(ball.getGlobalBounds()))
			{
				ballSpeed.x = -(ballSpeed.x);

			}
			if (player2.getGlobalBounds().intersects(ball.getGlobalBounds()))
			{
				ballSpeed.x = -(ballSpeed.x);

			}
			
			if (points1 == 10 || points2 == 10)
			{
				Play = false;
				Win = true;
			}
			
			
			
			window.clear(sf::Color::Black);
			window.draw(line1);
			window.draw(line2);
			window.draw(wall1);
			window.draw(wall2);
			window.draw(wall3);
			window.draw(wall4);
			window.draw(player1);
			window.draw(player2);
			window.draw(ball);
			window.draw(pts1);
			window.draw(pts2);
			window.draw(score1);
			window.draw(score2);
			window.display();
		}
		while (Win ==true)
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}

			}
			
			sf::Text win1("Player 1 wins!", font, 30U);
			win1.setFillColor(sf::Color::Green);
			win1.setPosition(200.0f, 200.0f);

			sf::Text lose1("Player 1 loses!", font, 30U);
			lose1.setFillColor(sf::Color::Red);
			lose1.setPosition(200.0f, 200.0f);

			sf::Text win2("Player 2 wins!", font, 30U);
			win2.setFillColor(sf::Color::Green);
			win2.setPosition(800.0f, 200.0f);

			sf::Text lose2("Player 2 loses!", font, 30U);
			lose2.setFillColor(sf::Color::Red);
			lose2.setPosition(800.0f, 200.0f);

			sf::Text menu(sf::String("Back to menu"), font, 30U);
			menu.setFillColor(sf::Color::White);
			menu.setPosition(sf::Vector2f(475.0f, 550.0f));

			sf::Text again(sf::String("Play again"), font, 30U);
			again.setFillColor(sf::Color::White);
			again.setPosition(sf::Vector2f(500.0f, 650.0f));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

				sf::FloatRect mbounds = menu.getGlobalBounds();
				sf::FloatRect abounds = again.getGlobalBounds();
				
				if (mbounds.contains(mouse))
				{
					points1 = 0;
					points2 = 0;
					Menu = true;
					Win = false;

				}
				if (abounds.contains(mouse))
				{
					points1 = 0;
					points2 = 0;
					Play = true;
					Win = false;

				}
			}
			window.clear(sf::Color::Black);
			if (points1 == 10)
			{
				window.draw(win1);
				window.draw(lose2);
			}
			else if (points2 == 10)
			{
				window.draw(lose1);
				window.draw(win2);
			}
			window.draw(menu);
			window.draw(again);
			window.display();
		}

}
return 0;
}

