#include "loggertime.h"
#include "stringfunctions.h"

#include <iostream>

using namespace std;

int main() {
	LoggerTime lt2;

	lt2.setMilitary(false);
	lt2.setUTC(false);

	cout << lt2 << endl;
}
