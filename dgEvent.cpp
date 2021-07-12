/*Disc Golf Score Summary
 * Made By: Keegan Jones
 * File: dgEvent.cpp
 * Purpose: Source file for dgEvent object, standard constructor and getter for the dgEvent objects
 */
#include "dgEvent.h"
dgEvent::dgEvent(course* newC, player* newP) {
	c = newC;
	p = newP;
}

dgEvent::~dgEvent() {
}

course* dgEvent::getCourse() {
	return c;
}

player* dgEvent::getPlayer() {
	return p;
}
