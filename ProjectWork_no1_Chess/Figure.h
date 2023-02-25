#include <SFML/Graphics.hpp>
#include <vector>
#ifndef FIGURE_H
#define FIGURE_H

class Figure
{

public:

	Figure();
	Figure(const std::string&, const std::string&, int, int);
	~Figure();

	int typeID;
	bool isBlack;
	int posAlph;
	int posNum;
	int lastMovement;
	bool isMoved;
	std::vector<sf::Vector2i>movePatern;
	std::vector<sf::Vector2i>ableMoves;

	void setUpPatern();
	void clearMoves();

};


#endif