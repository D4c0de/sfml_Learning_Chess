#include <SFML/Graphics.hpp>
#include "gameWorld.h"

void GameWorld::checkAbleMoves() {

	int y = chosenFigure->posAlph;
	int x = chosenFigure->posNum;
	int enemyColor = 0;
	int x2 = 1;
	int y2 = 1;
	if (chosenFigure->isBlack == 0)
	{
		enemyColor = 1;
	}
	if (chosenFigure->typeID == 0)
	{

		if (chosenFigure->isBlack == 0)
		{
			if (chosenFigure->posNum == 4)
			{

				for (int i = 0; i < 8; i++)
				{
					if (figures[enemyColor][i]->posNum != -1)
					{
						if (figures[enemyColor][i]->posAlph == y + 1 && figures[enemyColor][i]->posNum == x && figures[enemyColor][i]->lastMovement == moveNo - 1) {


							chosenFigure->ableMoves.push_back(sf::Vector2i(x + 1, y + 1));

						}
						else if (figures[enemyColor][i]->posAlph == y - 1 && figures[enemyColor][i]->posNum == x && figures[enemyColor][i]->lastMovement == moveNo - 1)
						{
							chosenFigure->ableMoves.push_back(sf::Vector2i(x + 1, y - 1));
						}
					}
				}
			}
			x2 = x + 1;
			y2 = y;
			if (!anyOnGrid(x2, y2, 0) &&
				!anyOnGrid(x2, y2, 1) &&
				!willBeCheck())
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
				if (chosenFigure->isMoved == false)
				{

					if (!anyOnGrid(x2 + 1, y, 0) &&
						!anyOnGrid(x2 + 1, y, 1) &&
						!willBeCheck())

					{
						chosenFigure->ableMoves.push_back(sf::Vector2i(x2 + 1, y2));
					}
				}
			}

			x2 = x + 1;
			y2 = y - 1;
			if (anyOnGrid(x2, y2, enemyColor) &&
				!willBeCheck()) {
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}
			x2 = x + 1;
			y2 = y + 1;
			if (anyOnGrid(x2, y2, enemyColor) &&
				!willBeCheck()) {
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}

		else if (chosenFigure->isBlack == 1)
		{
			if (chosenFigure->posNum == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					if (figures[enemyColor][i]->posNum != -1)
					{
						if (figures[enemyColor][i]->posAlph == y + 1 && figures[enemyColor][i]->posNum == x && figures[enemyColor][i]->lastMovement == moveNo - 1) {


							chosenFigure->ableMoves.push_back(sf::Vector2i(x - 1, y + 1));

						}
						else if (figures[enemyColor][i]->posAlph == y - 1 && figures[enemyColor][i]->posNum == x && figures[enemyColor][i]->lastMovement == moveNo - 1)
						{
							chosenFigure->ableMoves.push_back(sf::Vector2i(x - 1, y - 1));
						}
					}
				}
			}
			x2 = x - 1;
			y2 = y;
			if (!anyOnGrid(x2, y2, 0) &&
				!anyOnGrid(x2, y2, 1) &&
				!willBeCheck())
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
				if (chosenFigure->isMoved == false)
				{

					if (!anyOnGrid(x2 - 1, y, 0) &&
						!anyOnGrid(x2 - 1, y, 1) &&
						!willBeCheck())

					{
						chosenFigure->ableMoves.push_back(sf::Vector2i(x2 - 1, y2));
					}
				}
			}
			x2 = x - 1;
			y2 = y - 1;
			if (anyOnGrid(x2, y2, enemyColor) &&
				!willBeCheck()) {
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}
			x2 = x - 1;
			y2 = y + 1;
			if (anyOnGrid(x2, y2, enemyColor) &&
				!willBeCheck()) {
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}
		}
	}
	else if (chosenFigure->typeID == 1)
	{

		x2 = x + 1;
		y2 = y;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x - 1;
		y2 = y;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			y2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}

	}
	else if (chosenFigure->typeID == 3) {
		x2 = x + 1;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2++;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x + 1;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2++;
			y2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x - 1;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2--;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x - 1;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			y2--;
			x2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
	}
	else if (chosenFigure->typeID == 2) {

		x2 = x + 2;
		y2 = y + 1;
		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x + 2;
		y2 = y - 1;
		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x - 2;
		y2 = y + 1;
		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x - 2;
		y2 = y - 1;
		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}

		x2 = x + 1;
		y2 = y + 2;
		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}

		x2 = x + 1;
		y2 = y - 2;
		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x - 1;
		y2 = y - 2;
		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}

		x2 = x - 1;
		y2 = y + 2;
		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}

	}
	else if (chosenFigure->typeID == 4)
	{
		x2 = x + 1;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2++;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x + 1;
		y2 = y - 1;

		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2++;
			y2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x - 1;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2--;
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x - 1;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			y2--;
			x2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}


		x2 = x + 1;
		y2 = y;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x - 1;
		y2 = y;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			x2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x;
		y2 = y + 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			y2++;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
		x2 = x;
		y2 = y - 1;
		if (anyOnGrid(x2, y2, enemyColor) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		while (!anyOnGrid(x2, y2, 0) &&
			!anyOnGrid(x2, y2, 1) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			y2--;
			if (anyOnGrid(x2, y2, enemyColor) &&
				y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
			{
				chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
			}

		}
	}
	else if (chosenFigure->typeID == 5) {

		x2 = x + 1;
		y2 = y;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x + 1;
		y2 = y + 1;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x;
		y2 = y + 1;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x - 1;
		y2 = y + 1;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x - 1;
		y2 = y;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x - 1;
		y2 = y - 1;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x - 1;
		y2 = y;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x - 1;
		y2 = y - 1;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x;
		y2 = y - 1;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		x2 = x + 1;
		y2 = y - 1;

		if (!anyOnGrid(x2, y2, chosenFigure->isBlack) &&
			y2 < 8 && y2 >= 0 && x2 < 8 && x2 >= 0)
		{
			chosenFigure->ableMoves.push_back(sf::Vector2i(x2, y2));
		}
		int site = chosenFigure->isBlack;

		if (site == 1)
		{
			if (chosenFigure->isMoved == false && figures[1][8]->isMoved == false && figures[1][8]->posNum != -1)
			{
				if (!anyOnGrid(7, 2, 0) && !anyOnGrid(7, 2, 1) &&
					!anyOnGrid(7, 3, 0) && !anyOnGrid(7, 3, 1) &&
					!anyOnGrid(7, 1, 0) && !anyOnGrid(7, 1, 1))
				{
					chosenFigure->ableMoves.push_back(sf::Vector2i(7, 2));
				}
			}
			if (chosenFigure->isMoved == false && figures[1][8]->isMoved == false && figures[1][15]->posNum != -1)
			{
				if (!anyOnGrid(7, 5, 0) && !anyOnGrid(7, 5, 1) &&
					!anyOnGrid(7, 6, 0) && !anyOnGrid(7, 6, 1))
				{
					chosenFigure->ableMoves.push_back(sf::Vector2i(7, 6));
				}

			}
		}
		else
		{

			if (chosenFigure->isMoved == false && figures[1][8]->isMoved == false && figures[0][8]->posNum != -1)
			{
				if (!anyOnGrid(0, 2, 0) && !anyOnGrid(0, 2, 1) &&
					!anyOnGrid(0, 3, 0) && !anyOnGrid(0, 3, 1) &&
					!anyOnGrid(0, 1, 0) && !anyOnGrid(0, 1, 1))
				{
					chosenFigure->ableMoves.push_back(sf::Vector2i(0, 2));
				}
			}
			if (chosenFigure->isMoved == false && figures[1][8]->isMoved == false && figures[0][15]->posNum != -1)
			{
				if (!anyOnGrid(0, 5, 0) && !anyOnGrid(0, 5, 1) &&
					!anyOnGrid(0, 6, 0) && !anyOnGrid(0, 6, 1))
				{
					chosenFigure->ableMoves.push_back(sf::Vector2i(0, 6));
				}

			}
		}


	}
}

