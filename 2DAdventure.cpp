#pragma once
#include "2DAdventure.h"		//for declarations

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

/**
* Adds an enemy to the enemy array to keep it always at 5
* 
* @param enemies			//array of enemies
* @param enemyNames			//array of enemy names
*/
void addEnemy(SuperArray<Character*>& enemies, SuperArray<string>& enemyNames)
{
	//the range of the spawn area that theyll spawn in
	int spawnDiff = randNumGen(0, 2);

	//random num to decide which enemy is made
	int enemyType = randNumGen(0, 2);

	//1/3 of the time make a brute
	if (enemyType == 0)
	{
		enemies.pushBack(new Brute(enemyNames[0] + " the Brute", 19 - spawnDiff, 10 - spawnDiff));
	}
	//1/3 of the time make a marksman
	else if (enemyType == 1)
	{
		enemies.pushBack(new Marksman(enemyNames[0] + " the Marksman", 0 + spawnDiff, 10 - spawnDiff));
	}
	//1/3 of the time make a wolf
	else
	{
		enemies.pushBack(new Wolf(enemyNames[0] + " the Wolf", 19 - spawnDiff, 0 + spawnDiff));
	}
	//remove the name from the array
	enemyNames.remove(0);
}

/**
* makes two characters fight
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
		cout << endl;
		enemy->print();

		//pause the program 
		Sleep(SLEEP_TIME);

		//user takes turn
		player->takeTurn(enemy);

		//pause the program
		Sleep(SLEEP_TIME);

		//print both stats
		player->print();
		cout << endl;
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


/**
* The shop function to buy weapons
* 
* @param weapons			array of weapons to choose from
* @param player				the player, so they can change their weapon
*/
void shop(const Weapon weapons[], Character* player)
{
	//boolean to tell whether the user is in the shop
	bool shop = true;

	//while in shop
	while (shop)
	{
		//clear screen
		system("cls");

		//variable to store input
		string input;

		//variable to store chosen weapon index
		int weaponIndex = 0;

		cout << "\t\tWeapon Market!\n";
		cout << "\t\t--------------\n\n";
		cout << "\t\tYour gold: " << player->getGold() << endl;

		//loop through weapons (except teeth and fists)
		for (int i = 3; i < NUM_OF_WEAPONS; i++)
		{
			cout << "\t\t" << weapons[i].getName() << endl;
		}

		//approach user and ask them to do something
		cout << "\nHey! Are you looking to buy or sell? (you could just leave, but don't! I need the sale)\n";
		getline(cin, input);

		//check if they want to buy
		if (input == "buy")
		{
			//make a boolean to check if the input is valid
			bool validName = false;

			//have the user select a weapon
			cout << "\nName a weapon, I'll bring it out for you!\n";
			getline(cin, input);

			//loop through weapons (except fists, teeth and fists)
			for (int i = 3; i < NUM_OF_WEAPONS; i++)
			{
				//check if this weapon was chosen
				if (input == weapons[i].getName())
				{
					//print stats
					weapons[i].print();

					//save weapon index for purchases
					weaponIndex = i;

					//acknowledge it's a valid name
					validName = true;

				}
			}
			//check if chosen weapon was invalid
			if (not validName)
			{
				//print invalid message
				cout << "Invalid! If you aren't gonna buy something, leave!\n";
			}
			//othwerise, if it's valid
			else
			{
				//ask for purchase
				cout << "\nWould you like to buy this weapon?\n";
				getline(cin, input);

				//denied purchase
				if (input == "no")
				{
					//tell user to leave
					cout << "Ok! Then leave! No browsing here\n";
				}
				//approved purchase
				else if (input == "yes")
				{
					//buy it
					player->buyWeapon(weaponIndex, weapons);
				}
				else
				{
					//print invalid message
					cout << "Invalid, what're you talking about?\n";
				}
			}
		}
		//check if they want to sell
		else if (input == "sell")
		{
			//if they have a weapon
			if (player->getCurrentWeapon()->getName() != weapons[0].getName())
			{
				//give the player half their original purchase
				player->getGold() += (player->getCurrentWeapon()->getPrice() * 0.5);

				//print dialogue
				cout << "\nAlright, gimme that...";
				ICS_sleep(SLEEP_TIME);
				cout << "\nHere's your " << ICS_YELLOW_TEXT << (player->getCurrentWeapon()->getPrice() * 0.5) << ICS_RED_TEXT << " gold.\n";

				//assign fists to current weapon
				player->setWeapon(weapons[0]);
			}
			//if they don't have a weapon
			else
			{
				//print dialogue
				cout << "You have nothing to sell!\n";
			}
		}
		//check if they want to leave
		else if (input == "leave")
		{
			//quit loop
			shop = false;
		}
		//invalid inputs
		else
		{
			//print invalid message
			cout << "Invalid input, valid inputs are (buy, sell, leave)\n";
		}
		//pause before loop
		system("pause");
	}
}


