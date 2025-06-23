#include "Weapon.h"
#include <iostream>
#include <string>

void Weapon::print() const
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

