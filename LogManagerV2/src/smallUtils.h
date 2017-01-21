// Code Written and maintained by Daniel Jajliardo @ TheTechSphere
// Copywrite 2017 Daniel Jajliardo @ TheTechSphere
// This is a small utiliy file.
// Version 0.04 Updated 01/20/17 Daniel Jajliardo

#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

#pragma once

namespace smallutils {

	static std::string intToString(int i) {
		char intStr[50];
		_itoa(i, intStr, 10);
		return std::string(intStr);
	}

	static std::string replaceInString(std::string in, char del, char rep) {
		std::replace(in.begin(), in.end(), del, rep);
		return in;
	}

	// New ISO Standard Date/Time Formats
	static std::string getISODate() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		std::string Year, Mon, mDay;

		Year = intToString(now->tm_year + 1900);
		
		if (now->tm_mon + 1 <= 9)
			Mon = "0" + intToString(now->tm_mon + 1);
		else
			Mon = intToString(now->tm_mon + 1);

		if (now->tm_mday <= 9)
			mDay = "0" + intToString(now->tm_mday);
		else
			mDay = intToString(now->tm_mday);

		return std::string(Year + '-' + Mon + "-" + mDay);
	}

	static std::string getISOTime() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		std::string Hour, Min, Sec;

		if(now->tm_hour+1 <= 9)
			Hour = "0" + intToString(now->tm_hour + 1);
		else
			Hour = intToString(now->tm_hour + 1);

		if (now->tm_min <= 9)
			Min = "0" + intToString(now->tm_min);
		else
			Min = intToString(now->tm_min);

		if (now->tm_sec <= 9)
			Sec = "0" + intToString(now->tm_sec);
		else
			Sec = intToString(now->tm_sec);

		return std::string(Hour + ':' + Min + ":" + Sec + "Z");
	}

	static std::string getISOTimeStamp() {
		return getISODate() + "T" + getISOTime();
	}

};