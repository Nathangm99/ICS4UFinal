#pragma once
#include "Enemy.h"
class Wolf : public Enemy
{
public:

	/**
	* Constructor of a Marksman
	**/
	Wolf(std::string name, int xPos, int yPos);

	Wolf() = default;
	//do i need destructor?
};

