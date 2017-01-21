// Code Written and maintained by Daniel Jajliardo @ TheTechSphere
// Copywrite 2017 Daniel Jajliardo @ TheTechSphere
// This is a small utiliy file.
// Version 0.03 Updated 01/20/17 Daniel Jajliardo

#include <string>
#include <ctime>

#pragma once

namespace smallutils {

	static std::string intToString(int i) {
		char intStr[50];
		_itoa(i, intStr, 10);
		return std::string(intStr);
	}

	static std::string getDate() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		return intToString(now->tm_mon + 1) + '-' + intToString(now->tm_mday) + "-" + intToString(now->tm_year + 1900);
	}

	static std::string getTime() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		return intToString(now->tm_hour + 1) + '-' + intToString(now->tm_min);
	}

	static std::string getTimeWSec() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		return intToString(now->tm_hour + 1) + ':' + intToString(now->tm_min) + ':' + intToString(now->tm_sec);
	}

	static std::string getTimeStamp() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		return getDate() + "__" + getTimeWSec();;
	}
};