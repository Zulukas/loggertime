#include <ctime>
#include <iostream>
#include <iomanip>

class LoggerTime {
private: 
	time_t t;
	static bool military;
	static bool UTC;
	static bool shortDate;
	static std::string format;

	inline struct tm * getLocalTime(time_t *t) {
		return localtime(t);
	}
public:
	LoggerTime();
	
	inline bool getMilitary() { return military; }
	inline void setMilitary(bool military) { this->military = military; }

	inline bool getUTC() { return UTC; }
	inline void setUTC(bool UTC) { this->UTC = UTC; }

	inline bool getShortDate() { return shortDate; }
	inline void getShortDate(bool shortDate) { this->shortDate = shortDate; }

	inline std::string getDateFormat() { return format; }
	void setDateFormat(std::string format);

	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();

	friend std::ostream & operator << (std::ostream & out, const LoggerTime &time);
};
