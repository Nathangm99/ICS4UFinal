#pragma once
#include "Enemy.h"				//for enemy class

/**
* Constructor of a Brute
*
* @param name					the name of the Brute
* @param xPos					the xPos of the Brute
* @param yPos					the yPos of the Brute
**/
class Brute : public Enemy
{
	public:
	/**
	* Constructor of a Brute
	**/
	Brute(std::string name, int xPos, int yPos);

	Brute() = default;
};

