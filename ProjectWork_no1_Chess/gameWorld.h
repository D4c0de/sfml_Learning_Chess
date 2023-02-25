#include <SFML/Graphics.hpp>

#include <vector>
#include "Figure.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H


class GameWorld
{
public:

	GameWorld(sf::RenderWindow*, bool);
	void drawFigures();
	void mousePressd(int, int);
	bool end = false;
	bool debugMode;
	void deleteFigures();
	void checkAbleMoves();
private:
	
	sf::RenderWindow* window;
	unsigned int moveNo;
	unsigned int gridLenght;
	unsigned int gridHeight;
	void loadTextures();
	void setUpInternalState();
	std::vector<std::vector<Figure*>> figures;
	sf::Texture texturesFull[2][6];
	sf::Texture TexturesEmpty[2];
	sf::Texture TexturesAble[1];
	Figure* chosenFigure;
	void choseFigure(int, int);
	void figureMove(int, int);
	bool isAble(int, int, int);
	void takes(int, int);
	bool willBeCheck();


	bool inRenge(int, int);
	bool isMoveAble(int ,int);

	bool enPassant(int, int, int);

	bool anyOnGrid(int, int, bool);
	bool checkCaseling(int,int,int);
	

};
#endif