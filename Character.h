#pragma once
#include <string>				//for strings
#include "Weapon.h"				//for the Weapon class
#include "SuperArray.h"			//for the superArray class
 
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
	const Weapon* _currentWeapon;		  //their current weapon

public:

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
	Character(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, const Weapon* currentWeapon);
	
	/**
	* Copy Constructor for Character
	*
	* @param other			the character who's attributes are being copied and initialzied into the new character
	**/
	Character(const Character&);

	/**
	* Destructor of a Character
	**/
	virtual ~Character();

	/**
	* Assignment operator for characters
	*
	* @param other			the character who's attributes are being copied
	*/
	void operator=(const Character& other);
	
	/**
	* to print the character's attributes
	*/
	void print();


	/**
	* makes the Character drink a potion if they have one and are alive.
	*/
	void drinkPotion();


	/**
	* function to buy a weapon
	*
	* @param weapons[]       The weapons to look at.
	* @param x               Index of new weapon
	*/
	virtual void buyWeapon(int index, const Weapon weapon[]) = 0;


	/**
	* set the weapon of the character
	*
	* @param newWeapon			the weapon being given to the character
	*/
	void setWeapon(const Weapon newWeapon);

	/**
	* makes the first Character attack the second
	*
	* @param victim            The guy being attacked.
	*/
	void attack (Character* victim);


	/**
	* retrieves character's name 
	*/
	std::string getName()
	{
		return _name;
	}

	/**
	* retrieves character's xPos
	*/
	int& getXPos()
	{
		return _xPos;
	}

	/**
	* retrieves character's yPos
	*/
	int& getYPos()
	{
		return _yPos;
	}

	/**
	* retrieves character's health
	*/
	int& getHealth()
	{
		return _health;
	}

	/**
	* retrieves character's gold
	*/
	int& getGold()
	{
		return _gold;
	}

	/**
	* retrieves character's potions
	*/
	int& getPotions()
	{
		return _potions;
	}

	/**
	* retrieves character's currentWeapon 
	*/
	const Weapon* getCurrentWeapon()
	{
		return _currentWeapon;
	}

	/**
	* retrieves character's max health
	*/
	int getMaxHealth()
	{
		return _maxHealth;
	}

	/**
	* plays a turn 
	*/
	virtual void takeTurn(Character* victim) = 0;


};
