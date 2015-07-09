#include "loggertime.h"
#include "stringfunctions.h"

#include <iostream>

using namespace std;

int main() {
	LoggerTime lt2;

	lt2.setMilitary(false);
	lt2.setUTC(true);
	lt2.setDisplayDayName(true);
	lt2.setUseMonthName(true);
	lt2.setLittleEndian(true);
	lt2.setShortDayName(true);
	lt2.setShortMonthName(true);

	lt2.displayStatics();

	cout << lt2 << endl;
}
