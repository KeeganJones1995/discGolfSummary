/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: course.cpp
 * Purpose: Source file for Course object, standard constructor and getter/setters for the course objects
 */
#include "course.h"

course::course(vector<int> v, string s) {
	name = s;
	parTotal = sumPar(v);
	pars = v;
}

course::~course() {}

string course::getName() {
	return name;
}

int course::getParTotal() {
	return parTotal;
}

int course:: sumPar(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		sum = sum + v.at(i);
	}
	return sum;
}

vector<int> course::getPars() {
	return pars;
}