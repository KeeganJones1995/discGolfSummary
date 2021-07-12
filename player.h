/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: player.h
 * Purpose: Header file for Player object, holds the information for each player like number of rounds played and name
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "course.h"

using namespace std;
using std::string;

class player{
	public:
		player(string);
		~player();
		string getName();
		int getNumRounds();
		void numRoundsPlus1();
	private:
		string name;
		int numRounds;

};

#endif // PLAYER_H