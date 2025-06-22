#include "Wolf.h"
#include <iostream>
#include <string>
#include "Constants.h"
#include "Utils.h"



/**
* Constructor of a Character
**/
Wolf::Wolf(std::string name, int xPos, int yPos)
	:
	Enemy(name, xPos, yPos, 0, 0, 0, 0, nullptr)
{
	//randomize the health for a Wolf (they're strong)
	int newHealth = randNumGen(120, 150);
	_health = newHealth;
	_maxHealth = newHealth;

	//Gold stays at 0 they're animals

	//Gold stays at 0 they're animals
	 
	
	//randomize the weapon for the Wolf
	int newWeapon = randNumGen(0, 1);
	if (newWeapon == 0)
	{
		_currentWeapon = new Weapon("claws", 80, 15, 10, 0, "punches");
	}
	else
	{
		_currentWeapon = new Weapon("teeth", 70, 70, 30, 0, "bites");
	}
}