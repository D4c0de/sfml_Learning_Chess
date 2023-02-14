#include <SFML/Graphics.hpp>
#include "gameWorld.h"

void GameWorld::checkAbleMoves() {

	int y = chosenFigure->posAlph;
	int x = chosenFigure->posNum;
	int enemyColor = 0;
	if (chosenFigure->isBlack == 0)
	{
		enemyColor = 1;
	}
	if (chosenFigure->typeName == "pawn")
	{

		if (chosenFigure->isBlack == 0)
		{
			if (chosenFigure->isMoved == false)
			{
				if (!anyOnGrid(x + 2, y, 0) &&
					!anyOnGrid(x + 2, y, 1) &&
					!willBeCheck())
				{
					chosenFigure->ableMoves[x + 2][y] = true;
				}
			}
			if (!anyOnGrid(x + 1, y, 0) &&
				!anyOnGrid(x + 1, y, 1) &&
				!willBeCheck())
			{
				chosenFigure->ableMoves[x + 1][y] = true;
			}

			if (anyOnGrid(x + 1, y + 1, enemyColor) &&
				!willBeCheck()) {
				chosenFigure->ableMoves[x + 1][y + 1] = true;
			}

			if (anyOnGrid(x + 1, y - 1, enemyColor) &&
				!willBeCheck()) {
				chosenFigure->ableMoves[x + 1][y - 1] = true;
			}

		}

		else if (chosenFigure->isBlack == 1)
		{
			if (chosenFigure->isMoved == false)
			{


				if (!anyOnGrid(x - 2, y, 0) &&
					!anyOnGrid(x - 2, y, 1) &&
					!willBeCheck())

				{
					chosenFigure->ableMoves[x - 2][y] = true;
				}
			}
			if (!anyOnGrid(x - 1, y, 0) &&
				!anyOnGrid(x - 1, y, 1) &&
				!willBeCheck())
			{
				chosenFigure->ableMoves[x - 1][y] = true;
			}

			if (anyOnGrid(x - 1, y - 1, enemyColor) &&
				!willBeCheck()) {
				chosenFigure->ableMoves[x - 1][y - 1] = true;
			}
			if (anyOnGrid(x - 1, y + 1, enemyColor) &&
				!willBeCheck()) {
				chosenFigure->ableMoves[x - 1][y + 1] = true;
			}
		}
	}
	else if (chosenFigure->typeName == "rook")
	{

		int x2 = x + 1;
		int y2 = y;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x - 1;
		y2 = y;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			y2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}

	}
	else if (chosenFigure->typeName == "bishop") {
		int x2 = x + 1;
		int y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2++;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x + 1;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2++;
			y2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x - 1;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2--;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x - 1;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			y2--;
			x2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
	}
	else if (chosenFigure->typeName == "knight") {


		if (!anyOnGrid(x + 2, y + 1, chosenFigure->isBlack) &&
			y + 1 < 8 && y + 1 >= 0 && x + 2 < 8 && x + 2 >= 0)
		{
			chosenFigure->ableMoves[x + 2][y + 1] = true;
		}
		if (!anyOnGrid(x + 2, y - 1, chosenFigure->isBlack) &&
			y - 1 < 8 && y - 1 >= 0 && x + 2 < 8 && x + 2 >= 0)
		{
			chosenFigure->ableMoves[x + 2][y - 1] = true;
		}
		if (!anyOnGrid(x - 2, y + 1, chosenFigure->isBlack) &&
			y + 1 < 8 && y + 1 >= 0 && x - 2 < 8 && x - 2 >= 0)
		{
			chosenFigure->ableMoves[x - 2][y + 1] = true;
		}
		if (!anyOnGrid(x - 2, y - 1, chosenFigure->isBlack) &&
			y - 1 < 8 && y - 1 >= 0 && x - 2 < 8 && x - 2 >= 0)
		{
			chosenFigure->ableMoves[x - 2][y - 1] = true;
		}


		if (!anyOnGrid(x + 1, y + 2, chosenFigure->isBlack) &&
			y + 2 < 8 && y + 2 >= 0 && x + 1 < 8 && x + 1 >= 0)
		{
			chosenFigure->ableMoves[x + 1][y + 2] = true;
		}
		if (!anyOnGrid(x + 1, y - 2, chosenFigure->isBlack) &&
			y - 2 < 8 && y - 2 >= 0 && x + 1 < 8 && x + 1 >= 0)
		{
			chosenFigure->ableMoves[x + 1][y - 2] = true;
		}
		if (!anyOnGrid(x - 1, y - 2, chosenFigure->isBlack) &&
			y - 2 < 8 && y - 2 >= 0 && x - 1 < 8 && x - 1 >= 0)
		{
			chosenFigure->ableMoves[x - 1][y - 2] = true;
		}
		if (!anyOnGrid(x - 1, y + 2, chosenFigure->isBlack) &&
			y + 2 < 8 && y + 2 >= 0 && x - 1 < 8 && x - 1 >= 0)
		{
			chosenFigure->ableMoves[x - 1][y + 2] = true;
		}

	}
	else if (chosenFigure->typeName == "queen")
	{
		int x2 = x + 1;
		int y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2++;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x + 1;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2++;
			y2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x - 1;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2--;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x - 1;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			y2--;
			x2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}


		x2 = x + 1;
		y2 = y;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x - 1;
		y2 = y;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			x2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
		x2 = x;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves[x2][y2] = true;
			y2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}

		}
	}
	else if (chosenFigure->typeName == "king") {
		if (true)
		{
			int x2 = x + 1;
			int y2 = y;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x + 1;
			y2 = y + 1;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x;
			y2 = y + 1;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x - 1;
			y2 = y + 1;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x - 1;
			y2 = y;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x - 1;
			y2 = y - 1;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x - 1;
			y2 = y;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x - 1;
			y2 = y - 1;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x;
			y2 = y - 1;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
			x2 = x + 1;
			y2 = y - 1;

			if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves[x2][y2] = true;
			}
		}
	}
}

