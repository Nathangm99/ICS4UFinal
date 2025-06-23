#pragma once
#include "Character.h"
#include <string>
class Player : public Character
{
public:

	/**
	* Constructor of an Player
	*
	* @param name					the name of the Player
	* @param xPos					the xPos of the Player
	* @param yPos					the yPos of the Player
	* @param health					the health of the Player
	* @param gold					the gold of the Player
	* @param potions				the potions of the Player
	* @param maxHealth				the maxHealth of the Player
	* @param currentWeapon			the currentWeapon of the Player
	**/
	Player(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, const Weapon* currentWeapon);

	/**
	* The player takes a turn against a character
	*
	* @param victim				the character the turn is taken against
	*/
	void takeTurn(Character* victim) override;

	/**
	* function to buy a weapon
	*
	* @param weapons[]       The weapons to look at.
	* @param x               Index of new weapon
	*/
	void buyWeapon(int index, const Weapon weapon[]) override;
};

