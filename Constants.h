#pragma once
#include "ICS_ConsoleHelper.h"   //for colors

//constants
const int DRINK_CHANCE = 40;               //the % chance the AI drinks a potion
const int LOW_HP_DRINK_CHANCE = 20;        //the % chance the AI drinks a potion when they're near death
const int SLEEP_TIME = 500;                //sleep time in milliseconds
const int POTION_HEALTH = 30;              //how much health a potion gives
const int MAX_ENEMIES = 5;				   // how many enemies there can be at once

// constants for text and background colors (using RGB colors)
const string BROWN_TEXT = ICS_textColor(135, 84, 56);
const string PINK_TEXT = ICS_textColor(255, 174, 201);
const string ORANGE_BG = ICS_backgroundColor(255, 165, 0);
const string PURPLE_BG = ICS_backgroundColor(64, 0, 128);

//constants for map
const int GRID_HEIGHT = 10;
const int GRID_WIDTH = 20;
const char WATER = 254;
const char BRIDGE = 178;
const char ROCK = 'R';
const char LAND = '_';
const char ENEMY = 'E';
const char PLAYER = 'P';

const char TOWN = 223;
const int BOB_DONATE_CAP = 1000;
const int NUM_OF_WEAPONS = 9;
const int POTION_PRICE = 30;
const int TOWN_Y = 3;
const int TOWN_X = 19;


//make weapons
const Weapon weapons[] =
{
	Weapon("fists", 100, 20 , 5, 0, "punches"),
	Weapon("teeth", 70, 70, 30, 0, "bites"),
	Weapon("claws", 80, 15, 10, 0, "gouges"),
	Weapon("deagle", 30, 60, 50, 120, "shoots"),
	Weapon("pugio", 100, 30, 15, 55, "stabs"),
	Weapon("Warhammer", 60, 70, 10, 60, "bludgeon"),
	Weapon("bow", 80, 30, 20, 24, "snipes"),
	Weapon("pilum", 30, 80, 60, 40, "impales"),
	Weapon("gladius", 65, 60, 50, 30, "slashes")
};