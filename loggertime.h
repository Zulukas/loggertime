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
	static bool littleEndian;
	static bool useMonthName;
	static bool shortMonthName;
	static bool displayDayName;
	static bool shortDayName;

public:
	LoggerTime();
	
	//Military Time
	inline bool getMilitary() { return military; }
	inline void setMilitary(bool input) { this->military = input; }

	//UTC time
	inline bool getUTC() { return UTC; }
	inline void setUTC(bool input) { this->UTC = input; }

	inline bool getLittleEndian() { return littleEndian; }
	inline void setLittleEndian(bool input) { this->littleEndian = input; }

	inline bool getUseMonthName() { return useMonthName; }
	inline void setUseMonthName(bool input) { this->useMonthName = input; }

	inline bool getShortMonthName() { return shortMonthName; }
	inline void setShortMonthName(bool input) { this->shortMonthName = input; }

	inline bool getDisplayDayName() { return displayDayName; }
	inline void setDisplayDayName(bool input) { this->displayDayName = input; }

	inline bool getShortDayName() { return shortDayName; }
	inline void setShortDayName(bool input) { this->shortDayName = input; }

	inline time_t * getTime() { return &t; }

	inline struct tm * getLocalTime(time_t *t) {
		return localtime(t);
	}

	inline struct tm * getGMTime(time_t *t) {
		return gmtime(t);
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