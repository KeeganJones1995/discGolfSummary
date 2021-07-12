/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: dgEvent.h
 * Purpose: Header file for dgEvent object, holds parent object for dgRound and dgTotals, contain the the course and player associated with both of those objects
 */
#ifndef DGEVENT_H
#define DGEVENT_H

using namespace std;

#include <string>
#include <vector>
#include "course.h"
#include "player.h"

using std::string;

class dgEvent {
public:
	dgEvent(course*, player*);
	~dgEvent();
	course* getCourse();
	player* getPlayer();
	
private:
	course* c;
	player* p;

};

#endif // DGROUND_H