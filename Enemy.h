#pragma once
#include "Character.h"
#include <string>
class Enemy : public Character
{
public:

	/**
	* Constructor of a Character
	**/
	Enemy(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, Weapon* currentWeapon);

	void takeTurn(Character* victim) override;

};

