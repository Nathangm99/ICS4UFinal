#pragma once
#include "Character.h"
#include <string>
class Enemy : public Character
{
public:

	/**
	* Constructor of a Character
	**/
	Enemy(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, const Weapon* currentWeapon);

	void takeTurn(Character* victim) override;


	/**
	* function to buy a weapon
	*
	* @param weapons[]       The weapons to look at.
	* @param x               Index of new weapon
	*/
	void buyWeapon(int index, const Weapon weapon[]) override;
};