bool GameWorld::checkCaseling(int site,int y,int x ) {

	if (site==1)
	{
		if (x == 2 && y == 7 && chosenFigure->isMoved == false && figures[site][8]->isMoved == false && figures[site][8]->posNum != -1)
		{
			if (!anyOnGrid(7,2,0) && !anyOnGrid(7,2,1) &&
				!anyOnGrid(7,3,0) && !anyOnGrid(7,3,1) &&
				!anyOnGrid(7,1,0) && !anyOnGrid(7,1,1))
			{
				chosenFigure->posNum = y;
				chosenFigure->posAlph = x;
				chosenFigure->isMoved = true;
				figures[site][8]->posNum = y;
				figures[site][8]->posAlph = x + 1;
				figures[site][15]->isMoved = true;
				return true;
			}
		}
		else if (x == 6 && y == 7 && chosenFigure->isMoved == false && figures[site][15]->isMoved == false &&  figures[site][15]->posNum != -1)
		{
			if (!anyOnGrid(7,5,0)&& !anyOnGrid(7,5,  1)&&
				!anyOnGrid(7, 6,  0) && !anyOnGrid(7, 6,  1))
			{
				chosenFigure->posNum = y;
				chosenFigure->posAlph = x;
				chosenFigure->isMoved = true;
				figures[site][15]->posNum = y;
				figures[site][15]->posAlph = x - 1;
				figures[site][15]->isMoved = true;
				return true;
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
				return true;
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
				return true;

			}
		}
	}
	return false;

}

