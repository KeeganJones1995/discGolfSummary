/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File:dgTotals.cpp
 * Purpose: Source file for dgTotals object, contains the statistics summarizing the rounds
 */
#include "dgTotals.h"

dgTotals::dgTotals(course* newC, player* newP, vector<int> s) :dgEvent(newC, newP) {
	setSums(newC->getPars());
	addScore(s);
	setBirdies((int)newC->getPars().size());
	setPars((int)newC->getPars().size());
	best = 897;
}

dgTotals::~dgTotals() {}


//adds score to the totals vector, which just combines all the scores to later be divided by number of times played to get average
void dgTotals::addScore(vector<int> a) {
	for (int i = 0; i < (int)totals.size(); i++) {
		if (i < (int)a.size()) {
			totals.at(i).first = totals.at(i).first + a.at(i);
			totals.at(i).second++;
		}
	}
	
}

void dgTotals::setSums(vector<int> s) {
	for (int i = 0; i < (int)s.size(); i++) {
		totals.push_back({ 0, 0 });
	}
}
//create average from the totals vector
void dgTotals::setAvgs() {
	for (int i = 0; i < (int)totals.size(); i++) {
		double temp = (totals.at(i).first * 1.0) / totals.at(i).second;
		temp = round(temp * 1000) / 1000;
		avgs.push_back(temp);
	}
}

vector<double> dgTotals::getAvgs() {
	return avgs;
}

void dgTotals::setNumBirdies(int i) {
	numBirdies.at(i)++;
}

void dgTotals::setNumPars(int i){
	numPars.at(i)++;
}

void dgTotals::setBirdies(int s) {
	for (int i = 0; i < s; i++) {
		numBirdies.push_back(0);
	}
}

void dgTotals::setPars(int s) {
	for (int i = 0; i < s; i++) {
		numPars.push_back(0);
	}
}

double dgTotals::getIndAvgs(int i) {
	return avgs.at(i);
}

int dgTotals::getRoundsPlayed() {
	return roundsPlayed;
}

void dgTotals::incRP() {
	roundsPlayed++;
}

void dgTotals::checkBest(int s) {
	if (s < best) {
		best = s;
	}
}

int dgTotals::getBest() {
	return best;
}

vector<int> dgTotals::getNumBirdies() {
	return numBirdies;
}

vector<int> dgTotals::getNumPars() {
	return numPars;
}

vector<pair<int, int>> dgTotals::getTotals() {
	return totals;
}

double dgTotals::getOverallAvg() {
	return overallAvg;
}

//sets the average total score
void dgTotals::setOverallAvg() {
	for (int i = 0; i < (int)avgs.size(); i++) {
		overallAvg += avgs.at(i);
	}
}