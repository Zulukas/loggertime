#include "loggertime.h"

/* Set the Statics */

bool LoggerTime :: military = false;
bool LoggerTime :: UTC = false;
bool LoggerTime :: shortDate = true;
bool LoggerTime :: useSlashes = true;
bool LoggerTime :: useDashes = false;
bool LoggerTime :: useDots = false;
bool LoggerTime :: showDayString = false;
bool LoggerTime :: shortDayString = false;
bool LoggerTime :: showDayNumber = false;
std::string LoggerTime :: format = "mm/dd/yyyy";

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

void LoggerTime :: setDateFormat(std::string format) {
	if (checkDateFormat(format)) {
		this->format = format;
	}
}

/* End Setters & Getters */
///////////////////////////////////////////////////////////////////////////////
/* Overloaded Operators */

std::ostream & operator << (std::ostream & out, const LoggerTime &time) {
	/*struct tm *now = localtime(&time.t);

	if (time.UTC) {
		now = gmtime(&time.t);
	}

	std::string DAY = getDayStr(now->tm_mday, time.shortDate);
	std::string MONTH = getMonthStr(now->tm_mon + 1, time.shortDate);
	int YEAR = now->tm_year + 1900;
	int HOUR = now->tm_hour;
	int MIN = now->tm_min;
	int SEC = now->tm_sec;

	if (checkMiddleEndianFormat(time.format)) //MMDDYYYY
		out << MONTH << "/" << DAY << "/" << YEAR << ": ";
	else if (checkLittleEndianFormat(time.format)) //DDMMYYYY
		out << DAY << "/" << MONTH << "/" << YEAR << ": ";
	else if (checkBigEndianFormat(time.format)) //YYYYMMDD
		out << YEAR << "/" << MONTH << "/" << DAY << ": ";

	if (time.military)
		out << HOUR << ":" << std::setfill('0') << std::setw(2) 
			<< MIN << ":" << std::setfill('0') << std::setw(2) 
			<< SEC;
	else {
		if (HOUR >= 12)
			out << HOUR - 12 << ":" << std::setfill('0') << std::setw(2) 
				<< MIN << ":" << std::setfill('0') << std::setw(2) 
				<< SEC << "pm";
		else
			out << HOUR << ":" << MIN << ":" << SEC << "am";
	}
	*/
	return out;
}

/* End Overloaded Operators */
///////////////////////////////////////////////////////////////////////////////
