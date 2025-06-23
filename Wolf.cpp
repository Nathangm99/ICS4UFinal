#include "Wolf.h"			//for the wolf class
#include <iostream>			//for cout, endl
#include <string>			//for string
#include "Constants.h"		//for constants
#include "Utils.h"			//for utilities 



/**
* Constructor of a Wolf
* 
* @param name					the name of the Wolf
* @param xPos					the xPos of the Wolf
* @param yPos					the yPos of the Wolf
*/
Wolf::Wolf(std::string name, int xPos, int yPos)
	:
	Enemy(name, xPos, yPos, 0, 0, 0, 0, nullptr)
{
	//randomize the health for a Wolf (they're strong)
	int newHealth = randNumGen(120, 150);
	_health = newHealth;
	_maxHealth = newHealth;

	//Gold stays at 0 they're animals

	//Potions stays at 0 they're animals
	 
	//randomize the weapon for the Wolf
	int newWeapon = randNumGen(0, 1);

	// 1/2 the time
	if (newWeapon == 0)
	{
		//point currentWeapon at teeth
		_currentWeapon = &weapons[1];
	}
	// 1/2 the time
	else
	{
		//point currentWeapon at claws
		_currentWeapon = &weapons[2];
	}
}