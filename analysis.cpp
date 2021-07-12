/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: Analysis.cpp
 * Purpose: Source file for Analysis object, which will hold the functions used iterate through the rounds and create totals and avgs
 */
#include "analysis.h"
#include <iostream>

analysis::analysis() {}

analysis::~analysis() {}

//main function in analysis.cpp, used to iterate through all rounds and summarize data
void analysis::analyze(vector<player*> &p, vector<course*> &c, vector<dgRound*> &r, vector<dgTotals*> &playerTotals, vector<dgTotals*>& courseTotals) {
	for (int i = 0; i < (int)r.size(); i++) { //iterate through all rounds
		player* tempP = r.at(i)->getPlayer();
		course* tempC = r.at(i)->getCourse();
		int pIndex = pairExists(tempP, tempC, playerTotals);//get index of specific round within course vector and player vector
		int cIndex = courseExists(tempC, courseTotals);
		if (pIndex == -1) {//checks if player exists
			dgTotals* newTotal = new dgTotals(tempC, tempP, r.at(i)->getScores());
			pIndex = (int)playerTotals.size();
			playerTotals.push_back(newTotal);
		}
		else {
			playerTotals.at(pIndex)->addScore(r.at(i)->getScores());
		}
		playerTotals.at(pIndex)->incRP();//increase rounds played
		if (r.at(i)->getScores().size() == tempC->getPars().size()) {
			playerTotals.at(pIndex)->checkBest(r.at(i)->getScoreTotal());
		}
		if (cIndex == -1) {//check if the course exists
			dgTotals* newTotal = new dgTotals(tempC, tempP, r.at(i)->getScores());
			cIndex = (int)courseTotals.size();
			courseTotals.push_back(newTotal);
		}
		else {
			courseTotals.at(cIndex)->addScore(r.at(i)->getScores());
		}
		courseTotals.at(cIndex)->incRP();
		if (r.at(i)->getScores().size() == tempC->getPars().size() && r.at(i)->getPlayer()->getName() != "Duo") {
			courseTotals.at(cIndex)->checkBest(r.at(i)->getScoreTotal());
		}
		countBirdies(r.at(i), playerTotals.at(pIndex));
		countBirdies(r.at(i), courseTotals.at(cIndex));
		countPars(r.at(i), playerTotals.at(pIndex));
		countPars(r.at(i), courseTotals.at(cIndex));
	}
	for(int i = 0; i < (int)playerTotals.size(); i++) {//takes the sum of all scores and creates an average for each player for a specific course
		playerTotals.at(i)->setAvgs();
		playerTotals.at(i)->setOverallAvg();

	}
	for (int i = 0; i < (int)courseTotals.size(); i++) {//takes the sum of all scores and creates an average for a specific course
		courseTotals.at(i)->setAvgs();
		courseTotals.at(i)->setOverallAvg();
	}

}

int analysis::pairExists(player* p, course* c, vector<dgTotals*>& playerTotals) {// checks if a specific course-player combination exists
	for (int i = 0; i < (int)playerTotals.size(); i++) {
		if (playerTotals.at(i)->getCourse() == c && playerTotals.at(i)->getPlayer() == p) {
			return i;
		}
	}
	return -1;
}

void analysis::countBirdies(dgRound* r, dgTotals* t) {
	for (int j = 0; j < (int)r->getScores().size(); j++) {
		if (r->getCourse()->getPars().at(j) > r->getScores().at(j)) {
			t->setNumBirdies(j);
		}
	}
}

void analysis::countPars(dgRound* r, dgTotals* t) {
	for (int j = 0; j < (int)r->getScores().size(); j++) {
		if (r->getCourse()->getPars().at(j) == r->getScores().at(j)) {
			t->setNumPars(j);
		}
	}
}

int analysis::courseExists(course* c, vector<dgTotals*>& courseTotals) {
	for (int i = 0; i < (int)courseTotals.size(); i++) {
		if (courseTotals.at(i)->getCourse() == c) {
			return i;
		}
	}
	return -1;
}