/**
* The casino minigame
* 
* @param player				the player who's gonna gamble
*/
void casino(Character* player)
{
	//clear screen
	system("cls");

	//the dealer's minimum number in blackjack
	const int DEALER_MIN_NUM = 17;

	//variable to store bet value
	int bet = 10;

	//boolean to stay in casino loop
	bool casino = true;

	//create boolean to represent if the player is casino town or not
	while (casino)
	{
		//set colors
		cout << ICS_backgroundColor(120, 30, 50);
		cout << ICS_BLACK_TEXT;

		//title
		cout << "------------pompeii Casino--------------\n";
		cout << "-------------Welcome!---------------\n";

		//print player stats
		cout << "Name: " << player->getName() << endl;
		cout << "Money: " << player->getGold() << endl;
		cout << "Bet: " << bet << endl;

		//varible to store input
		string input;

		//Ask player what they want to do
		cout << "What would you like to do? (Valid commands are: slots, blackjack, talk, leave)\n";
		getline(cin, input);

		//Deciding which loop to run
		if (input == "slots")
		{
			//set colors
			cout << ICS_INTENSE_WHITE_BACKGROUND;
			cout << ICS_BLACK_TEXT;

			//while the boolean is true, they stay in this loop
			while (input != "leave")
			{
				//declare variables for random slot numbers
				int rand1 = rand() % 10;
				int rand2 = rand() % 10;
				int rand3 = rand() % 10;

				//title
				cout << "------------pompeii Casino--------------\n";
				cout << "-------------Welcome!---------------\n";

				//print player stats
				cout << "Name: " << player->getName() << endl;
				cout << "Money: " << player->getGold() << endl;
				cout << "Bet: " << bet << endl;

				//Ask player what they want to do and set colors
				cout << ICS_BLACK_TEXT << "What would you like to do? (" << ICS_INTENSE_GREEN_TEXT << " play," << ICS_INTENSE_RED_TEXT << " leave" << ICS_BLACK_TEXT << " or " << ICS_MAGENTA_TEXT << "change bet" << ICS_BLACK_TEXT << ")" << endl;
				getline(cin, input);

				//starts slots
				if (input == "play")
				{
					//if their bet is valid, play
					if (bet <= player->getGold())
					{
						//print message
						cout << endl << endl << "You drop $" << bet << " into the machine.\n\n";

						//lose bet money
						player->getGold() -= bet;

						//print slot numbers
						ICS_sleep(1000);
						cout << rand1 << " ";
						ICS_sleep(1000);
						cout << rand2 << " ";
						ICS_sleep(1000);
						cout << rand3 << endl;

						//if all three numbers are equal
						if (rand1 == rand2 and rand1 == rand3)
						{
							//print message
							cout << "Congragulations! You won 10x your bet!\n";

							//add gold
							player->getGold() = player->getGold() + bet * 10;
						}

						//if 2 numbers in a row are equal
						else if (rand1 == rand2 or rand2 == rand3)
						{
							//print message
							cout << "Congragulations! You won 3x your bet!\n";

							//add gold
							player->getGold() = player->getGold() + bet * 3;
						}
						//none are equal
						else
						{
							//print message
							cout << "You lost! Come back soon!\n";
						}

						//wait for user input to continue
						system("pause");
					}
					else
					{
						//print invalid message
						cout << "I don't think you can bet that!\n";

						//wait for user input to continue
						system("pause");
					}
				}
				//change bet value
				else if (input == "change bet")
				{
					//ask user to change bet
					cout << "What do you want to change your bet to? (Enter a real number that isn't more than what you have and isn't less than one)\n";
					getline(cin, input);

					//make change bet variable and assign it user input
					int changeBet = atoi(input.c_str());


					//check if bet is valid
					if (changeBet >= 1 and changeBet <= player->getGold())
					{
						//change bet
						bet = changeBet;
						cout << "\nYou changed your bet!\n";
					}
					//if bet is invalid
					else
					{
						//print invalid message
						cout << "\nInvalid response! Must be a number >=0 and <= your money\n";

						//wait for user input to continue
						system("pause");
					}
				}
				//free win
				else if (input == "autowin")
				{
					//if their bet is valid, play
					if (bet <= player->getGold())
					{
						//print message
						cout << endl << endl << "You drop $" << bet << " into the machine.\n\n";

						//lose bet money
						player->getGold() -= bet;

						//print slot numbers
						ICS_sleep(1000);
						cout << rand1 << " ";
						ICS_sleep(1000);
						cout << rand1 << " ";
						ICS_sleep(1000);
						cout << rand1 << endl;

						//print message
						cout << "Congragulations! You won 10x your bet!\n";

						//add gold
						player->getGold() = player->getGold() + bet * 10;

					}
					else
					{
						//print invalid message
						cout << "I don't think you can bet that!\n";

						//wait for user input to continue
						system("pause");
					}

					//wait for user input to continue
					system("pause");
				}
				//leaves the loop
				else if (input == "leave")
				{
					//pause
					system("pause");
				}
				//invalid command
				else
				{
					//invalid command
					cout << "That's an invalid command. Valid commands are (" << ICS_INTENSE_GREEN_TEXT << " play," << ICS_INTENSE_RED_TEXT << " leave" << ICS_BLACK_TEXT << " or " << ICS_MAGENTA_TEXT << "change bet" << ICS_BLACK_TEXT << ")" << endl;
					system("pause");
				}
				//clear screen
				system("cls");
			}

		}
		//if they enter blackjack
		else if (input == "blackjack")
		{
			while (input != "leave")
			{
				//set colors
				cout << ICS_INTENSE_YELLOW_BACKGROUND;
				cout << ICS_BLACK_TEXT;

				//title
				cout << "------------pompeii Casino--------------\n";
				cout << "-------------Welcome!---------------\n";

				//print player stats
				cout << "Name: " << player->getName() << endl;
				cout << "Money: " << player->getGold() << endl;
				cout << "Bet: " << bet << endl;

				//Ask player what they want to do and set colors
				cout << "What would you like to do? (" << ICS_INTENSE_GREEN_TEXT << " play," << ICS_INTENSE_RED_TEXT << " leave" << ICS_BLACK_TEXT << " or " << ICS_MAGENTA_TEXT << "change bet" << ICS_BLACK_TEXT << ")" << endl;
				getline(cin, input);

				//playing blackjack
				if (input == "play")
				{
					if (bet <= player->getGold())
					{
						//boolean to leave the loop when they say stand
						bool leave = false;

						//reset computer sum
						int computerSum = 0;

						//make computer card
						int computerCard1 = rand() % 10 + 1;

						////switch to player cards 

						//reset sum
						int sum = 0;

						//make cards
						int card1 = rand() % 10 + 1;
						int card2 = rand() % 10 + 1;
						sum = card1 + card2;

						// deal cards
						cout << "You were dealt a " << card1 << " and a " << card2 << ". Your sum is " << sum << endl;
						cout << "The dealer is showing a " << computerCard1 << endl;

						//while no one's won and loop hasn't been left
						while (sum < 21 and not leave)
						{
							// hit or stand?
							cout << "Do you want to hit or stand?\n";
							getline(cin, input);

							//check if they hit
							if (input == "hit")
							{
								//assign random new card from 1-10
								int newCard = rand() % 10 + 1;
								cout << "You were dealt a " << newCard << endl;

								//add to sum
								sum = sum + newCard;
								cout << "Your total is " << sum << endl;
							}
							//check if they stand
							else if (input == "stand")
							{
								//tell user their total
								cout << "Your total is " << sum << endl;
								leave = true;
							}
							//invalid commmands
							else
							{
								//print invalid statement
								cout << "That's an invalid command. Valid commands are (hit, stand)" << endl;
								system("pause");
							}
						}
						//pause
						system("pause");

						////dealer plays out his turn/////

						//boolean to leave 'stand' loop for dealer
						bool leave2 = false;

						//dealer's other card
						int computerCard2 = rand() % 10 + 1;

						//add to sum
						computerSum = computerCard1 + computerCard2;

						//tell user dealer's card
						cout << "The dealer's second card is " << computerCard2 << ", his total is " << computerSum << endl;

						//while the dealer hasn't quit or gone over 21
						while (computerSum < 21 and leave2 == false)
						{
							//always hit if under 17
							while (computerSum < DEALER_MIN_NUM and leave2 == false)
							{
								//make new card and total
								int newComputerCard = rand() % 10 + 1;
								computerSum = computerSum + newComputerCard;

								//tell user dealer's
								cout << "The dealer hits, he gets a " << newComputerCard << ", his total is " << computerSum << endl;
							}
							//stand if over 17
							while (computerSum >= 17 and leave2 == false)
							{
								//print dealer stats
								cout << "The dealer stands, his total is " << computerSum << endl;
								system("pause");
								leave2 = true;
							}
						}
						//win/loss conditions
						{
							//win
							if ((computerSum > 21 and sum <= 21) or (sum > computerSum and sum <= 21 and computerSum <= 21))
							{
								//tell player how much they won
								cout << "You won $" << bet << endl;
								player->getGold() = player->getGold() + bet;
								system("pause");
							}
							//loss
							else if ((sum > 21) or (computerSum <= 21 and sum <= 21 and computerSum > sum) or (sum > 21 and computerSum > 21))
							{
								//tell player they lost
								cout << "You bust!" << endl;
								player->getGold() = player->getGold() - bet;
								system("pause");

							}
							//tie
							else if (sum == computerSum)
							{
								//tell player it's a push
								cout << "push!" << endl;
								system("pause");
							}
						}
					}
					//if they can't pay
					else
					{
						//tell user they're broke
						cout << "You don't have that much money!\n";
						system("pause");
					}
				}
				//change bet value
				else if (input == "change bet")
				{
					//ask user to change bet
					cout << "What do you want to change your bet to? (Enter a real number that isn't more than what you have and isn't less than one)\n";
					getline(cin, input);

					//make change bet variable and assign it user input
					int changeBet = atoi(input.c_str());

					//if bet is valid
					if (changeBet >= 1 and changeBet <= player->getGold())
					{
						//change bet and tell user
						bet = changeBet;
						cout << "\nYou changed your bet!\n";
					}
					//if bet isn't valid
					else
					{
						//tell user their number is invalid
						cout << "\nInvalid response! Must be a number >=0 and <= your money\n";

						//wait for user input to continue
						system("pause");
					}
				}

				//leave
				else if (input == "leave")
				{
					//pause
					system("pause");
				}
				//invalid commmands
				else
				{
					//print invalid message
					cout << "That's an invalid command. Valid commands are (" << ICS_INTENSE_GREEN_TEXT << " play," << ICS_INTENSE_RED_TEXT << " leave" << ICS_BLACK_TEXT << " or " << ICS_MAGENTA_TEXT << "change bet" << ICS_BLACK_TEXT << ")" << endl;
					system("pause");
				}
			}
		}
		//if user wants to talk
		else if (input == "talk")
		{
			//background colour
			cout << ICS_backgroundColor(205, 152, 240);

			//different results
			int chance = rand() % 4;

			//event 1
			if (chance == 0)
			{
				//placeholder
				string nothing;

				//rich uncle gives you betting money
				int freeCash = rand() % BOB_DONATE_CAP + 1;
				cout << ICS_INTENSE_RED_TEXT;
				cout << "Hey newbie how ya doin?\n";
				getline(cin, nothing);
				cout << "Ahh whatever, take some cash, win big!\n";
				system("pause");
				cout << "Uncle Bob gives you $" << freeCash << " \n";
				system("pause");
				player->getGold() = player->getGold() + freeCash;
			}
			//event 2
			else if (chance == 1)
			{
				//mysterious man gives player a tip
				cout << ICS_BLUE_TEXT;
				cout << "Psst, hey.";
				ICS_sleep(1000);
				cout << " \nOn the slots machine if you type 'autowin', ";
				ICS_sleep(1500);
				cout << "you'll get a free win! Careful though, it only works once a day!\n";
				system("pause");
			}
			//event 3
			else if (chance == 2)
			{
				//user hears the mayor
				ICS_BLACK_BACKGROUND;
				cout << "You hear a big booming laugh, a responding voice stutters something about paying a man back later.\n You turn and see the mayor in the Casino! He seems to be in a tight situation...\n";
				system("pause");
			}
			//event 4
			else if (chance == 3)
			{
				//user encounters a rude Character
				cout << ICS_GREEN_TEXT << "What are you looking at?\n";
				system("pause");
			}
		}
		//if user says to leave
		else if (input == "leave")
		{
			//leave loop
			casino = false;
		}
		//invalid commmand
		else
		{
			//print invalid message
			cout << "That's an invalid command. Valid commands are (slots, blackjack, talk)\n";
			system("pause");
		}
	}
}

