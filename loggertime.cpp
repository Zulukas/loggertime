#include "loggertime.h"

/* Set the Statics */

bool LoggerTime :: military = 		  	false;
bool LoggerTime :: UTC = 			  	false;

bool LoggerTime :: littleEndian = 		false;
bool LoggerTime :: useMonthName = 		false;
bool LoggerTime :: shortMonthName = 	false;
bool LoggerTime :: displayDayName = 	false;
bool LoggerTime :: shortDayName = 		false;

/* End Statics */
///////////////////////////////////////////////////////////////////////////////
/* Constructors */

LoggerTime :: LoggerTime() {
	t = time(0);
}

/* End Constructors */
///////////////////////////////////////////////////////////////////////////////
/* Setters & Getters */

int LoggerTime :: getYear() {
	return getLocalTime(&t)->tm_year + 1900;
}

int LoggerTime :: getMonth() {
	return getLocalTime(&t)->tm_mon + 1;
}

int LoggerTime :: getDay() {
	return getLocalTime(&t)->tm_mday;
}

int LoggerTime :: getHour() {
	return getLocalTime(&t)->tm_hour;
}

int LoggerTime :: getMinute() {
	return getLocalTime(&t)->tm_min;
}

int LoggerTime :: getSecond() {
	return getLocalTime(&t)->tm_sec;
}

/* End Setters & Getters */
///////////////////////////////////////////////////////////////////////////////
/* Overloaded Operators */

std::ostream & operator << (std::ostream & out, const LoggerTime &time) {
	struct tm *now = localtime(&time.t);

	
	
	return out;
}

/* End Overloaded Operators */
///////////////////////////////////////////////////////////////////////////////
