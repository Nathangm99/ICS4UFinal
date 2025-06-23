#include "Weapon.h"				//for Weapon class
#include "Character.h"			//for Character class
#include <iostream>				//for cout, endl
#include <string>				//for strings
#include "Constants.h"			//for constants
#include "Utils.h"				//for utilities


/**
* Constructor for Character
* 
* @param name					the name of the character
* @param xPos					the xPos of the character
* @param yPos					the yPos of the character
* @param health					the health of the character
* @param gold					the gold of the character
* @param potions				the potions of the character
* @param maxHealth				the maxHealth of the character
* @param currentWeapon			the currentWeapon of the character
*/
Character::Character(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, const Weapon* currentWeapon)
	:	
	_name(name),
	_xPos(xPos),
	_yPos(yPos),
	_health(health),
	_gold(gold),
	_potions(potions),
	_maxHealth(maxHealth),
	_currentWeapon(currentWeapon)
{

}

/**
* Copy Constructor for Character
* 
* @param other			the character who's attributes are being copied and initialzied into the new character
**/
Character::Character(const Character& other)
	:
	_name(other._name),
	_xPos(other._xPos),
	_yPos(other._yPos),
	_health(other._health),
	_gold(other._gold),
	_potions(other._potions),
	_maxHealth(other._maxHealth),
	_currentWeapon(new Weapon(*(_currentWeapon)))
{

}

/**
* Assignment operator for characters
* 
* @param other			the character who's attributes are being copied
*/
void Character::operator=(const Character& other)
{
	//set the values equal to the other character's values
	_name = other._name;
	_xPos = other._xPos;
	_yPos = other._yPos;
	_health = other._health;
	_gold = other._gold;
	_potions = other._potions;
	_maxHealth = other._maxHealth;

	//if current weapon isnt null
	if (_currentWeapon)
	{
		//deallocate memory of the pointer
		delete _currentWeapon;
	}
	//point currentWeapon at a copy of the Weapon the other pointer is pointing at
	_currentWeapon = new Weapon(*(other._currentWeapon));
}

/**
* Destructor of a Character
**/
Character::~Character()
{
	//if the currentWeapon pointer isnt null
	if (_currentWeapon)
	{
		//decallocate currentWeapon
		delete _currentWeapon;
	}
}

/**
* to print the character's attributes
*/
void Character::print()
{
	//print each of the Character's attributes
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Health: " << _health << std::endl;
	std::cout << "Potions: " << _potions << std::endl;
}

/**
* set the weapon of the character
* 
* @param newWeapon			the weapon being given to the character
*/
void Character::setWeapon(const Weapon newWeapon)
{
	//if the currentWeapon pointer isnt null
	if (_currentWeapon)
	{
		//decallocate currentWeapon
		delete _currentWeapon;
	}

	//point the currentWeapon at the new weapon
	_currentWeapon = new Weapon(newWeapon);
}

/**
* makes the Character drink a potion if they have one and are alive.
*/
void Character::drinkPotion()
{
	//if they have potions
	if (_potions > 0)
	{
		//if their health is below max health
		if (_health < _maxHealth)
		{
			//potion adds health
			_health = _health + POTION_HEALTH;

			//let them know it added health
			cout << _name << " drank a potion!\n\n";

			//if it overflows, cap back at max health
			if ( _health > _maxHealth)
			{
				_health = _maxHealth;
			}

			//subtract one potion
			_potions--;

			//exit function
			return;
		}
		//if their health is already at max health
		else if (_health == _maxHealth)
		{
			//let them know they already have full health
			cout << _name << " tries to drink a potion but has full health already!\n\n";

			//exit function
			return;
		}

	}
	//if they have no potions
	else if (_potions == 0)
	{
		//let them know they have full potions
		cout << _name << " tries to drink a potion but has none!\n\n";

		//exit function
		return;
	}
}


/**
* makes the first Character attack the second
*
* @param victim            The guy being attacked.
*/
void Character::attack(Character* victim)
{
	//make the hit number, this is a number from 1 to 100, if it's less than or equal to the hitchance  then it's a hit
	int hitNumber = randNumGen(1, 100);

	//check if it's less than or equal to the hit chance
	if (hitNumber <= _currentWeapon->getHitChance())
	{
		//make the damage number, which is a random number ranging from the min attack to max attack
		int damageNumber = randNumGen(_currentWeapon->getMinAttack(), _currentWeapon->getMaxAttack());

		//print hit statement
		cout << _name << " " <<_currentWeapon->getAttackName() << " " << victim->getName() << " for " << damageNumber << " damage!\n\n";

		//deduct health
		victim->getHealth() -= damageNumber;

		//don't allow negative health
		if (victim->getHealth() < 0)
		{
			victim->getHealth() = 0;
		}
	}
	else
	{
		//print miss statement
		cout << _name << " misses!\n\n";
	}

}



