#pragma once
#include "Enemy.h"
#include <string>
class Brute : public Enemy
{
	public:
	/**
	* Constructor of a Brute
	**/
	Brute(std::string name, int xPos, int yPos);

	Brute() = default;
	//do i need destructor?
};

