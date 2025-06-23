#include "player.h"
#include <iostream>
#include <string>
#include "Constants.h"
#include "Utils.h"
#include <Windows.h>

/**
* Constructor of an Player
**/
Player::Player(std::string name, int xPos, int yPos, int health, int gold, int potions, int maxHealth, const Weapon* currentWeapon)
	:
	Character(name, xPos, yPos, health, gold, potions, maxHealth, currentWeapon)
{

}

void Player::takeTurn(Character* victim)
{
	//boolean for valid commands
	bool validCommand = false;

	//only play if alive
	if (_health > 0)
	{
		//make input variable for recieving keyboard input.
		string input;

		//while the command is invalid
		while (not validCommand)
		{
			//ask player to enter command
			cout << "What would you like to do? (Valid commands: attack, drink)\n\n";
			getline(cin, input);

			//execute command
			if (input == "attack")
			{
				//valid command
				validCommand = true;

				//execute attack function
				attack(victim);
			}
			else if (input == "drink")
			{
				//valid command
				validCommand = true;

				//execute drinkPotion
				drinkPotion();
			}
			else
			{
				//invalid command, loop
				validCommand = false;

				//invalid command statement
				Sleep(SLEEP_TIME);
				cout << endl << endl << input << " is an invalid command. (Valid commands are:  attack, drink)\n\n";
			}
		}
	}
}

/**
* function to buy a weapon
*
* @param weapons[]       The weapons to look at.
* @param x               Index of new weapon
*/
void Player::buyWeapon(int index, const Weapon weapon[])
{
		//check if they don't have a weapon
		if (_currentWeapon->getName() == weapon[0].getName())
		{
			//check if they can afford it
			if (_gold >= weapon[index].getPrice())
			{
				//charge them
				_gold -= weapon[index].getPrice();

				//give them the weapon
				setWeapon(weapon[index]);

				//say bye
				cout << "Pleasure doin business with you! Off ya go!\n";
			}
			//if they can't afford it
			else
			{
				//tell them they're broke
				cout << "You can't afford that!\n";
			}
		}
		//check if they have a weapon
		else
		{
			cout << "You already have a weapon equipped, sell it before you get this one!\n";
		}
}