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
		

	Weapon& operator=(const Weapon& other) = default;

	void print() const;

	std::string getName() const
	{
		return _name;
	}

	std::string getAttackName() const
	{
		return _attackName;
	}
	int getHitChance() const
	{
		return _hitChance;
	}

	int getMaxAttack() const
	{
		return _maxAttack;
	}

	int getMinAttack() const
	{
		return _minAttack;
	}

	int getPrice() const
	{
		return _price;
	}
};