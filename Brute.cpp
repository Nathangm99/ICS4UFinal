#include "Brute.h"				//for the Brute class
#include <iostream>				//for cout, endl
#include <string>				//for strings
#include "Constants.h"			//for constants
#include "Utils.h"				//for utilites



/**
* Constructor of a Brute
* 
* @param name					the name of the Brute
* @param xPos					the xPos of the Brute
* @param yPos					the yPos of the Brute
**/
Brute::Brute(std::string name, int xPos, int yPos)
	:
	Enemy(name, xPos, yPos, 0, 0, 0, 0, nullptr)
{
	//randomize the health for a brute (they're strong)
	int newHealth = randNumGen(120, 150);
	_health = newHealth;
	_maxHealth = newHealth;

	//randomize the gold for a brute (they're broke)
	int newGold = randNumGen(2, 10);
	_gold = newGold;

	//randomize the potions for a brute (not like theyre gonna use em)
	int newPotions = randNumGen(0, 1);
	_potions = newPotions;

	//randomize the weapon for the brutes (simple weapons)
	int newWeapon = randNumGen(0, 3);

	//1/4 of the time assign this weapon
	if (newWeapon == 0)
	{
		//assign fists
		_currentWeapon =  &weapons[0];
	}
	//1/4 of the time assign this weapon
	else if (newWeapon == 1)
	{
		//assign pugio
		_currentWeapon = &weapons[4];
	}
	//1/4 of the time assign this weapon
	else if (newWeapon == 2)
	{
		//assign gladius
		_currentWeapon = &weapons[8];
	}
	//1/4 of the time assign this weapon
	else
	{
		//assign warhammer
		_currentWeapon = &weapons[5];
	}
}