#include <iostream>

#include "src\logManager.h"

int main() {
	
	logger::LogManager Logs = logger::LogManager::get(logger::DefualtLogs::Debug, logger::CustomLogs::CustomOn);

	Logs.LOGINFO("Info Log!!");
	Logs.LOGWARNING("Warning Log!!");
	Logs.LOGERROR("Error Log!!");
	Logs.LOGDEBUG("Debug Log!!");
	Logs.LOGCUSTOM("CUSTOM", "Custom Log!!");
	Logs.LOGCUSTOM("CUSTOM", "Custom Log!!", 0);

	std::cout << std::endl;
	system("PAUSE");
	return 0;
}
