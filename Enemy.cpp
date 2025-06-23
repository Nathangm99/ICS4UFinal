#include "Enemy.h"					//for Enemy class
#include <iostream>					//for cout, endl
#include <string>					//for strings
#include "Constants.h"				//for constants
#include "Utils.h"					//for utilities

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
Enemy::Enemy(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, const Weapon* currentWeapon)
	:
	Character(name, xPos, yPos, health, gold, potions, maxHealth, currentWeapon)
{

}

/**
* Take an automated turn
* 
* @param victim				the character the turn will be played against
*/
void Enemy::takeTurn(Character* victim)
{
	//only play if alive
	if (_health > 0)
	{
		//make the drink number, this is a number from 1 to 100, if it's less than or equal to the drinkchance then drink function is executed
		int drink = randNumGen(1, 100);

		//chance of trying to drink potion if health is below 50% and they have a potion
		if (_health < (_maxHealth / 2))
		{
			//check if it's below or equal to the drink chance
			if (drink <= DRINK_CHANCE)
			{
				//execute drinkPotion
				drinkPotion();
			}
			else
			{
				//execute attack function
				attack(victim);
			}
		}
		//chance of trying to drink potion if health is below 30% and they have a potion
		else if (_health < (_maxHealth * 0.3))
		{
			//check if it's below or equal to the drink chance
			if (drink <= LOW_HP_DRINK_CHANCE)
			{
				//execute drinkPotion
				drinkPotion();
			}
			else
			{
				//execute attack function
				attack(victim);
			}
		}
		else
		{
			//execute attack function
			attack(victim);
		}
	}
	//death message
	else
	{
		//tell attacker they died
		cout << _name << " died!\n\n";
	}
}


/**
* function to buy a weapon
*
* @param weapons[]       The weapons to look at.
* @param x               Index of new weapon
*/
void Enemy::buyWeapon(int index, const Weapon weapon[])
{
	cout << "enemy should not be buying a weapon!\n";
}