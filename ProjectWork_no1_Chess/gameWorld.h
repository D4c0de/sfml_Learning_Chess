#include <SFML/Graphics.hpp>

#include <vector>
#include "Figure.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H


class GameWorld
{
public:

	GameWorld(int, int);
	void drawFigures();
	void mousePressd(int, int);
	std::vector<std::vector<sf::Sprite>> boardNames;


	float gridLenght;
	float gridHeight;
	void loadTextures();
	void setUpInternalState();

private:
	void setsize();
	std::vector<std::vector<Figure*>> figures;

	sf::Texture texturesFull[2][2][6];
	sf::Texture TexturesEmpty[2];
	
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