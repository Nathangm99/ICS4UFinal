#include "Weapon.h"
#include "Character.h"
#include <iostream>
#include <string>
#include "Constants.h"
#include "Utils.h"


Character::Character(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, Weapon* currentWeapon)
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
* Copy Constructor of a Character
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
	_currentWeapon(other._currentWeapon)
{

}

void Character::print()
{
	//print each of the Character's attributes
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Health: " << _health << std::endl;
	std::cout << "Potions: " << _potions << std::endl;
}

/**
* Destructor of a Character
**/
Character::~Character()
{
	if(_currentWeapon != nullptr)
	{
		delete _currentWeapon; 
	}
}

/**
* Operator for Character
**/
void Character::operator=(const Character& other)
{
	_name = other._name;
	_xPos = other._xPos;
	_yPos = other._yPos;
	_health = other._health;
	_gold = other._gold;
	_potions = other._potions;
	_maxHealth = other._maxHealth;
	delete _currentWeapon;
	_currentWeapon = other._currentWeapon;
}

void Character::setWeapon(const Weapon* newWeapon)
{
	delete _currentWeapon;

	//cam taught me derefrencing
	//set the characters current weapon to the new one
	_currentWeapon = new Weapon(*(newWeapon));
}

/**
* makes the Character drink a potion if they have one and are alive.
*/
void Character::drinkPotion()
{
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
* function to buy a weapon
*
* @param weapons[]       The weapons to look at.
* @param x               Index of new weapon
*/
void Character::buyWeapon(SuperArray<Weapon*> weapons, int x)
{
	//check if they don't have a weapon
	if (_currentWeapon->getName() == weapons[0]->getName())
	{
		//check if they can afford it
		if (_gold >= weapons[x]->getPrice())
		{
			//charge them
			_gold -= weapons[x]->getPrice();

			//give them the weapon
			setWeapon(weapons[x]);

			//say bye
			cout << "Pleasure doin business with you! Off ya go!\n";
		}
		//if they can't afford it
		else
		{
			//
			cout << "You can't afford that!\n";
		}
	}
	//check if they have a weapon
	else
	{
		cout << "You already have a weapon equipped, sell it before you get this one!\n";
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



