#include "Utils.h"

/**
*generates a random number
*
* @param min                The minimum value.
* @param max                The maximum value.
*
* @returns                  The random number in between the min and max.
*/
int randNumGen(int min, int max)
{
	return rand() % (max - min + 1) + min;
}