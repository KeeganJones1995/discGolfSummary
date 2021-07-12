/*Disc Golf Score Summary 
 * Made By: Keegan Jones
 * File: Analysis.h
 * Purpose: Header file for Analysis object, which will hold the functions used iterate through the rounds and create totals and avgs
 */
#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <string>
#include <vector>
#include "player.h"
#include "course.h"
#include "dgTotals.h"
#include "dgRound.h"

using namespace std;
using std::string;

class analysis {
public:
	analysis();
	~analysis();
	void analyze(vector<player*>&, vector<course*>&, vector<dgRound*>&, vector<dgTotals*>&, vector<dgTotals*>&);
private:
	int pairExists(player*, course*, vector<dgTotals*>&);
	void countBirdies(dgRound*, dgTotals*);
	void countPars(dgRound*, dgTotals*);
	int courseExists(course*, vector<dgTotals*>&);

};

#endif // ANALYSIS_H