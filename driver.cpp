#include "loggertime.h"
#include "stringfunctions.h"

#include <iostream>

using namespace std;

int main() {
	LoggerTime lt;
	LoggerTime lt2;

	cout << lt << endl;
	cout << lt2 << endl;

	lt2.setMilitary(true);
	lt2.setUTC(true);

	cout << lt << endl;
	cout << lt2 << endl;
	
}
