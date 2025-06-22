#include "Weapon.h"
#include <iostream>
#include <string>

void Weapon::print()
{
	//print each of the weapon's attributes
	std::cout << "\nName:       " << _name << std::endl;
	std::cout << "Hit chance: " << _hitChance << std::endl;
	std::cout << "Max Attack: " << _maxAttack << std::endl;
	std::cout << "Min Attack: " << _minAttack << std::endl;
	std::cout << "Price:      " << _price << std::endl;
}


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

Weapon::Weapon(const Weapon& other)
{
	_name = other._name;
	_hitChance = other._hitChance;
	_maxAttack = other._maxAttack;
	_minAttack = other._minAttack;
	_price = other._price;
	_attackName = other._attackName;
}


void Weapon::operator=(const Weapon& other)
{
	_name = other._name;
	_hitChance = other._hitChance;
	_maxAttack = other._maxAttack;
	_minAttack = other._minAttack;
	_price = other._price;
	_attackName = other._attackName;
}
