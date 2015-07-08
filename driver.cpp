#include "loggertime.h"
#include "stringfunctions.h"

#include <iostream>

using namespace std;

int main() {
	LoggerTime lt2;

	lt2.setMilitary(true);
	lt2.setUTC(false);
	lt2.setDisplayDayName(true);

	cout << lt2 << endl;
}
