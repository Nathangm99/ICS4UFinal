#pragma once
#include "Enemy.h"			//for enemy class

/**
* the definition of a wolf
*/
class Wolf : public Enemy
{
public:

	/**
	* Constructor of a Wolf
	*
	* @param name					the name of the Wolf
	* @param xPos					the xPos of the Wolf
	* @param yPos					the yPos of the Wolf
	*/
	Wolf(std::string name, int xPos, int yPos);

	Wolf() = default;

};

