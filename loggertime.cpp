/*#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	time_t t = time(0);
	struct tm *now = localtime(&t);

	cout << now->tm_mon + 1 << "-" << now->tm_mday << "-" << now->tm_year + 1900 << endl;

}

*/

#include "loggertime.h"
#include "stringfunctions.cpp"

bool LoggerTime :: military = false;

LoggerTime :: LoggerTime() {
	t = time(0);
}

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

std::ostream & operator << (std::ostream & out, const LoggerTime &time) {
	struct tm *now = localtime(&time.t);
	out << now->tm_mon + 1 << "/" << now->tm_mday << "/" << now->tm_year + 1900 << ": ";

	if (time.military)
		out << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec;
	else {
		int hour = now->tm_hour;

		if (hour >= 12)
			out << hour - 12 << ":" << now->tm_min << ":" << now->tm_sec << "pm";
		else
			out << hour << ":" << now->tm_min << ":" << now->tm_sec << "am";
	}

	return out;
}

