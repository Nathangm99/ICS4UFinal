#pragma once
#include "Enemy.h"				//for enemy class

/**
* the definition of a marksman
*/
class Marksman : public Enemy
{
public:

	/**
	* Constructor of a Marksman
	*
	* @param name				the name of the Marksman
	* @param xPos				the xPos of the Marksman
	* @param yPos				the yPos of the Marksman
	**/
	Marksman(std::string name, int xPos, int yPos);

	Marksman() = default;
};

