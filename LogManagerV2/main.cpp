#include <iostream>

#include "src\smallUtils.h"
#include "src\logManager.h"

using namespace std;

int main() {
	
	logger::LogManager Logs = logger::LogManager::get(logger::DefualtLogs::Warning, logger::CustomLogs::CustomOn);

	Logs.LOGINFO("Info Log!!");
	Logs.LOGWARNING("Warning Log!!");
	Logs.LOGERROR("Error Log!!");
	Logs.LOGDEBUG("Debug Log!!");
	Logs.LOGCUSTOM("CUSTOM", "Custom Log!!");
	Logs.LOGCUSTOM("CUSTOM", "Custom Log!!", 0);


	cout << endl;
	system("PAUSE");
	return 0;
}
