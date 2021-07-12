/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: player.cpp
 * Purpose: Source file for Player object, standard constructor and getter/setters for the player objects
 */
#include "player.h"

player::player(string n) {
	name = n;
	numRounds = 0;
}

player::~player() {

}

string player::getName() {
	return name;
}

int player::getNumRounds() {
	return numRounds;
}

void player::numRoundsPlus1() {
	numRounds++;
}