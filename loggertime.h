#include <ctime>
#include <iostream>

class LoggerTime {
private: 
	time_t t;
	static bool UTC;
	static bool military;

	inline struct tm * getLocalTime(time_t *t) {
		return localtime(t);
	}
public:
	LoggerTime();
	
	inline bool getUTC() { return UTC; }
	inline bool getMilitary() { return military; }

	inline void setUTC(bool UTC) { this->UTC = UTC; }
	inline void setMilitary(bool military) { this->military = military; }

	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();

	friend std::ostream & operator << (std::ostream & out, const LoggerTime &time);
};
