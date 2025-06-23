#pragma once
#include <string>

/**
* The definition for a weapon
*/
class Weapon
{
protected:
	std::string _name;			//name of the weapon
	int _hitChance;				//the chance that the weapon will hit (1-100)
	int _maxAttack;				//The weapon's max attack
	int _minAttack;				//The weapon's min attack
	int _price;					//the weapon's price
	std::string _attackName;	//the weapons attack name

public:

	/**
	* Default constructor for Weapon
	*/
	Weapon() = default;

	/**
	* Copy constructor for a weapon
	*
	* @param copy				the weapon who's attributed are being used to initialized this
	*/
	Weapon(const Weapon* copy);


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
	Weapon(std::string name, int hitChance, int maxAttack, int minAttack, int price, std::string attackName);

	/**
	* to print the attributes
	*/
	void print() const;

	/**
	* retrieve name
	*/
	std::string getName() const
	{
		return _name;
	}

	/**
	* retrieve attackName
	*/
	std::string getAttackName() const
	{
		return _attackName;
	}

	/**
	* retrieve hit chance
	*/
	int getHitChance() const
	{
		return _hitChance;
	}

	/**
	* retrieve max attack
	*/
	int getMaxAttack() const
	{
		return _maxAttack;
	}

	/**
	* retrieve min attack
	*/
	int getMinAttack() const
	{
		return _minAttack;
	}

	/**
	* retrieve price
	*/
	int getPrice() const
	{
		return _price;
	}
};