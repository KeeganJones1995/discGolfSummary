/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: dgRound.cpp
 * Purpose: Source file for dgRound object, standard constructor and getter/setters for the dgRound objects
 */
#include "dgRound.h"

dgRound::dgRound(course* newC, player* newP, vector<int> s):dgEvent(newC, newP) {
	scores = s;
	scoreTotal = sumScore(s);
}

dgRound::~dgRound() {
}



int dgRound::getScoreTotal() {
	return scoreTotal;
}

vector<int> dgRound::getScores() {
	return scores;
}

int dgRound::sumScore(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		sum = sum + v.at(i);
	}
	return sum;
}