/**
* The shop to buy potions
* 
* @param player				the player so they can add potions 
*/
void brewery(Character* player)
{
	//bool to stay in brewery
	bool brewery = true;

	//while in the brewry loop
	while (brewery)
	{
		//clear screen
		system("cls");

		//variable to store user input
		string input;

		//print message for user
		cout << "Welcome to my brewery adventurer!\n Just " << POTION_PRICE << " gold for a healing potion, would you like to buy one?\n";
		getline(cin, input);

		//check if user says yes
		if (input == "yes")
		{
			//check if they can afford it
			if (player->getGold() >= POTION_PRICE)
			{
				//subtract gold and add potion
				player->getGold() -= 30;
				player->getPotions()++;

				//print message to tell player thay got it
				cout << "Here's your potion!\n";

				//pause
				system("pause");

				//quit loop
				brewery = false;
			}
			else
			{
				//tell user they're broke
				cout << "You can't afford one!\n";

				//pause
				system("pause");

				//quit loop
				brewery = false;
			}
		}
		//check if they say no
		else if (input == "no")
		{
			//tell user bye
			cout << "OK, Goodbye then!\n";

			//quit loop
			brewery = false;

			//pause
			system("pause");

		}
		//invalid responses
		else
		{
			//invalid response message
			cout << "Valid responses are (yes, no)\n";

			//pause
			system("pause");
		}
	}
}


