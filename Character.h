#pragma once
#include <string>
#include "Weapon.h"
#include "SuperArray.h"
 
/**
*	definition of a Character
*/
class Character
{
protected:

	std::string _name = "";				  //the Characters name
	int _xPos = 0;						  //which column the Character is on
	int _yPos = 0;						  //which row the player is on
	int _health = 0;				      //how much health the player has
	int _gold = 0;						  //how much gold the player has
	int _potions = 0;					  //how many potions they have
	int _maxHealth = 0;			   	   	  //their max health
	const Weapon* _currentWeapon;				  //their current weapon

public:

	/**
	* Constructor of a Character
	**/
	Character(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, const Weapon* currentWeapon);
	
	/**
	* Copy Constructor of a Character
	**/
	Character(const Character&);

	/**
	* Destructor of a Character
	**/
	virtual ~Character();

	/**
* Operator for Character
**/
	void operator=(const Character& other);
	
	/**
	* prints the Character's important attributes to the console in a user friendly format.
	*
	* @param Character          The Character to print.
	*/
	void print();


	/**
	* makes the Character drink a potion if they have one and are alive.
	*
	* @param Character          The Character trying to drink a potion.
	*/
	void drinkPotion();


	/**
	* function to buy a weapon
	*
	* @param weapons[]       The weapons to look at.
	* @param x               Index of new weapon
	*/
	virtual void buyWeapon(int index, const Weapon weapon[]) = 0;

	void setWeapon(const Weapon newWeapon);

	/**
	* makes the first Character attack the second
	*
	* @param victim            The guy being attacked.
	*/
	void attack (Character* victim);

	std::string getName()
	{
		return _name;
	}

	int& getXPos()
	{
		return _xPos;
	}

	int& getYPos()
	{
		return _yPos;
	}

	int& getHealth()
	{
		return _health;
	}

	int& getGold()
	{
		return _gold;
	}

	int& getPotions()
	{
		return _potions;
	}

	const Weapon* getCurrentWeapon()
	{
		return _currentWeapon;
	}

	int getMaxHealth()
	{
		return _maxHealth;
	}

	virtual void takeTurn(Character* victim) = 0;


};
