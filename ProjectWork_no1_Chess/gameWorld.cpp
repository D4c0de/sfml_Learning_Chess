#include <SFML/Graphics.hpp>
#include "gameWorld.h"
#include <iostream>


GameWorld::GameWorld(sf::RenderWindow* Window,bool debug) {
	window = Window;
	sf::Vector2u vector=window->getSize();
	gridLenght = vector.y / 8;
	gridHeight = vector.x / 8;
	chosenFigure = NULL;
	debugMode = debug;
	setUpInternalState();
	loadTextures();

}


void GameWorld::deleteFigures()
{
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 16; x++) {
			delete figures[i][x];
		}
	}
}


void GameWorld::setUpInternalState() {
	figures.clear();
	std::vector<Figure*> Row;
	moveNo = 1;
	Row.push_back(new Figure("pawn", "white", 0, 1));
	Row.push_back(new Figure("pawn", "white", 1, 1));
	Row.push_back(new Figure("pawn", "white", 2, 1));
	Row.push_back(new Figure("pawn", "white", 3, 1));
	Row.push_back(new Figure("pawn", "white", 4, 1));
	Row.push_back(new Figure("pawn", "white", 5, 1));
	Row.push_back(new Figure("pawn", "white", 6, 1));
	Row.push_back(new Figure("pawn", "white", 7, 1));

	Row.push_back(new Figure("rook", "white", 0,  0 ));
	Row.push_back(new Figure("knight", "white", 1,  0 ));
	Row.push_back(new Figure("bishop", "white", 2,  0 ));
	Row.push_back(new Figure("queen", "white", 3,  0 ));
	Row.push_back(new Figure("king", "white", 4,  0 ));
	Row.push_back(new Figure("bishop", "white", 5,  0 ));
	Row.push_back(new Figure("knight", "white",6,  0 ));
	Row.push_back(new Figure("rook", "white", 7,  0 ));


	figures.push_back(Row);
	Row.clear();
	Row.push_back(new Figure("pawn", "black", 0, 6));
	Row.push_back(new Figure("pawn", "black", 1, 6));
	Row.push_back(new Figure("pawn", "black", 2, 6));
	Row.push_back(new Figure("pawn", "black", 3, 6));
	Row.push_back(new Figure("pawn", "black", 4, 6));
	Row.push_back(new Figure("pawn", "black", 5, 6));
	Row.push_back(new Figure("pawn", "black", 6, 6));
	Row.push_back(new Figure("pawn", "black", 7, 6));

	Row.push_back(new Figure("rook", "black", 0, 7));
	Row.push_back(new Figure("knight", "black", 1, 7));
	Row.push_back(new Figure("bishop", "black", 2, 7));
	Row.push_back(new Figure("queen", "black", 3,  7));
	Row.push_back(new Figure("king", "black", 4,  7));
	Row.push_back(new Figure("bishop", "black",5,  7));
	Row.push_back(new Figure("knight", "black", 6,  7));
	Row.push_back(new Figure("rook", "black", 7,  7));
	figures.push_back(Row);
	

}
void GameWorld::loadTextures() {
	std::string figureColor[2];
	std::string figureType[7];
	figureColor[0] = "d";//dark
	figureColor[1] = "l";//light
	figureType[0] = "p";//pawn
	figureType[1] = "r";//rook
	figureType[2] = "n";//knight
	figureType[3] = "b";//bishop
	figureType[4] = "q";//queen
	figureType[5] = "k";//king

	
	TexturesEmpty[0].loadFromFile("images/free/dark.png");
	TexturesEmpty[1].loadFromFile("images/free/light.png");
	
	TexturesAble[0].loadFromFile("images/ablemoves/ae.png");

	for (int y = 0; y < 2; y++)
	{
		for (int z = 0; z < 6; z++)
		{
			texturesFull[y][z].loadFromFile("images/pices/" +  figureColor[y] + figureType[z] + ".png");
		}
	}
	



}

