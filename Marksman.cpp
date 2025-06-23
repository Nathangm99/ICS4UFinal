#include "Marksman.h"				//for marksman class
#include <iostream>					//for cout, endl
#include <string>					//for strings
#include "Constants.h"				//for constants
#include "Utils.h"					//for utilities



/**
* Constructor of a Marksman
* 
* @param name				the name of the Marksman
* @param xPos				the xPos of the Marksman
* @param yPos				the yPos of the Marksman
**/
Marksman::Marksman(std::string name, int xPos, int yPos)
	:
	Enemy(name, xPos, yPos, 0, 0, 0, 0, nullptr)
{
	//randomize the health/maxHealth for a marksman (they're fragile)
	int newHealth = randNumGen(60, 90);
	_health = newHealth;
	_maxHealth = newHealth;

	//randomize the gold for a marksman (they're wealthy)
	int newGold = randNumGen(70, 80);
	_gold = newGold;

	//randomize the potions for a marksman (they carry a lot)
	int newPotions = randNumGen(4, 7);
	_potions = newPotions;

	//randomize the weapon for the brutes (simple weapons)
	int newWeapon = randNumGen(0, 2);

	// 1/3 of the time
	if (newWeapon == 0)
	{
		//set their weapon to deagle
		_currentWeapon = &weapons[3];
	}
	// 1/3 of the time
	else if (newWeapon == 1)
	{
		//set their weapon to bow
		_currentWeapon = &weapons[6];
	}
	// 1/3 of the time
	else
	{
		//set their weapon to pilum
		_currentWeapon = &weapons[7];
	}
}