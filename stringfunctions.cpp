#include "stringfunctions.h"
#include <string>

/* String Function Global Constants */

const int numStringFormats = 6;
const std::string legalFormats[numStringFormats] = {
	"mm/dd/yyyy", //Middle-endian
	"dd/mm/yyyy", //Little-endian
	"yyyy/mm/dd", //Big-endian
	"mmddyyyy",
	"ddmmyyyy",
	"yyyymmdd"
};

/* End String Function Global Constants */
///////////////////////////////////////////////////////////////////////////////
/* Start string-returning functions */

std::string getDayName(int day, bool shortDay) {
	shortDay = !shortDay; //too lazy to correct the entire switch statement :)

	switch (day) {
		case 0:
			if (shortDay)
				return "Sunday";
			else
				return "Sun";
		case 1:
			if (shortDay) 
				return "Monday";
			else
				return "Mon";
		case 2:
			if (shortDay) 
				return "Tuesday";
			else
				return "Tue";
		case 3:
			if (shortDay) 
				return "Wednesday";
			else
				return "Wed";
		case 4:
			if (shortDay) 
				return "Thursday";
			else
				return "Thur";
		case 5:
			if (shortDay) 
				return "Friday";
			else
				return "Fri";
		case 6:
			if (shortDay) 
				return "Saturday";
			else
				return "Sat";
		default:
			return "ERROR";
	}
}

std::string getMonthName(int month, bool shortMonth) {
	switch (month) {
		case 1:
			if (shortMonth)
				return "Jan";
			else
				return "January";
		case 2:
			if (shortMonth)
				return "Feb";
			else
				return "February";
		case 3:
			if (shortMonth)
				return "Mar";
			else
				return "March";
		case 4:
			if (shortMonth)
				return "Apr";
			else
				return "April";
		case 5:
			return "May";
		case 6:
			if (shortMonth)
				return "Jun";
			else
				return "June";
		case 7:
			if (shortMonth)
				return "Jul";
			else
				return "July";
		case 8:
			if (shortMonth)
				return "Aug";
			else
				return "August";
		case 9:
			if (shortMonth)
				return "Sep";
			else
				return "September";
		case 10:
			if (shortMonth)
				return "Oct";
			else
				return "October";
		case 11:
			if (shortMonth)
				return "Nov";
			else
				return "November";
		case 12:
			if (shortMonth)
				return "Dec";
			else
				return "December";
		default:
			return "ERROR";
	}
}

std::string getDateString(TimeData &td) {
	std::string out;

	return out;
}

std::string getTimeString(TimeData &td) {
	std::string out = "";

	std::string DAY = std::to_string(td.DAY);

	if (td.lt.getShowDayString()) {


		out += getDayName(td.DAY) + " ";

		if (td.lt.getShowDayNumber()) {
			out += DAY + " ";
		}
	}

	return out;
}

std::string getDayString(TimeData &td) {
	std::string out;

	if (td.lt.getShowDayString() && !td.lt.getShortDate()) { //Day String
		out += getDayName(td.DAY, td.lt.getShortDayString()) + " ";
	}
	
	out += td.DAY;

	return out;
}


std::string getMonthString(TimeData &td) {
	std::string out;

	LoggerTime temp = td.lt;

	if (td.lt.getShowMonthString() && !td.lt.getShortDate()) { //Month String
		out += getMonthName(td.MONTH, td.lt.getShortMonthString());
	}
	else { 
		out += std::to_string(td.MONTH);
	}

	return out;
}

std::string getYearString(TimeData &td) {
	return std::to_string(td.YEAR);
}

/* DD MM YYYY */
std::string getLittleEndianString(TimeData &td) {
	std::string DAY = getDayString(td);
	std::string MONTH = getMonthString(td);
	std::string YEAR = getYearString(td);

	if (td.lt.getShortDate()) {
		return (DAY + "/" + MONTH + "/" + YEAR);
	}
	else {
		return (DAY + " of ");
	}
}

/* MM DD YYYY*/
std::string getMiddleEndianString(TimeData &td) {
	std::string out;

	return out;
}
 
/* YYYY DD MM */
std::string getBigEndianString(TimeData &td) {
	std::string out;

	return out;
}

/* End string-returning functions */
///////////////////////////////////////////////////////////////////////////////
/* Start bool-returning functions */

bool checkDateFormat(std::string format) {
	for (int i = 0; i < numStringFormats; i++) {
		if (legalFormats[i] == format)
			return true;
	}

	return false;
}

/*
* YYYYMMDD - Saudi Arabia and a few other countries
*/
bool checkBigEndianFormat(std::string format) {
	return ((legalFormats[2]) == format || (legalFormats[5]) == format);
}

/*
* DDMMYYYY - Most of the world
*/
bool checkLittleEndianFormat(std::string format) {
	return ((legalFormats[1]) == format || (legalFormats[4]) == format);
}

/*
* MMDDYYYY - Most of North America
*/
bool checkMiddleEndianFormat(std::string format) {
	return ((legalFormats[0]) == format || (legalFormats[3]) == format);
}





//TEST FUNCTIONS

//std::string getDayStr(int day, bool shortDay) { return ""; }
//std::string getMonthStr(int month, bool shortMonth) { return ""; }
//std::string getDateString(TimeData &td) { return ""; }
//std::string getTimeString(TimeData &td) { return ""; }
//std::string getDayString(TimeData &td) { return ""; }
//std::string getMonthString(TimeData &td) { return ""; }
//std::string getYearString(TimeData &td) { return ""; }
/*std::string getLittleEndianString(TimeData &td) { return ""; }
std::string getMiddleEndianString(TimeData &td) { return ""; }
std::string getBigEndianString(TimeData td) { return ""; }

bool checkDateFormat(std::string format) { return false; }
bool checkBigEndianFormat(std::string format) { return false; }		//YYYY MM DD
bool checkLittleEndianFormat(std::string format) { return false; }	//DD MM YYYY
bool checkMiddleEndianFormat(std::string format) { return false; }	//MM DD YYYY
*/