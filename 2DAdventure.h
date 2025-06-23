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

void addEnemy(SuperArray<Character*> enemies, SuperArray<string>& enemyNames);

/**
* makes two people fight
*
* @param player             The player's strucutre
* @param enemy              The enemy's structure
*
* @returns                  True if the player won, false otherwise
*/
bool fight(Character* player, Character* enemy);

void shop(const Weapon weapons[], Character* player);

void casino(Character* player);

void brewery(Character* player);

void enemiesMove(SuperArray<Character*> enemies, Character* player, char map[GRID_HEIGHT][GRID_WIDTH]);

void collisionCheck(SuperArray<Character*> enemies, Character* player, SuperArray<string> enemyNames);

void town(const Weapon enemies[], Character* player);


/**
*function for opening the legend
*/
void openLegend();

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
