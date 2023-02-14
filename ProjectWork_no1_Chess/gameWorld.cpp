#include <SFML/Graphics.hpp>
#include "gameWorld.h"
#include <iostream>


GameWorld::GameWorld(int width,int height) {
	gridLenght = width / 8;
	gridHeight = height / 8;
	chosenFigure = NULL;

	setUpInternalState();
	loadTextures();
	setsize();

}




void GameWorld::setUpInternalState() {
	std::vector<Figure*> Row;
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

	TexturesEmpty[0].loadFromFile("images/free/dark.png");
	TexturesEmpty[1].loadFromFile("images/free/light.png");
	
	std::string figureColor[2];
	std::string figureType[7];
	figureColor[0] = "d";
	figureColor[1] = "l";
	figureType[0] = "p";
	figureType[1] = "r";
	figureType[2] = "n";
	figureType[3] = "b";
	figureType[4] = "q";
	figureType[5] = "k";
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
	
	figuresOnBoard.clear();
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
					figuresOnBoard.push_back(sprite);
				}

			}
			
		}
	}
	if (chosenFigure != NULL)
	{
		drawAbleMoves();
	}
}

void GameWorld::drawAbleMoves() {
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (chosenFigure->ableMoves[x][y]) {

				sf::Sprite sprite;
				sprite.setTexture(TexturesAble[0]);
				sprite.setPosition(y * gridLenght, x * gridHeight);
				figuresOnBoard.push_back(sprite);
			}
		}
	}

}

void GameWorld::setsize() {

	
	std::vector<sf::Sprite> SpriteRow;
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
					SpriteRow.push_back(sprite);

				}
			}
			else
			{
				for (int i = 1; i >= 0; i--)
				{
					sprite.setTexture(TexturesEmpty[i]);
					sprite.setPosition(a * gridLenght, ((b * 2) + (1 - i)) * gridHeight);
					SpriteRow.push_back(sprite);

				}
			}

		}
		boardNames.push_back(SpriteRow);
		SpriteRow.clear();
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
		chosenFigure = NULL; 

	}

}


void GameWorld::figureMove(int gridX,int gridY) {

	if (chosenFigure->typeName=="king")
	{
		checkCaseling(chosenFigure->isBlack, gridX, gridY);
	}
	if (chosenFigure->ableMoves[gridX][gridY] == true) {
		takes(gridX, gridY);
		if (chosenFigure->typeName == "pawn"&&(gridX==0||gridX==7))
		{
			chosenFigure->typeName = "queen";
			chosenFigure->typeID = 4;
		}
		chosenFigure->isMoved = true;
		chosenFigure->posNum = gridX;
		chosenFigure->posAlph = gridY;
	}
	else
	{
		//std::cout << "ruch nie dozwolony\n";
	}
	chosenFigure->clearMoves();
}



void GameWorld::choseFigure(int gridX, int gridY) {
	
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 16; k++)
		{
			int fx = figures[i][k]->posNum;
			int fy = figures[i][k]->posAlph;
			if (fx==gridX&&  fy== gridY)
			{
				chosenFigure = figures[i][k];
				//std::cout << "wybrano "+chosenFigure->typeName+"\n";
				checkAbleMoves();
				return;
			}

		}
	}
	//std::cout << "na tym polu nic siê nie znajduje \n";
}

bool GameWorld::anyOnGrid(int gridX, int gridY, int site) {
	for (int i = 0; i < figures[site].size(); i++)
	{
		if (figures[site][i]->posNum == gridX&& figures[site][i]->posAlph == gridY) {
			
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

				if (figures[site][i]->typeName=="king")
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
