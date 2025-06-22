#include "Marksman.h"
#include <iostream>
#include <string>
#include "Constants.h"
#include "Utils.h"



/**
* Constructor of a Character
**/
Marksman::Marksman(std::string name, int xPos, int yPos)
	:
	Enemy(name, xPos, yPos, 0, 0, 0, 0, nullptr)
{
	//randomize the health for a marksman (they're fragile)
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

	if (newWeapon == 0)
	{
		_currentWeapon = new Weapon("desert eagle", 30, 60, 50, 120, "shoots");
	}
	else if (newWeapon == 1)
	{
		_currentWeapon = new Weapon("pilum", 30, 80, 60, 40, "impales");
	}
	else
	{
		_currentWeapon = new Weapon("bow", 80, 30, 20, 24, "snipes");
	}
}