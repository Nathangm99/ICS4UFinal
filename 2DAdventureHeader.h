#pragma once
#include <string>                //for strings
#include <iostream>              //for cin and cout
#include <windows.h>             // for Sleep_()
#include <fstream>               // for save file
#include "ICS_ConsoleHelper.h"
#include "ICS_Helpers.h"
#include "SuperArray.h"
#include "Weapon.h"
#include "Character.h"
#include "Constants.h"
#include "Utils.h"
#include "Marksman.h"
#include "Brute.h"
#include "Wolf.h"
#include "player.h"

using namespace std;       //include standard namespace


/**
* prints the fighter's stats
*
* @param player             The player's strucutre
* @param enemy              The enemy's structure
*/
void printStats(Character* player, Character* enemy)
{
	//print stats
	cout << "Your health:  " << player->getHealth() << "/" << player->getMaxHealth() << "\t\t " << enemy->getName() << " health: " << enemy->getHealth() << "/" << enemy->getMaxHealth() << endl;
	cout << "Weapon: " << player->getCurrentWeapon()->getName() << "\t\t\t " << "Weapon: " << enemy->getCurrentWeapon()->getName() << endl;
}

void addEnemy(SuperArray<Character*>& enemies, SuperArray<string>& enemyNames) //NOTE gonna add name array parameter once i have name array, prolly coords too
{
	int spawnDiff = randNumGen(0, 2);
	int enemyType = randNumGen(0, 2);
	if (enemyType == 0)
	{
		enemies.pushBack(new Brute(enemyNames[0] + " the Brute", 19 - spawnDiff, 10 - spawnDiff));
	}
	else if (enemyType == 1)
	{
		enemies.pushBack(new Marksman(enemyNames[0] + " the Marksman", 0 + spawnDiff, 10 - spawnDiff));
	}
	else
	{
		enemies.pushBack(new Wolf(enemyNames[0] + " the Wolf", 19 - spawnDiff, 0 + spawnDiff));
	}
	//remove the name from the array
	enemyNames.remove(0);
}

/**
* makes two people fight
*
* @param player             The player's strucutre
* @param enemy              The enemy's structure
*
* @returns                  True if the player won, false otherwise
*/
bool fight(Character* player, Character* enemy)
{
	//clear screen when function starts
	system("cls");

	//make boolean for valid command
	bool validCommand = false;

	//make input variable for recieving keyboard input.
	string input;

	//stay in loop until someone dies
	while (player->getHealth() > 0 and enemy->getHealth() > 0)
	{
		//clear screen every round
		system("cls");

		//print both stats

		player->print();
		enemy->print();

		//pause the program 
		Sleep(SLEEP_TIME);

		//user takes turn
		player->takeTurn(enemy);

		//pause the program
		Sleep(SLEEP_TIME);

		//print both stats
		player->print();
		enemy->print();

		//pause the program 
		Sleep(SLEEP_TIME);

		//computer takes turn
		enemy->takeTurn(player);

		//pause
		system("pause");
	}

	//if you lose
	if (player->getHealth() == 0)
	{
		cout << "you died to " << enemy->getName() << ".\n";

		//pause
		system("pause");

		//clear screen
		system("cls");

		//return lost
		return false;
	}
	//if you win
	else if (enemy->getHealth() == 0)
	{
		//pause the program 
		Sleep(SLEEP_TIME);

		//tell player they took potions off their opponent
		cout << "\nYou take " << ICS_YELLOW_TEXT << enemy->getGold() << ICS_WHITE_TEXT << " gold off of " << enemy->getName() << "'s body!\n\n";

		//transfer potions
		player->getPotions() += enemy->getPotions();
		enemy->getPotions() = 0;

		//pause
		system("pause");

		//clear screen
		system("cls");

		//return won
		return true;
	}
}