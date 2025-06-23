#pragma once
#include "Character.h"			//for the character class
#include <string>				//for strings

/**
*	definition of an Enemy
*/
class Enemy : public Character
{
public:

	/**
	* Constructor of an Enemy
	*
	* @param name					the name of the Enemy
	* @param xPos					the xPos of the Enemy
	* @param yPos					the yPos of the Enemy
	* @param health					the health of the Enemy
	* @param gold					the gold of the Enemy
	* @param potions				the potions of the Enemy
	* @param maxHealth				the maxHealth of the Enemy
	* @param currentWeapon			the currentWeapon of the Enemy
	**/
	Enemy(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, const Weapon* currentWeapon);


	/**
	* Take an automated turn
	*
	* @param victim				the character the turn will be played against
	*/
	void takeTurn(Character* victim) override;


	/**
	* function to buy a weapon(cant happen in enemy)
	*
	* @param weapons[]       The weapons to look at.
	* @param x               Index of new weapon
	*/
	void buyWeapon(int index, const Weapon weapon[]) override;
};