/**
* The function to preform all the Enemies travelling
* 
* @param enemies			the array of enemies
* @param player				the player pointer
* @param enemyNames			the array of enemy names
*/
void enemiesMove(SuperArray<Character*> enemies, Character* player, char map[GRID_HEIGHT][GRID_WIDTH])
{
	//loop through enemies movement choices
	for (int i = 0; i < enemies.getSize(); i++)
	{
		//generate a random num from 0-4
		int moveChance = randNumGen(0, 4);

		//move if they're not on the enemies square
		if (player->getYPos() != enemies[i]->getYPos() or player->getXPos() != enemies[i]->getXPos())
		{
			//don't move if moveChance = 0

			//check if moveChance = 1 and movement is valid
			if (moveChance == 1 and enemies[i]->getYPos() - 1 >= 0 and map[enemies[i]->getYPos() - 1][enemies[i]->getXPos()] != WATER and map[enemies[i]->getYPos() - 1][enemies[i]->getXPos()] != ROCK)
			{
				//go north
				enemies[i]->getYPos()--;
			}
			//check if moveChance = 2
			else if (moveChance == 2 and enemies[i]->getYPos() + 1 < GRID_HEIGHT and map[enemies[i]->getYPos() + 1][enemies[i]->getXPos()] != WATER and map[enemies[i]->getYPos() + 1][enemies[i]->getXPos()] != ROCK)
			{
				//go south and movement is valid
				enemies[i]->getYPos()++;
			}
			//check if moveChance = 3
			else if (moveChance == 3 and enemies[i]->getXPos() - 1 >= 0 and map[enemies[i]->getYPos()][enemies[i]->getXPos() - 1] != WATER and map[enemies[i]->getYPos()][enemies[i]->getXPos() - 1] != ROCK)
			{
				//go west and movement is valid
				enemies[i]->getXPos()--;
			}
			//check if moveChance = 4
			else if (moveChance == 4 and enemies[i]->getXPos() + 1 < GRID_WIDTH and map[enemies[i]->getYPos()][enemies[i]->getXPos() + 1] != WATER and map[enemies[i]->getYPos()][enemies[i]->getXPos() + 1] != ROCK)
			{
				//go east and movement is valid
				enemies[i]->getXPos()++;
			}
		}
	}
}


