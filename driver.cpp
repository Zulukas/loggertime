#include "loggertime.h"
#include "stringfunctions.cpp"

#include <iostream>

using namespace std;

int main() {
	LoggerTime lt;
	LoggerTime lt2;

	lt2.setMilitary(true);

	cout << lt << endl;
	cout << lt2 << endl;
	
}
