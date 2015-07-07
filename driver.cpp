#include "loggertime.h"
#include "stringfunctions.h"

#include <iostream>

using namespace std;

int main() {
	LoggerTime lt2;

	lt2.setMilitary(false);
	lt2.setUTC(false);
	lt2.setShortDate(false);
	lt2.setDateFormat("ddmmyyyy");

	cout << lt2 << endl;
}
