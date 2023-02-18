#include <SFML/Graphics.hpp>
#include <vector>
#ifndef FIGURE_H
#define FIGURE_H

class Figure
{

public:

	Figure(const std::string&, const std::string&, int, int);
	~Figure();

	int typeID;
	int isBlack;
	int posAlph;
	int posNum;
	int lastMovement;
	bool isMoved;

	std::vector<sf::Vector2i>ableMoves;
	void clearMoves();

};



#endif