bool GameWorld::enPassant(int site,int gridX, int gridY) {

	int enemyColor = 0;
	if (chosenFigure->isBlack == 0)
	{
		enemyColor = 1;
	}
	int x = gridX;
	int y = gridY;
	if (chosenFigure->isBlack == 0)
	{


		if (chosenFigure->posNum == 4)
		{

			for (int i = 0; i < 8; i++)
			{
				if (figures[enemyColor][i]->posNum != -1)
				{
					if (figures[enemyColor][i]->posAlph == y && figures[enemyColor][i]->posNum == 4 && figures[enemyColor][i]->lastMovement == moveNo - 1) {


						takes(4, y);
						chosenFigure->posAlph = y;
						chosenFigure->posNum = x;
						return true;

					}
					else if (figures[enemyColor][i]->posAlph == y && figures[enemyColor][i]->posNum == 4 && figures[enemyColor][i]->lastMovement == moveNo - 1)
					{
						takes(4, y);
						chosenFigure->posAlph = y;
						chosenFigure->posNum = x;
						return true;
					}
				}
			}
		}
	}
	else
	{
		if (chosenFigure->posNum == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				if (figures[enemyColor][i]->posNum != -1)
				{
					if (figures[enemyColor][i]->posAlph == y && figures[enemyColor][i]->posNum == 3 && figures[enemyColor][i]->lastMovement == moveNo - 1) {


						takes(3, y);
						chosenFigure->posAlph = y;
						chosenFigure->posNum = x;
						return true;
					}
					else if (figures[enemyColor][i]->posAlph == y && figures[enemyColor][i]->posNum == 3 && figures[enemyColor][i]->lastMovement == moveNo - 1)
					{
						takes(3, y);
						chosenFigure->posAlph = y;
						chosenFigure->posNum = x;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool GameWorld::isAble(int x , int y, int all) {

	if (all==0)
	{
		if (!anyOnGrid(x, y, chosenFigure->isBlack) &&
			y < 8 && y >= 0 && x < 8 && x >= 0)
		{
			return true;
		}


	}
	else if (all==1)
	{
		if (all == 0)
		{
			if (!anyOnGrid(x, y, chosenFigure->isBlack) &&
				y < 8 && y >= 0 && x < 8 && x >= 0)
			{
				return true;
			}

		}
	}
	else
	{
		if (!anyOnGrid(x, y, 0) &&
			!anyOnGrid(x, y, 1) &&
			y < 8 && y >= 0 && x < 8 && x >= 0)
		{
			return true;
		}
	}
	return false;
}