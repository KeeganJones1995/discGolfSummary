/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: reader.cpp
 * Purpose: Source file for Reader object, for iterating through the csv files and transforming them into usable objects
 */
#include "reader.h"
#include <fstream>
#include <iostream>
#include <sstream>

reader::reader(vector<string> list) {
	fileList = list;
}

reader::~reader() {}


void reader::read(vector<player*> &players, vector<course*> &courses, vector<dgRound*> &rounds) {
	string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	size_t f2;
	string courseStr, round, line, tempName;
	int par, col, val, row = 0;
	course* courseObj;
	player* playerObj;
	vector<pair<string, vector<int>>> res;
	for (int i = 0; i < (int)fileList.size(); i++) {
		size_t f1 = fileList.at(i).find_last_of("/\\");
		round = fileList.at(i).substr(f1 + 1);
		res.clear();
		for (int j = 0; j < 12; j++) {
			if (round.find(months[j]) != string::npos) {
				f2 = round.find(months[j]);
				break;
			}
		}
		courseStr = round.substr(0, f2);
		
		ifstream currFile("C:/Users/habsr/Documents/discGolfScores/" + round);

		if(!currFile.is_open()) {
			throw runtime_error("Can't Opener");
		}

		if(currFile.good()) {
			getline(currFile, line);
			stringstream ss(line);
			while (getline(ss, tempName, ',')) {
				size_t f3 = tempName.find("Hole");
				size_t f4 = tempName.find("Par");

				if ((f3 > 1000) && (f4 > 1000)) {
					if (!playerExists(tempName, players)) {
						player* newP = new player(tempName);
						players.push_back(newP);
					}
				}
				res.push_back({ tempName, vector<int> {} });
					
			}
		}
		while (getline(currFile, line)) {
			stringstream ss(line);
			col = 0;
			row++;
			while (ss >> val) {
				
				if (row == 19 && col == 0) {
					res.at(col).second.push_back(0);
				}
				else {
					res.at(col).second.push_back(val);
				}
				if (ss.peek() == ',') {
					ss.ignore();
				}
				col++;
			}
		}

		if (courseExists(courseStr, courses)) {
			courseObj = getCourse(courseStr, courses);
		}
		else {
			courseObj = new course(res.at(1).second, courseStr);
			courses.push_back(courseObj);
		}

		for (int j = 2; j < (int)res.size(); j++) {
			string name = res.at(j).first;
			int pIndex = findPlayer(name, players);
			playerObj = players[pIndex];
			playerObj->numRoundsPlus1();
			dgRound* newRound = new dgRound(courseObj, playerObj, res.at(j).second);
			rounds.push_back(newRound);
			
		}
			
	}

}

//checks if a player object already exists
bool reader::playerExists(string name, vector<player*> players) {
	for (int i = 0; i < (int)players.size(); i++) {
		if (players[i]->getName() == name) {
			return true;
		}
	}
	return false;
}

//returns the index of a specific player
int reader::findPlayer(string name, vector<player*> players) {
	for (int i = 0; i < (int)players.size(); i++) {
		if (players[i]->getName() == name) {
			return i;
		}
	}
	return -1;
}

//checks if a specific course object already exists
bool reader::courseExists(string name, vector<course*> courses) {
	for (int i = 0; i < (int)courses.size(); i++) {
		if (courses[i]->getName() == name) {
			return true;
		}
	}
	return false;
}

//return the index of a specific course object
course* reader::getCourse(string name, vector<course*> courses) {
	for (int i = 0; i < (int)courses.size(); i++) {
		if (courses[i]->getName() == name) {
			return courses[i];
		}
	}
}