#ifndef LOGGERTIME
#define LOGGERTIME

#include <ctime>
#include <iostream>
#include <iomanip>

#include "stringfunctions.h"

class LoggerTime {
private: 
	time_t t;
	
	//time related statics
	static bool military; //00:00:00 - 23:59:59
	static bool UTC;

	//date related statics
	static bool shortDate; //Jan 1, 2015 --> 1/1/2015
	static bool useDashes;
	static bool useDots;
	static bool useSlashes;

	static bool showDayString; //Will be display the name of the day or just the number?
	static bool shortDayString;
	static bool showDayNumber; //Shows by default is day string is false
	
	static bool showMonthString;
	static bool shortMonthString;
	static bool showMonthNumber;

	static std::string format; //mm/dd/yyyy, dd/mm/yyyy, yyyy/mm/dd

	
public:
	LoggerTime();
	
	//Military Time
	inline bool getMilitary() { return military; }
	inline void setMilitary(bool military) { this->military = military; }

	//UTC time
	inline bool getUTC() { return UTC; }
	inline void setUTC(bool UTC) { this->UTC = UTC; }

	//Simple Date (ex.:mm/dd/yyyy)
	inline bool getShortDate() { return shortDate; }
	inline void setShortDate(bool shortDate) { this->shortDate = shortDate; }

	//Use dashes instead of slashes
	inline bool getUseDashes() { return useDashes; }
	
	//Use dots instead of slashes
	inline bool getUseDots() { return useDots; }

	//Use slashes
	inline bool getUseSlashes() { return useSlashes; }

	//Show the name of the day
	inline bool getShowDayString() { return showDayString; }
	inline void setShowDayString(bool showDayString) { this->showDayString = showDayString; }

	//Short day string format (Mon instead of Monday)
	inline bool getShortDayString() { return shortDayString; }
	inline bool setShortDayString(bool shortDayString) { 
		this->shortDayString = shortDayString; 
	}

	//Show the number of the day iff the name of the day is shown
	inline bool getShowDayNumber() { return showDayNumber; }
	inline void setShowDayNumber(bool showDayNumber) { 
		this->showDayNumber = showDayNumber; 
	}

	//Show the name of the month
	inline bool getShowMonthString() { return showMonthString; }
	inline void setShowMonthString(bool showMonthString) { 
		this->showMonthString = showMonthString; 
	}

	//Short month string format (Jan instead of January)
	inline bool getShortMonthString() { return shortMonthString; }
	inline void setShortMonthString(bool shortMonthString) { this->shortMonthString = shortMonthString; }

	//Show the number of month iff the name of the month is shown
	inline bool getShowMonthNumber() { return showMonthNumber; }
	inline bool setShowMonthNumber(bool showMonthNumber) { this->showMonthNumber = showMonthNumber; }

	inline std::string getDateFormat() { return format; }
	void setDateFormat(std::string format);

	inline struct tm * getLocalTime(time_t *t) {
		return localtime(t);
	}

	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();

	friend std::ostream & operator << (std::ostream & out, const LoggerTime &time);
};

#endif