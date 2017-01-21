Code Written and maintained by Daniel Jajliardo @ TheTechSphere

Copywrite 2017 Daniel Jajliardo @ TheTechSphere

Version 2.0 Updated 01/20/17 Daniel Jajliardo

\#include "logManager.h" In file where you would like to use logs

logger::LogManager LOGS = logger::LogManager::get(logger::DefualtLogs::DefualtOn, logger::CustomLogs::CustomOn); initialize a LOGS logManager Object

logger::LogManager LOGS = logger::LogManager::get(logger::AllLogs::AllOn); You can also initalize like this for convinance


LogManager(AllLogs);

LogManager(DefualtLogs, CustomLogs);



#All Varaiables: 

AllLogs::AllOn

AllLogs::AllOff

DefualtLogs::DefualtOn

DefualtLogs::Info

DefualtLogs::Warning

DefualtLogs::Error

DefualtLogs::Debug

DefualtLogs::DefualtOff

CustomLogs::CustomOn

CustomLogs::CustomOff



#And use one of  the following to write to the console, and just change above setting in initalizer to change what logs are viewed

LOGS.LOGINFO("Info Log Works");

LOGS.LOGWARNING("Warning Log Works");

LOGS.LOGERROR("Error Log Works");

LOGS.LOGDEBUG("Debug Log Works");

LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works");



#If you would like the timestamps to be invisible in the console add and extra option of '0' to the end of the command:

LOGS.LOGINFO("Info Log Works!"); <-- No timestamp (DEFUALT)

LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works"); <-- No Timestap as well (DEFUALT)

LOGS.LOGINFO("Info Log Works!", 0); <-- No timestamp (DEFUALT)

LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works", 0); <-- No Timestap as well (DEFUALT)

LOGS.LOGINFO("Info Log Works!", 1); <-- Timestamp Visible in console

LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works", 1); <-- Timestamp Visible in console



#if you dont want to initailize a LogManager Variable you can use:

SIDENOTE!!! --- after the first time youset the logger Type values, it will not be nessisary again

logger::LogManager::get(logger::AllLogs::AllOn).LOGCUSTOM("Special", "Specal Log");
