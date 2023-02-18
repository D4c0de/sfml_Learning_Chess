#include <SFML/Graphics.hpp>
#include <string>
#include "Figure.h"

Figure::Figure(const std::string& type, const std::string& site, int alph, int num) {
	
	posAlph = alph;
	posNum = num;
	if (site == "white")
	{
		isBlack =0;
	}
	else
	{
		isBlack = 1;
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

}
void Figure::clearMoves() {
	ableMoves.clear();
}

Figure::~Figure() {


}