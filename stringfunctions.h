#ifndef STRINGFUNCTIONS
#define STRINGFUNCTIONS

#include <string>
#include <ctime>

#include "loggertime.h"

/* Forward Declarations */
class LoggerTime;

struct TimeData {
	LoggerTime &lt;
	time_t *t;
	int YEAR;
	int MONTH;
	int DAY;
	int HOUR;
	int MIN;
	int SEC;
};

/*
* Notes:
*
* Functions with default values given must be given within the declaration, 
* not within the definition
*
* Always include .h files, not .cpp's.  Using .cpps will result in errors 
* about multiple definitions
*
* Anytime you're referencing a class or function which involves some kind of 
* circular inclusion, you must forward declare.
*/

/** API Documentation **/
// VARIABLES:
// 		numStringFormats = number of recognized legal formats; used for iteration purposes mostly
// 		legalFormats = recognized legal date formats
//
// FUNCTIONS:
//		getDayStr(int day, bool shortDay) = Return the string name of the day, shortDay will cause
//											it to return for days (Tue instead of Tuesday)
//		getMonthStr(int month, bool shortMonth) = Works similarly to getDayStr, returns month strings
//		checkDateFormat(string format) = Checks to see if a string is in a legal date format
//		checkLittleEndianFormat(string format) = Checks to see if the format string is little endian notation
//		checkMiddleEndianFormat(string format) = Checks to see if the format string is middle endian notatiton
//		checkBigEndianFormat(string format) = Checks to see if the format string is big endian notation

extern const int numStringFormats;
extern const std::string legalFormats[];

std::string getDayName(int day, bool shortDay = 0);
std::string getMonthName(int month, bool shortMonth = 0);
std::string getDateString(TimeData &td);
std::string getTimeString(TimeData &td);
std::string getDayString(TimeData &td);
std::string getMonthString(TimeData &td);
std::string getYearString(TimeData &td);
std::string getLittleEndianString(TimeData &td);
std::string getMiddleEndianString(TimeData &td);
std::string getBigEndianString(TimeData td);

bool checkDateFormat(std::string format);
bool checkBigEndianFormat(std::string format);		//YYYY MM DD
bool checkLittleEndianFormat(std::string format);	//DD MM YYYY
bool checkMiddleEndianFormat(std::string format);	//MM DD YYYY

#endif