/**
* This function checks if there has been a collision between player and enemy
* 
* @param enemies			array of enemies
* @param player				the player pointer
* @param enemyNames			the array of enemy names
*/
void collisionCheck(SuperArray<Character*> enemies, Character* player, SuperArray<string> enemyNames)
{
	//loop through enemies
	for (int i = 0; i < enemies.getSize(); i++)
	{
		//if the player meets an enemy
		if (player->getYPos() == enemies[i]->getYPos() and player->getXPos() == enemies[i]->getXPos())
		{
			//fight and assign true or false to win
			bool win = fight(player, enemies[i]);

			//check if the player won
			if (win)
			{
				//pause
				ICS_sleep(SLEEP_TIME);

				//add the enemy's name back to the array of names
				enemyNames.pushBack(enemies[i]->getName());

				//remove the enemy from the game
				enemies.remove(i);
			}
		}
	}
}

/**
* The function for the activities preformed in the town
* 
* @param player			the player to be passed into minigames
*/
void town(Character* player)
{

	//create boolean to represent if the player is in town or not
	bool town = true;

	//while in town
	while (town)
	{
		//move cursor to top of screen
		COORD pos = { 0, 0 };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);

		//varible to store input
		string input;

		//set background color
		cout << ICS_WHITE_BACKGROUND;
		cout << ICS_BLACK_TEXT << "You're in the town, do you want to go to the " << ICS_RED_TEXT << "shop, casino, brewery" << ICS_BLACK_TEXT << " or" << ICS_RED_TEXT << " leave" << ICS_RED_TEXT << "?" << endl;
		getline(cin, input);

		//check if they said shop
		if (input == "shop")
		{
			//enter shop
			shop(weapons, player);
		}
		//check if they said casino
		else if (input == "casino")
		{
			//enter casino
			casino(player);
		}
		//check if they said brewery
		else if (input == "brewery")
		{
			//enter brewery
			brewery(player);
		}
		//check if they said to leave
		else if (input == "leave")
		{
			//leave town loop
			town = false;
		}
		//invalid entries
		else
		{
			//print error message
			cout << ICS_BLACK_TEXT << "Invalid input, valid inputs are " << ICS_RED_TEXT << "shop, casino, " << ICS_BLACK_TEXT << "or" << ICS_RED_TEXT << " lounge\n" << ICS_BLACK_TEXT;

			//pause
			system("pause");
		}
	}
	//reset colors to deafault
	system("cls");
	cout << ICS_BLACK_BACKGROUND;
	cout << ICS_WHITE_TEXT;
}

