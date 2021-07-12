/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: main.cpp
 * Purpose: Header file for main object, control flow for the whole program
 */
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <ctime>
#include "reader.h"
#include "analysis.h"


using namespace std;
namespace fs = filesystem;

ofstream newFile;

//find the object associated with a specific course/player pair
dgTotals* findPTotals(player* p, course* course, vector<dgTotals*> v) {
	for (int i = 0; i < (int)v.size(); i++) {
		if (v.at(i)->getCourse() == course && v.at(i)->getPlayer() == p) {
			return v.at(i);
		}
	}
	return NULL;
}

//returns the course object for green lane as we want to hard code that course to be printed out at the top
course* getGreenLane(vector<course*> c) {
	for (int i = 0; i < (int)c.size(); i++) {
		if (c.at(i)->getName() == "greenLane") {
			return c.at(i);
		}
	}
	return NULL;
}

//find the dgTotals object associated with a specific course
dgTotals* findCTotals(course* course, vector<dgTotals*> v) {
	for (int i = 0; i < (int)v.size(); i++) {
		if (v.at(i)->getCourse() == course) {
			return v.at(i);
		}
	}
	return NULL;
}

//prints all of the stats collected in analysis.cpp
void printCourseDetails(course* c, dgTotals* pTotals, dgTotals* cTotals) {
	int diffP = pTotals->getBest() - c->getParTotal();
	int diffC = cTotals->getBest() - c->getParTotal();

	string pPm = "", pCm = "";

	if (diffP > 0) {
		pPm = "+";
	}

	if (diffC > 0) {
		pCm = "+";
	}

	newFile << setprecision(3) << "Course: " << c->getName() << "\nRounds Played: " << pTotals->getRoundsPlayed() << "\tPar: "
		<< c->getParTotal() << "\t\tPersonal Best: " << pTotals->getBest() << "(" + pPm
		<< diffP << ")" << "Personal Average: " << pTotals->getOverallAvg() << "\tThe Boys Best: " 
		<< cTotals->getBest() << "(" << pCm << diffC << ")" << "The Boys Average: " 
		<< cTotals->getOverallAvg() << "\n\n";

	for (int j = 0; j < (int)c->getPars().size(); j++) {
		int tempB = pTotals->getNumBirdies().at(j);
		double tempBP = (1.00 * tempB / pTotals->getTotals().at(j).second) * 100;
		int tempP = pTotals->getNumPars().at(j);
		double tempPP = (1.00 * tempP / pTotals->getTotals().at(j).second) * 100;

		newFile << setprecision(3) << "Hole: " << j + 1 << "\t\tPar: " << c->getPars().at(j) << "\tAverage: "
			<< pTotals->getAvgs().at(j) << "\tThe Boys Averages: " << cTotals->getAvgs().at(j)
			<< "\tBirdies: " << tempB << "\tPercentage: " << tempBP << "%\tPars: " << tempP
			<< "\tPercentage: " << tempPP << "%\n";
	}
}

int main(int args, char* argv[]) {
	vector<string> fileList;
	vector<player*> players;
	vector<course*> courses;
	vector<dgRound*> rounds;
	vector<dgTotals*> pTotals;
	vector<dgTotals*> cTotals;
	reader* r;
	for (auto& p : fs::directory_iterator("C:/Users/habsr/Documents/discGolfScores")) {
		string temp = p.path().string();
		if (temp.substr(temp.size() - 4) == ".csv") {
			fileList.push_back(temp);
		}
	}
	r = new reader(fileList);
	r->read(players, courses, rounds);
	analysis a;
	a.analyze(players, courses, rounds, pTotals, cTotals);
	
	time_t currDate;
	struct tm timeInfo;
	time(&currDate);
	localtime_s(&timeInfo, &currDate);
	int year = 1900 + timeInfo.tm_year;
	int month = 1 + timeInfo.tm_mon;
	int day = timeInfo.tm_mday;
	string monthArr[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	string pathEnd = to_string(day) + monthArr[timeInfo.tm_mon] + to_string(year) + "Analysis.txt";
	string d = "C:/Users/habsr/Documents/discGolfScores/discGolfSummary/" + pathEnd;
	
	newFile.open(d);
	
	newFile << "Disc Golf Summary\nAs of: " + monthArr[timeInfo.tm_mon] + " " + to_string(day) + " " + to_string(year) + "\n\n";
	
	course* gl = getGreenLane(courses);


	for (int i = 0; i < (int)players.size(); i++) {
		newFile << "Player: " + players.at(i)->getName() + "\nNumber of Rounds: " + to_string(players.at(i)->getNumRounds()) 
			+ "\n\n";
		
		dgTotals* tempPSummary = findPTotals(players.at(i), gl, pTotals);
		dgTotals* tempCSummary = findCTotals(gl, cTotals);
		
		if (tempPSummary != NULL) {
			printCourseDetails(gl, tempPSummary, tempCSummary);
		}

		for (int j = 0; j < (int)courses.size(); j++) {
			course* c = courses.at(j);
			tempPSummary = findPTotals(players.at(i), c, pTotals);
			tempCSummary = findCTotals(c, cTotals);
			if (c->getName() != "greenLane" && tempPSummary != NULL && tempCSummary != NULL) {
				printCourseDetails(courses.at(j), tempPSummary, tempCSummary);
				newFile << "\n";
			}
		}
		
		newFile << "\n\n";

	}


	for (int i = 0; i < (int)rounds.size(); i++) {
		delete rounds.at(i);
	}

	for (int i = 0; i < (int)pTotals.size(); i++) {
		delete pTotals.at(i);
	}

	for (int i = 0; i < (int)cTotals.size(); i++) {
		delete cTotals.at(i);
	}

	for (int i = 0; i < (int)courses.size(); i++) {
		delete courses.at(i);
	}

	for (int i = 0; i < (int)players.size(); i++) {
		delete players.at(i);
	}


	delete r;


	newFile.close();

}

