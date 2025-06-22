#pragma once
#include "Enemy.h"
class Marksman : public Enemy
{
public:

/**
* Constructor of a Marksman
**/
	Marksman(std::string name, int xPos, int yPos);

	Marksman() = default;
	//do i need destructor?
};