/**
*function for opening the legend
*/
void openLegend()
{
	//clear the screen
	system("cls");

	//print title
	cout << "\t\t\tLegend\n";
	cout << "\t\t\t-------\n";

	//list info
	cout << "\t\t\t" << LAND << " - land\n";
	cout << "\t\t\t" << ROCK << " - rock\n";
	cout << ICS_BLUE_TEXT << "\t\t\t" << WATER << ICS_WHITE_TEXT << " - water\n";
	cout << BROWN_TEXT << "\t\t\t" << BRIDGE << ICS_WHITE_TEXT << " - bridge\n";
	cout << ICS_YELLOW_TEXT << "\t\t\t" << PLAYER << ICS_WHITE_TEXT << " - player\n";
	cout << "\t\t\t" << ENEMY << " - enemy\n";

	//wait for user to quit legend
	system("pause");

	//clear scree n
	system("cls");

}


/**
* the function for handling player actions
* 
* @param player			the player making the actions
* @param input			the input to dictate the action
* @param map			the 2D array that has map info
*/
void playerActions(Character* player, char input, char map[GRID_HEIGHT][GRID_WIDTH])
{
	//check if they clicked L
	if (input == 'l')
	{
		//open legend
		openLegend();
	}
	//check if they clicked W
	else if (input == 'w')
	{
		//if movement is valid
		if (player->getYPos() - 1 >= 0 and player->getYPos() - 1 < GRID_HEIGHT and map[player->getYPos() - 1][player->getXPos()] != WATER and map[player->getYPos() - 1][player->getXPos()] != ROCK)
		{
			//move north
			player->getYPos()--;
		}
	}
	//check if they clicked S
	else if (input == 's')
	{
		//if movement is valid
		if (player->getYPos() + 1 >= 0 and player->getYPos() + 1 < GRID_HEIGHT and map[player->getYPos() + 1][player->getXPos()] != WATER and map[player->getYPos() + 1][player->getXPos()] != ROCK)
		{
			//move south
			player->getYPos()++;
		}
	}
	//check if they clicked A
	else if (input == 'a')
	{
		//if movement is valid
		if (player->getXPos() - 1 >= 0 and player->getXPos() - 1 < GRID_WIDTH and map[player->getYPos()][player->getXPos() - 1] != WATER and map[player->getYPos()][player->getXPos() - 1] != ROCK)
		{
			//move west
			player->getXPos()--;
		}
	}
	//check if they clicked D
	else if (input == 'd')
	{
		//if movement is valid
		if (player->getXPos() + 1 >= 0 and player->getXPos() + 1 < GRID_WIDTH and map[player->getYPos()][player->getXPos() + 1] != WATER and map[player->getYPos()][player->getXPos() + 1] != ROCK)
		{
			//move east
			player->getXPos()++;
		}
	}
	else
	{
		//print invalid statement
		cout << "Invalid input, valid inputs are L, W, S, A, D\n";

		//pause
		system("pause");

		//when screen is overwritten, it doesn't reach invalid statement, so clear
		system("cls");
	}
}


