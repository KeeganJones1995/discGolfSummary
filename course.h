/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: course.h
 * Purpose: Header file for Course object, holds the information for each course like par and name
 */
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

using namespace std;

using std::string;

class course{
	public:
		course(vector<int>, string);
		~course();
		string getName();
		int getParTotal();
		vector<int> getPars();
	private:
		string name;
		int parTotal;
		vector<int> pars;
		int sumPar(vector<int>);
};

#endif // COURSE_H

