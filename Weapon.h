#pragma once
#include <string>

class Weapon
{
protected:
	std::string _name;       //name of the weapon
	int _hitChance;         //the chance that the weapon will hit (1-100)
	int _maxAttack;         //The weapon's max attack
	int _minAttack;         //The weapon's min attack
	int _price;             //the weapon's price
	std::string _attackName; //the weapons attack name

public:

	Weapon() = default;//i forget why i put this here?

	Weapon(std::string name, int hitChance, int maxAttack, int minAttack, int price, std::string attackName);
		
	Weapon(const Weapon& other);

	void operator=(const Weapon& other);

	void print();

	std::string getName()
	{
		return _name;
	}

	std::string getAttackName()
	{
		return _attackName;
	}
	int getHitChance()
	{
		return _hitChance;
	}

	int getMaxAttack()
	{
		return _maxAttack;
	}

	int getMinAttack()
	{
		return _minAttack;
	}

	int getPrice()
	{
		return _price;
	}
};