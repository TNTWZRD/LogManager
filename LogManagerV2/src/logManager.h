// Code Written and maintained by Daniel Jajliardo & Corbin Matchull @ TheTechSphere
// Copywrite 2017 TheTechSphere
// Version 2.04 Updated 01/20/17 Daniel Jajliardo
// Please See README.md for how to use

#include <string>
#include <iostream>
#include "fileManager.h"
#include "smallUtils.h"

#pragma once

namespace logger {

	enum AllLogs { AllOn, AllOff };
	enum DefualtLogs { DefualtOn = 1, Info = 2, Warning = 3, Error = 4, Debug = 5, DefualtOff = 0 };
	enum CustomLogs { CustomOn, CustomOff };

	class LogManager {
	public:
		// FileManager Variables:
		const std::string fileLoc = "logs/";
		static const bool useDate = true;
		std::string LogName;

	private:
		// Log Manager Variables:
		DefualtLogs LogLevel = DefualtOff;
		CustomLogs  CustomEnabled = CustomOn;

		void LogManager::SendLog(std::string loggerName, std::string loggerString, bool timestamp, bool actualOutput = true) {
			if (actualOutput) {
				if (timestamp)
					std::cout << "[" << smallutils::getTimeStamp() << "][" << loggerName << "]: " << loggerString << std::endl;
				else
					std::cout << "[" << loggerName << "]: " << loggerString << std::endl;
			}
			fmanager::FileManager fman;
			fman.appendFile(LogName, "[" + smallutils::getTimeStamp() + "][" + loggerName + "]: " + loggerString);
		}

		// Constructor
		LogManager::LogManager(DefualtLogs logLevel, CustomLogs customEnabled) {
			if (logLevel == DefualtOn)
				LogLevel = Debug;
			else
				LogLevel = logLevel;
			CustomEnabled = customEnabled;
			fmanager::FileManager fman;
			if (useDate)
				LogName = fileLoc + smallutils::getDate() + "__" + string(smallutils::getTime()) + ".log";
			else
				LogName = "LogFile.log";
			fman.writeFile(LogName, " --- Log File Initialized --- \n");
		}

	public:
		// Singleton Code
		static LogManager& LogManager::get(AllLogs allLogs) {
			if (allLogs == AllLogs::AllOn)
				return get(DefualtLogs::DefualtOn, CustomLogs::CustomOn);
			else
				return get(DefualtLogs::DefualtOff, CustomLogs::CustomOff);
		}

		static LogManager& LogManager::get(DefualtLogs defaultLogs, CustomLogs customLogs) {
			static LogManager Instance(defaultLogs, customLogs);
			return Instance;
		}
		// End Singleton Code

		void LogManager::LOGINFO(std::string loggerString, bool timestamp = true) {
			if (LogLevel >= Info)
				SendLog("INFO", loggerString, timestamp);
			else
				SendLog("INFO", loggerString, timestamp, 0);
		}

		void LogManager::LOGWARNING(std::string loggerString, bool timestamp = true) {
			if (LogLevel >= Warning)
				SendLog("WARNING", loggerString, timestamp);
			else
				SendLog("WARNING", loggerString, timestamp, 0);
		}

		void LogManager::LOGERROR(std::string loggerString, bool timestamp = true) {
			if (LogLevel >= Error)
				SendLog("ERROR", loggerString, timestamp);
			else
				SendLog("ERROR", loggerString, timestamp, 0);
		}

		void LogManager::LOGDEBUG(std::string loggerString, bool timestamp = true) {
			if (LogLevel >= Debug)
				SendLog("DEBUG", loggerString, timestamp);
			else
				SendLog("DEBUG", loggerString, timestamp, 0);
		}

		void LogManager::LOGCUSTOM(std::string loggerName, std::string loggerString, bool timestamp = true) {
			if (CustomEnabled == CustomOn)
				SendLog(loggerName, loggerString, timestamp);
			else
				SendLog(loggerName, loggerString, timestamp, 0);
		}
	};
}