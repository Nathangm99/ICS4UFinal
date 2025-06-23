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
void printStats(Character* player, Character* enemy);

/**
* Adds an enemy to the enemy array to keep it always at 5
*
* @param enemies			//array of enemies
* @param enemyNames			//array of enemy names
*/
void addEnemy(SuperArray<Character*>& enemies, SuperArray<string>& enemyNames);

/**
* makes two people fight
*
* @param player             The player's strucutre
* @param enemy              The enemy's structure
*
* @returns                  True if the player won, false otherwise
*/
bool fight(Character* player, Character* enemy);

/**
* The shop function to buy weapons
*
* @param weapons			array of weapons to choose from
* @param player				the player, so they can change their weapon
*/
void shop(const Weapon weapons[], Character* player);

/**
* The casino minigame
*
* @param player				the player who's gonna gamble
*/
void casino(Character* player);

/**
* The shop to buy potions
*
* @param player				the player so they can add potions
*/
void brewery(Character* player);

/**
* The function to preform all the Enemies travelling
*
* @param enemies			the array of enemies
* @param player				the player pointer
* @param enemyNames			the array of enemy names
*/
void enemiesMove(SuperArray<Character*> enemies, Character* player, char map[GRID_HEIGHT][GRID_WIDTH]);



/**
* This function checks if there has been a collision between player and enemy
*
* @param enemies			array of enemies
* @param player				the player pointer
* @param enemyNames			the array of enemy names
*/
void collisionCheck(SuperArray<Character*> enemies, Character* player, SuperArray<string> enemyNames);

/**
* The function for the activities preformed in the town
*
* @param player			the player to be passed into minigames
*/
void town(Character* player);


/**
*function for opening the legend
*/
void openLegend();

/**
* the function for handling player actions
*
* @param player			the player making the actions
* @param input			the input to dictate the action
* @param map			the 2D array that has map info
*/
void playerActions(Character* player, char input, char map[GRID_HEIGHT][GRID_WIDTH]);


/**
* function to initialize a 2d array with a character
*
* @param grid                      the 2d array to initialize
* @param newCharacter              the character to fill the grid with
*/
void initializeArray(char grid[GRID_HEIGHT][GRID_WIDTH]);

/**
* fuction to print out a given array
*
* @param grid                      the 2d array to print out
*/
void printGrid(char grid[GRID_HEIGHT][GRID_WIDTH], Character* player, SuperArray<Character*> enemies);

/**
*function to replace a piece on the grid
*
* @param grid                      //the grid to put the character in
* @param row                       //which row to put it in
* @param column                    //which column to put it in
* @param newCharacter              //the character to insert
*/
void insertArray(char grid[GRID_HEIGHT][GRID_WIDTH], int row, int column, char newCharacter);
