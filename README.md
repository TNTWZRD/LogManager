**LogManagerV2**
===============
Version 2.01, Updated 01-20-17.

**Functionality:**

- This project is currently running using a singleton class so it may only be initialized once. 

- The logs by default include a timestamp, this may be disabled when you log something.

- The logs are sent to a log file with the date, time, log name, and message. These logs are immune to when you change what logs are visible, they are always sent to this file if not the console.

- The logs are easy to turn on and off, and easy to manage what logs are visible in the console, as well as if they have a timestamp there or not.


---------------------

Usage:
--------
 **NOTE:** See provided main.cpp for example usage.

 Include *logManager.h*, as well as *simpleUtils.h*, and *fileManager.h*.
> \#include "logManager.h" 
> \#include "fileManager.h" 
> \#include "smallUtils.h"

Create a LogManager Object:
> namespace logger{
> &emsp;&emsp;LogManager LOGS = LogManager::get(AllLogs::AllOn);
> }

Or for more control:
> namespace logger{
> &emsp;&emsp;LogManager LOGS = LogManager::get(DefualtLogs::DefualtOn, CustomLogs::CustomOn);
> }


All Varaiables:
-----------------

**AllLogs:**
>AllLogs::AllOn
>AllLogs::AllOff

**DefualtLogs**
>DefualtLogs::DefualtOn
>DefualtLogs::Info
>DefualtLogs::Warning
>DefualtLogs::Error
>DefualtLogs::Debug
>DefualtLogs::DefualtOff

    NOTE: Enabling Debug enables everything below it, Error, Warning, Etc. This works for all of them.

**Custom**
>CustomLogs::CustomOn
>CustomLogs::CustomOff

Logging
---------

To send a log use:
>LOGS.LOGINFO("Info Log Works");
>LOGS.LOGWARNING("Warning Log Works");
>LOGS.LOGERROR("Error Log Works");
>LOGS.LOGDEBUG("Debug Log Works");
>LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works");

If you would like to disable the timestamp use the following:
>LOGS.LOGINFO("Info Log Works", 0 );
>LOGS.LOGWARNING("Warning Log Works", 0);
>LOGS.LOGERROR("Error Log Works", 0);
>LOGS.LOGDEBUG("Debug Log Works", 0);
>LOGS.LOGCUSTOM("LOGGER_NAME", "Custom Logger Works", 0);

Other:
--------

**If you dont want to initailize a LogManager Variable you can use:**

> namespace logger{
> &emsp;&emsp;LogManager::get(AllLogs::AllOn).LOGINFO("No OBJ Log");
> }

**NOTE:** When you initialize the first object, or use the above code, you will be unable to change what log types are going to be shown. They are set once and may not be changed until you close the application and change the code/setting.

------------------------

------------------------

> Code Written and maintained by Daniel Jajliardo @ TheTechSphere
> Copywrite 2017 Daniel Jajliardo @ TheTechSphere