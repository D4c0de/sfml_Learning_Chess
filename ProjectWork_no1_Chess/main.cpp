#include <SFML/Graphics.hpp>
#include "gameWorld.h"
#include <iostream>
#include <Windows.h>




int main() {
	
	bool play=true;
	while (play)
	{


		int windowWidth = 360;
		int windowLenght = 360;
		sf::RenderWindow window(sf::VideoMode(windowWidth, windowLenght), "chess");
		GameWorld gameWorld = GameWorld(windowWidth, windowLenght, &window);
		gameWorld.debugMode = true;
		bool sleepTime = false;

		while (window.isOpen() && !gameWorld.end)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				gameWorld.mousePressd(mousePos.y, mousePos.x);

				sleepTime = true;
			}
			window.clear();
			
			gameWorld.drawFigures();



			window.display();
			if (sleepTime)
			{
				Sleep(300);

			}
			sleepTime = false;
		}
		std::cout << "play agan?1/0: ";
		std::cin >> play;
		std::cout << "\n";
	}
	return 1;
}