/**
* function to initialize a 2d array with a character
*
* @param grid                      the 2d array to initialize
* @param newCharacter              the character to fill the grid with
*/
void initializeArray(char grid[GRID_HEIGHT][GRID_WIDTH])
{
	//loop through every row
	for (int row = 0; row < GRID_HEIGHT; row++)
	{
		//loop through every column
		for (int column = 0; column < GRID_WIDTH; column++)
		{
			//make it land
			grid[row][column] = LAND;
		}
	}
}

/**
* fuction to print out a given array
*
* @param grid                      the 2d array to print out
*/
void printGrid(char grid[GRID_HEIGHT][GRID_WIDTH], Character* player, SuperArray<Character*> enemies)
{
	bool isEnemy = false;

	//print top border of the map
	cout << endl << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	//loop through all rows
	for (int row = 0; row < GRID_HEIGHT; row++)
	{
		cout << "\t\t\t| ";

		//loop through all columns
		for (int column = 0; column < GRID_WIDTH; column++)
		{
			//loop through enemies
			for (int x = 0; x < enemies.getSize(); x++)
			{
				if (row == enemies[x]->getYPos() and column == enemies[x]->getXPos())
				{
					isEnemy = true;
				}
			}
			//check if the player  is there
			if (row == player->getYPos() and player->getXPos() == column and not isEnemy)
			{
				//print them 
				cout << ICS_YELLOW_TEXT << PLAYER << ICS_WHITE_TEXT << ' ';
			}
			else if (isEnemy)
			{
				//print them 
				cout << ICS_RED_TEXT << ENEMY << ICS_WHITE_TEXT << ' ';
			}
			//check if there's a bridge there
			else if (grid[row][column] == BRIDGE)
			{
				//print it brown
				cout << BROWN_TEXT << grid[row][column] << ICS_WHITE_TEXT << ' ';
			}
			//check if there's water there
			else if (grid[row][column] == WATER)
			{
				//print it blue
				cout << ICS_BLUE_TEXT << grid[row][column] << ICS_WHITE_TEXT << ' ';
			}
			//for any other spot
			else if (not isEnemy)
			{
				//print what's in that box
				cout << grid[row][column] << ' ';
			}
			isEnemy = false;
		}
		//close off the map at the end of each row
		cout << "|";

		//go to next line
		cout << endl;
	}
	// print bottom border of the map
	cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

/**
*function to replace a piece on the grid
*
* @param grid                      //the grid to put the character in
* @param row                       //which row to put it in
* @param column                    //which column to put it in
* @param newCharacter              //the character to insert
*/
void insertArray(char grid[GRID_HEIGHT][GRID_WIDTH], int row, int column, char newCharacter)
{
	grid[row][column] = newCharacter;
}
