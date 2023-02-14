#include <SFML/Graphics.hpp>
#include <vector>
#ifndef FIGURE_H
#define FIGURE_H

class Figure
{

public:

	Figure(const std::string&, const std::string&, int, int);
	~Figure();
	std::string typeName;
	int typeID;
	int isBlack;
	int posAlph;
	int posNum;
	bool isMoved;
	std::vector<std::vector<bool>>ableMoves;
	void clearMoves();

};



#endif