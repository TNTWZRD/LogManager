// Code Written and maintained by Daniel Jajliardo @ TheTechSphere
// Copywrite 2017 Daniel Jajliardo @ TheTechSphere
// This code is used to manage logs on a big C++ Project.
// Version 5.0 Updated 01/20/17 Daniel Jajliardo
// This Version includes code to make it a singleton Class, 
// so there is never more than one instance of it

// Usage 
// #include "logManager.h" // In file where you would like to use logs
// logger::LogManager LOGS = logger::LogManager::get(logger::DefualtLogs::DefualtOn, logger::CustomLogs::CustomOn); // initialize a LOGS logManager Object
// logger::LogManager LOGS = logger::LogManager::get(logger::AllLogs::AllOn); // You can also initalize like this for convinance
//
// LogManager(AllLogs);
// LogManager(DefualtLogs, CustomLogs);
//
// All Varaiables: 
// AllLogs::AllOn
// AllLogs::AllOff
// 
// DefualtLogs::DefualtOn
// DefualtLogs::Info
// DefualtLogs::Warning
// DefualtLogs::Error
// DefualtLogs::Debug
// DefualtLogs::DefualtOff
//
// CustomLogs::CustomOn
// CustomLogs::CustomOff
//
// And use one of  the following to write to the console, and just change above setting in initalizer to change what logs are viewed
// LOGS.LOGINFO("Info Log Works");
// LOGS.LOGWARNING("Warning Log Works");
// LOGS.LOGERROR("Error Log Works");
// LOGS.LOGDEBUG("Debug Log Works");
// LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works");
//
// If you would like the timestamps to be invisible in the console add and extra option of '0' to the end of the command:
// LOGS.LOGINFO("Info Log Works!"); <-- No timestamp (DEFUALT)
// LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works"); <-- No Timestap as well (DEFUALT)
// LOGS.LOGINFO("Info Log Works!", 0); <-- No timestamp (DEFUALT)
// LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works", 0); <-- No Timestap as well (DEFUALT)
// LOGS.LOGINFO("Info Log Works!", 1); <-- Timestamp Visible in console
// LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works", 1); <-- Timestamp Visible in console
//
// if you dont want to initailize a LogManager Variable you can use:
// SIDENOTE!!! --- after the first time youset the logger Type values, it will not be nessisary again
// logger::LogManager::get(logger::AllLogs::AllOn).LOGCUSTOM("Special", "Specal Log");

#include <string>
#include <iostream>
#include "fileManager.h"
#include "smallUtils.h"

#pragma once

namespace logger {

	enum AllLogs { 
		AllOn, 
		AllOff 
	};
	enum DefualtLogs { 
		DefualtOn = 1, 
		Info = 2, 
		Warning = 3, 
		Error = 4, 
		Debug = 5, 
		DefualtOff = 0 
	};
	enum CustomLogs { 
		CustomOn, 
		CustomOff 
	};

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
			if (allLogs == AllLogs::AllOn) {
				return get(DefualtLogs::DefualtOn, CustomLogs::CustomOn);
			}
			else {
				return get(DefualtLogs::DefualtOff, CustomLogs::CustomOff);
			}
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