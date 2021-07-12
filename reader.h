/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: reader.h
 * Purpose: Header file for Reader object, which has all the function that will iterate through and collect meaningful info from the csv files
 */
#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include "player.h"
#include "course.h"
#include "dgRound.h"

using namespace std;
using std::string;

class reader{
	public:
		reader(vector<string>);
		~reader();
		void read(vector<player*>&, vector<course*>&, vector<dgRound*>&);
		int findPlayer(string, vector<player*>);
		course* getCourse(string, vector<course*>);
	private:
		bool playerExists(string, vector<player*>);
		bool courseExists(string, vector<course*>);
		vector<string> fileList;

		
};

#endif // READER_H
