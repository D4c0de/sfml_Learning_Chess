#include <SFML/Graphics.hpp>

#include <vector>
#include "Figure.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H


class GameWorld
{
public:

	GameWorld(int, int, sf::RenderWindow*);
	void drawFigures();
	void mousePressd(int, int);
	bool end=false;
	bool debugMode;
private:

	sf::RenderWindow* window;
	int moveNo;
	float gridLenght;
	float gridHeight;
	void loadTextures();
	void setUpInternalState();
	std::vector<std::vector<Figure*>> figures;
	sf::Texture texturesFull[2][6];
	sf::Texture TexturesEmpty[2];
	sf::Texture TexturesAble[1];
	Figure* chosenFigure;
	void choseFigure(int, int);
	void figureMove(int, int);
	void checkAbleMoves();
	void takes(int, int);
	bool willBeCheck();
	bool anyOnGrid(int, int, int);
	void checkCaseling(int,int,int);
	

};
#endif