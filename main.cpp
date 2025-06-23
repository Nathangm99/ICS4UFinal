#include "Weapon.h"					//for weapon class
#include "Character.h"				//for character class
#include "ICS_ConsoleHelper.h"		// for colors, sleeping, pausing...
#include <conio.h>					//for getting characters 
#include "2DAdventure.h"			// for other functions I stole from my gladiator project
#include "Enemy.h"					//for enemy class
#include "player.h"					//for player class
#include "Constants.h"				//for constants
#include "Brute.h"					//for brute class
#include "Wolf.h"					//for wolf class
#include <fstream>					//for file streams

using namespace std;			// for cout and endl 

//entry point of the program
int main()
{
	//make background black (otherwise leaving and returning to game messes up colour) and clear whatevers on termial
	ICS_BLACK_BACKGROUND;
	system("cls");

	//seed random number
	srand((unsigned int)time(NULL));

	//make the player
	Character* player = new Player("Nathan", 0, 0, 100, 300, 3, 100, &weapons[0]);

	//declare an array to store enemy names
	SuperArray<string>  enemyNames;

	//declare a variable to store input
	string fileInput = "";

	//ifstream object to read data from this file
	ifstream inFile("Enemy Names.txt");

	//check if the file is open
	if (inFile.is_open())
	{
		string token = "";
		while (getline(inFile, token, ','))
		{
			//add the names to the names array
			enemyNames.pushBack(token);
		}
		
		//shuffle the names
		enemyNames.shuffle();
	}
	//if the file doesnt open
	else
	{
		//tell the user the file didn't open
		cout << "File not opening lil bro pack it up\n";
	}


	//make starting enemies
	SuperArray<Character*> enemies;
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		//add an enemy to the array
		addEnemy(enemies, enemyNames);
	}

	//declare the map
	char map[GRID_HEIGHT][GRID_WIDTH];

	//make the map
	{
		//initialize the map
		initializeArray(map);

		//mountain range
		insertArray(map, 7, 3, ROCK);
		insertArray(map, 7, 4, ROCK);
		insertArray(map, 7, 5, ROCK);
		insertArray(map, 8, 5, ROCK);
		insertArray(map, 8, 6, ROCK);

		insertArray(map, 6, 11, ROCK);
		insertArray(map, 7, 11, ROCK);
		insertArray(map, 7, 12, ROCK);

		//river
		insertArray(map, 0, 12, WATER);
		insertArray(map, 1, 12, WATER);
		insertArray(map, 2, 12, WATER);
		insertArray(map, 3, 12, WATER);
		insertArray(map, 3, 13, WATER);
		insertArray(map, 4, 13, WATER);
		insertArray(map, 5, 13, WATER);
		insertArray(map, 5, 14, WATER);
		insertArray(map, 5, 15, BRIDGE);
		insertArray(map, 5, 16, WATER);
		insertArray(map, 5, 17, WATER);
		insertArray(map, 5, 18, WATER);
		insertArray(map, 5, 19, WATER);


		//town
		insertArray(map, TOWN_Y, TOWN_X, TOWN);
	}

	//variable to store user input
	char input;

	//ask user for input until user dies
	while (player->getHealth() > 0)
	{
		//loop through the max number of enemies in the array
		if (enemies.getSize() < MAX_ENEMIES)
		{
			//add all enemies
			addEnemy(enemies, enemyNames);
		}

		//move cursor to top of screen
		COORD pos = { 0, 0 };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);

		//print the map
		printGrid(map, player, enemies);

		//print info under map
		cout << "Enter " << ICS_BLUE_TEXT << "L" << ICS_WHITE_TEXT << " to open legend, and " << ICS_BLUE_TEXT << "W S A D, " << ICS_WHITE_TEXT << "to move\n";
		input = _getch();

		//run the players actions
		playerActions(player, input, map);

		//check if player hit town
		if (map[player->getYPos()][player->getXPos()] == TOWN)
		{
			town(player);
		}

		//make the enemies travel
		enemiesMove(enemies, player, map);

		////Check for collisons////
		collisionCheck(enemies, player, enemyNames);
	}
}