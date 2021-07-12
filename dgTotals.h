/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File:dgTotals.h
 * Purpose: Header file for dgTotals object, contains the statistics summarizing the rounds
 */
#ifndef DGTOTALS_H
#define DGTOTALS_H

using namespace std;

#include <string>
#include <vector>
#include "course.h"
#include "player.h"
#include "dgEvent.h"

using std::string;

class dgTotals : public dgEvent {
public:
	dgTotals(course*, player*, vector<int>);
	~dgTotals();
	void addScore(vector<int>);
	void setAvgs();
	vector<double> getAvgs();
	void setNumBirdies(int);
	void setNumPars(int);
	void setBirdies(int);
	void setPars(int);
	double getIndAvgs(int);
	int getRoundsPlayed();
	void incRP();
	void checkBest(int);
	int getBest();
	vector<int> getNumBirdies();
	vector<int> getNumPars();
	vector<pair<int, int>> getTotals();
	double getOverallAvg();
	void setOverallAvg();
private:
	void setSums(vector<int>);
	vector<pair<int, int>> totals;
	vector<double> avgs;
	vector<int> numBirdies;
	vector<int> numPars;
	int roundsPlayed;
	int best;
	double overallAvg;
};

#endif // DGROUND_H