void GameWorld::drawFigures() {
	
		for (int a = 0; a < 8; a++)
		{
			for (int b = 0; b < 4; b++)
			{
				sf::Sprite sprite;
				if (a % 2 == 0)
				{
					for (int i = 0; i < 2; i++)
					{
						sprite.setTexture(TexturesEmpty[i]);
						sprite.setPosition(a * gridLenght, ((b * 2) + i) * gridHeight);
						window->draw(sprite);

					}
				}
				else
				{
					for (int i = 1; i >= 0; i--)
					{
						sprite.setTexture(TexturesEmpty[i]);
						sprite.setPosition(a * gridLenght, ((b * 2) + (1 - i)) * gridHeight);
						window->draw(sprite);

					}
				}

			}
		}
	
	for (int i = 0; i < figures.size(); i++)
	{
		for (int k = 0; k < figures[i].size(); k++)
		{
			if (figures[i][k]->posNum!=-1)
			{
				sf::Sprite sprite;

				int white = figures[i][k]->isBlack;
				int id = figures[i][k]->typeID;
				int x = figures[i][k]->posAlph;
				int y = figures[i][k]->posNum;
				if (x!=-1)
				{
					sprite.setTexture(texturesFull[white][id]);
					sprite.setPosition(x * gridLenght, y * gridHeight);
					window->draw(sprite);
				}

			}
			
		}
	}
	if (chosenFigure != NULL)
	{
		for (int i = 0; i < chosenFigure->ableMoves.size(); i++)
		{
			sf::Sprite sprite;
			sprite.setTexture(TexturesAble[0]);
			sprite.setPosition(chosenFigure->ableMoves[i].y * gridLenght, chosenFigure->ableMoves[i].x * gridHeight);
			window->draw(sprite);
		}
			
		
	}
}




void GameWorld::mousePressd(int x,int y) {

	int gridX = x / gridHeight;
	int gridY = y / gridLenght;
	//std::cout << "grid x/y " << gridX << " " << gridY << " \n";
	if (chosenFigure == NULL) {
		choseFigure(gridX, gridY);

	}
	else
	{
		figureMove(gridX,gridY);
		chosenFigure->clearMoves();
		chosenFigure = NULL; 

	}

}



void GameWorld::figureMove(int gridX, int gridY) {


	if (chosenFigure->typeID == 0)
	{
		//enPassant(chosenFigure->isBlack, gridX, gridY);
	}
	for (int i = 0; i < chosenFigure->ableMoves.size(); i++)
	{
		if (chosenFigure->ableMoves[i].x == gridX && chosenFigure->ableMoves[i].y == gridY) {

			if (chosenFigure->typeID == 5)
			{
				if (checkCaseling(chosenFigure->isBlack, gridX, gridY)) {
					chosenFigure->lastMovement = moveNo;
					moveNo++;
					return;
				}
			}
			if (chosenFigure->typeID == 0)
			{
				if (enPassant(chosenFigure->isBlack, gridX, gridY))
				{
					chosenFigure->lastMovement = moveNo;
					moveNo++;
					return;
				}
			}
			takes(gridX, gridY);
			if (chosenFigure->typeID == 0 && (gridX == 0 || gridX == 7))
			{
				chosenFigure->typeID = 4;
			}
			chosenFigure->isMoved = true;
			chosenFigure->posNum = gridX;
			chosenFigure->posAlph = gridY;
			chosenFigure->lastMovement = moveNo;
			moveNo++;
			return;
		}
	}

}



void GameWorld::choseFigure(int gridX, int gridY) {
	
	if (debugMode)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < 16; k++)
			{
				if (figures[i][k]->posNum == gridX && figures[i][k]->posAlph == gridY)
				{
					chosenFigure = figures[i][k];
					checkAbleMoves();
					return;
				}

			}
		}
		
	}
	else
	{
		for (int k = 0; k < 16; k++)
		{
			if (figures[moveNo % 2][k]->posNum == gridX && figures[moveNo % 2][k]->posAlph == gridY)
			{
				chosenFigure = figures[moveNo % 2][k];
				checkAbleMoves();
				return;
			}

		}
	}
	//std::cout << "na tym polu nic si� nie znajduje \n";
}

bool GameWorld::anyOnGrid(int gridX, int gridY, bool site) {

	int sitei;
	if (site==true)
	{
		sitei = 1;
	}
	else
	{
		sitei = 0;
	}
	for (int i = 0; i < figures[sitei].size(); i++)
	{
		if (figures[sitei][i]->posNum == gridX&& figures[sitei][i]->posAlph == gridY) {
			
			return true;
		}
	}
	return false;
}

void GameWorld::takes(int gridX, int gridY) {
	for (int site = 0; site < figures.size(); site++)
	{

		for (int i = 0; i < figures[site].size(); i++)
		{
			if (figures[site][i]->posNum == gridX && figures[site][i]->posAlph == gridY) {

				if (figures[site][i]->typeID == 5 )
				{
					if (site)
					{
						std::cout << "black win\n";
					}
					else
					{
						std::cout << "white win\n";
					}
					end = true;
				}
				figures[site][i]->posNum = -1;

				return;
			}
		}
	}
}
bool GameWorld::willBeCheck() {
	return false;
}
