#include <string>

std::string getDayStr(int day, bool shortDay = 0) {
	switch (day) {
		case 0:
			if (shortDay)
				return "Sunday";
			else
				return "Sun";
		case 1:
			if (shortDay) 
				return "Monday";
			else
				return "Mon";
		case 2:
			if (shortDay) 
				return "Tuesday";
			else
				return "Tue";
		case 3:
			if (shortDay) 
				return "Wednesday";
			else
				return "Wed";
		case 4:
			if (shortDay) 
				return "Thursday";
			else
				return "Thur";
		case 5:
			if (shortDay) 
				return "Friday";
			else
				return "Fri";
		case 6:
			if (shortDay) 
				return "Saturday";
			else
				return "Sat";
	}
}

std::string getMonthStr(int month, bool shortMonth = 0) {
	switch (month) {
		case 1:
			if (shortMonth)
				return "Jan";
			else
				return "January";
		case 2:
			if (shortMonth)
				return "Feb";
			else
				return "February";
		case 3:
			if (shortMonth)
				return "Mar";
			else
				return "March";
		case 4:
			if (shortMonth)
				return "Apr";
			else
				return "April";
		case 5:
			return "May";
		case 6:
			if (shortMonth)
				return "Jun";
			else
				return "June";
		case 7:
			if (shortMonth)
				return "Jul";
			else
				return "July";
		case 8:
			if (shortMonth)
				return "Aug";
			else
				return "August";
		case 9:
			if (shortMonth)
				return "Sep";
			else
				return "September";
		case 10:
			if (shortMonth)
				return "Oct";
			else
				return "October";
		case 11:
			if (shortMonth)
				return "Nov";
			else
				return "November";
		case 12:
			if (shortMonth)
				return "Dec";
			else
				return "December";
		default:
			return "ERROR";
	}
}
