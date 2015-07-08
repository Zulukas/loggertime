#include "stringfunctions.h"
#include <string>

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
	std::string DAY = std::to_string(td.DAY);
	std::string MONTH;
	std::string YEAR = std::to_string(td.YEAR);

	if (td.lt.getDisplayDayName()) {
		out += getDayName(td.t->tm_wday, td.lt.getShortDayName()) + " ";
	}

	if (td.lt.getUseMonthName()) {
		MONTH = getMonthName(td.MONTH, td.lt.getShortMonthName());
	}
	else {
		MONTH = std::to_string(td.MONTH);
	}

	if (td.lt.getLittleEndian()) {
		out = DAY + "-" + MONTH + "-" + YEAR;
	}
	else {
		out = MONTH + "-" + DAY + "-" + YEAR;
	}

	return out;
}

std::string getTimeString(TimeData &td) {
	std::string out = "";

	std::string HOUR;
	std::string MINUTE = std::to_string(td.MIN);
	std::string SECONDS = std::to_string(td.SEC);

	int iHour;

	if (td.lt.getUTC()) { 
		struct tm *t = td.lt.getGMTime(td.lt.getTime());
		iHour = (t->tm_hour);
	}
	else {
		iHour = (td.HOUR);
	}

	if (td.lt.getMilitary()) {
		HOUR = std::to_string(iHour);

		return HOUR + ":" + MINUTE + ":" + SECONDS;
	}

	bool PM = (iHour >= 12);
	HOUR = std::to_string((PM) ? (iHour - 12) : (iHour));

	return HOUR + ":" + MINUTE + ":" + SECONDS + (PM ? " pm" : " am");
}