#include "Weapon.h"				//for the weapon class
#include <iostream>				//for cout, endl
#include <string>				//for strings


/**
* printing the attributes of each weapon
*/
void Weapon::print() const
{
	//print each of the weapon's attributes
	std::cout << "\nName:       " << _name << std::endl;
	std::cout << "Hit chance: " << _hitChance << std::endl;
	std::cout << "Max Attack: " << _maxAttack << std::endl;
	std::cout << "Min Attack: " << _minAttack << std::endl;
	std::cout << "Price:      " << _price << std::endl;
}

/**
* Copy constructor for a weapon
* 
* @param copy				the weapon who's attributed are being used to initialized this
*/
Weapon::Weapon(const Weapon* copy) :
	_name(copy->_name),
	_hitChance(copy->_hitChance),
	_maxAttack(copy->_maxAttack),
	_minAttack(copy->_minAttack),
	_price(copy->_price),
	_attackName(copy->_attackName)
{
}

/**
* Constructor for a weapon
* 
* @param name					the name of the weapon
* @param hitChance				the hitChance of the weapon
* @param maxAttack				the maxAttack of the weapon
* @param minAttack				the minAttack of the weapon
* @param price					the price of the weapon
* @param attackName				the attack name of the weapon
*/
Weapon::Weapon(std::string name, int hitChance, int maxAttack, int minAttack, int price, std::string attackName)
	:
	_name(name),
	_hitChance(hitChance),
	_maxAttack(maxAttack),
	_minAttack(minAttack),
	_price(price),
	_attackName(attackName)
{

}

