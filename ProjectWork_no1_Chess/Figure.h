#include <SFML/Graphics.hpp>
#include <vector>
#ifndef FIGURE_H
#define FIGURE_H

class Figure
{

public:

	
	bool isAlive;
	std::string typeName;
	int typeID;
	int isBlack;
	int posAlph;
	int posNum;
	bool isMoved;
	std::vector<std::vector<bool>>ableMoves;
	void clearMoves();


	Figure(std::string, std::string, int, int);
	~Figure();

};



#endif