void GameWorld::checkCaseling(int site,int y,int x ) {

	if (site==1)
	{
		if (x == 2 && y == 7 && chosenFigure->isMoved == false && figures[site][8]->isMoved == false && figures[site][8]->posNum != -1)
		{
			if (!anyOnGrid(7,2,  0) && !anyOnGrid( 7,2, 1) &&
				!anyOnGrid(7,3,  0) && !anyOnGrid( 7,3, 1) &&
				!anyOnGrid(7,1,  0) && !anyOnGrid( 7,1, 1)
				)
			{
				chosenFigure->posNum = y;
				chosenFigure->posAlph = x;
				chosenFigure->isMoved = true;
				figures[site][8]->posNum = y;
				figures[site][8]->posAlph = x + 1;
				figures[site][15]->isMoved = true;
			}
		}
		else if (x == 6 && y == 7 && chosenFigure->isMoved == false && figures[site][15]->isMoved == false &&  figures[site][15]->posNum != -1)
		{
			if (!anyOnGrid(7,5,0)&& !anyOnGrid(7,5,  1)&&
				!anyOnGrid(7, 6,  0) && !anyOnGrid(7, 6,  1)
				)
			{
				chosenFigure->posNum = y;
				chosenFigure->posAlph = x;
				chosenFigure->isMoved = true;
				figures[site][15]->posNum = y;
				figures[site][15]->posAlph = x - 1;
				figures[site][15]->isMoved = true;
			}
			
		}
		
		
	}
	else
	{
		if (x ==2&&y==0 &&chosenFigure->isMoved==false&&figures[site][8]->isMoved==false && figures[site][8]->posNum!=-1)
		{
			if (!anyOnGrid( 0,2, 0) && !anyOnGrid(0,2, 1) &&
				!anyOnGrid( 0,3, 0) && !anyOnGrid(0,3, 1) &&
				!anyOnGrid( 0,1, 0) && !anyOnGrid(0,1, 1)
				) {
				chosenFigure->posNum = y;
				chosenFigure->posAlph = x;
				figures[site][8]->posNum = y;
				figures[site][8]->posAlph = x + 1;
			}
		}
		else if (x == 6 && y == 0 && chosenFigure->isMoved == false && figures[site][15]->isMoved == false && figures[site][15]->posNum != -1)
		{
			if (!anyOnGrid(0, 5, 0) && !anyOnGrid( 0,5, 1) &&
				!anyOnGrid(0, 6, 0) && !anyOnGrid( 0,6, 1)
				)
			{
				chosenFigure->posNum = y;
				chosenFigure->posAlph = x;
				chosenFigure->isMoved = true;
				figures[site][15]->posNum = y;
				figures[site][15]->posAlph = x - 1;
				figures[site][15]->isMoved = true;

			}
		}
	}

}