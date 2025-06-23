#include "Brute.h"
#include <iostream>
#include <string>
#include "Constants.h"
#include "Utils.h"



/**
* Constructor of a Character
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

	if (newWeapon == 0)
	{
		_currentWeapon =  &weapons[0];
	}
	else if (newWeapon == 1)
	{
		_currentWeapon = &weapons[4];
	}
	else if (newWeapon == 2)
	{
		_currentWeapon = &weapons[8];
	}
	else
	{
		_currentWeapon = &weapons[1];
	}
}