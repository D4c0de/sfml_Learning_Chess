#include <SFML/Graphics.hpp>
#include <string>
#include "Figure.h"
#include <vector>

Figure::Figure(const std::string& type, const std::string& site, int alph, int num) {
	
	posAlph = alph;
	posNum = num;
	isMoved = false;
	if (site == "white")
	{
		isBlack =false;
	}
	else
	{
		isBlack = true;
	}

	if (type=="pawn")
	{
		typeID = 0;
	}
	else if(type == "rook")
	{
		typeID = 1;
	}
	else if (type == "knight")
	{
		typeID = 2;
	}
	else if (type == "bishop")
	{
		typeID = 3;
	}
	else if (type == "queen")
	{
		typeID = 4;
	}
	else if (type == "king")
	{
		typeID = 5;
	}
	setUpPatern();
}
void Figure::clearMoves() {
	ableMoves.clear();
}

Figure::~Figure() {


}
void Figure::setUpPatern() {
	switch (typeID)
	{
	case(1):
		movePatern.push_back(sf::Vector2i(1, 0));
		movePatern.push_back(sf::Vector2i(-1, 0));
		movePatern.push_back(sf::Vector2i(0, 1));
		movePatern.push_back(sf::Vector2i(0, -1));
		break;
	case(2):
		movePatern.push_back(sf::Vector2i(2, 1));
		movePatern.push_back(sf::Vector2i(2, -1));
		movePatern.push_back(sf::Vector2i(-2, 1));
		movePatern.push_back(sf::Vector2i(-2, -1));
		movePatern.push_back(sf::Vector2i(1, 2));
		movePatern.push_back(sf::Vector2i(1, -2));
		movePatern.push_back(sf::Vector2i(-1, 2));
		movePatern.push_back(sf::Vector2i(-1, -2));
		break;
	case(3):
		movePatern.push_back(sf::Vector2i(1, 1));
		movePatern.push_back(sf::Vector2i(-1, -1));
		movePatern.push_back(sf::Vector2i(-1, 1));
		movePatern.push_back(sf::Vector2i(1, -1));
		break;
	case(4):
		movePatern.push_back(sf::Vector2i(1, 1));
		movePatern.push_back(sf::Vector2i(-1, -1));
		movePatern.push_back(sf::Vector2i(-1, 1));
		movePatern.push_back(sf::Vector2i(1, -1));
		movePatern.push_back(sf::Vector2i(1, 0));
		movePatern.push_back(sf::Vector2i(-1, 0));
		movePatern.push_back(sf::Vector2i(0, 1));
		movePatern.push_back(sf::Vector2i(0, -1));
		break;
	}
}