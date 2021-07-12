/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: dgRound.h
 * Purpose: Header file for dgRound object, holds the information for one instance of one persons round
 */
#ifndef DGROUND_H
#define DGROUND_H

using namespace std;

#include <string>
#include <vector>
#include "course.h"
#include "player.h"
#include "dgEvent.h"

using std::string;

class dgRound: public dgEvent {
public:
	dgRound(course*, player*, vector<int>);
	~dgRound();
	int getScoreTotal();
	vector<int> getScores();
private:
	int scoreTotal;
	int sumScore(vector<int>);
	vector<int> scores;

};

#endif // DGROUND_H