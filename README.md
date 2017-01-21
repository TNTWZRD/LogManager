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
> \#include "logManager.h" <br>
> \#include "fileManager.h" <br> 
> \#include "smallUtils.h" <br>

Create a LogManager Object:
> namespace logger{ <br>
> &emsp;&emsp;LogManager LOGS = LogManager::get(AllLogs::AllOn); <br>
> } <br>

Or for more control:
> namespace logger{ <br>
> &emsp;&emsp;LogManager LOGS = LogManager::get(DefualtLogs::DefualtOn, CustomLogs::CustomOn); <br>
> } <br>


All Varaiables:
-----------------

**AllLogs:**
>AllLogs::AllOn <br>
>AllLogs::AllOff <br>

**DefualtLogs**
>DefualtLogs::DefualtOn <br>
>DefualtLogs::Info <br>
>DefualtLogs::Warning <br>
>DefualtLogs::Error <br>
>DefualtLogs::Debug <br>
>DefualtLogs::DefualtOff <br>

    NOTE: Enabling Debug enables everything below it, Error, Warning, Etc. This works for all of them.

**Custom**
>CustomLogs::CustomOn <br>
>CustomLogs::CustomOff <br>

Logging
---------

To send a log use:
>LOGS.LOGINFO("Info Log Works"); <br>
>LOGS.LOGWARNING("Warning Log Works"); <br>
>LOGS.LOGERROR("Error Log Works"); <br>
>LOGS.LOGDEBUG("Debug Log Works"); <br>
>LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works"); <br>

If you would like to disable the timestamp use the following:
>LOGS.LOGINFO("Info Log Works", 0 ); <br>
>LOGS.LOGWARNING("Warning Log Works", 0); <br>
>LOGS.LOGERROR("Error Log Works", 0); <br>
>LOGS.LOGDEBUG("Debug Log Works", 0); <br>
>LOGS.LOGCUSTOM("LOGGER_NAME", "Custom Logger Works", 0); <br>

Other:
--------

**If you dont want to initailize a LogManager Variable you can use:**

> namespace logger{ <br>
> &emsp;&emsp;LogManager::get(AllLogs::AllOn).LOGINFO("No OBJ Log"); <br>
> } <br>

**NOTE:** When you initialize the first object, or use the above code, you will be unable to change what log types are going to be shown. They are set once and may not be changed until you close the application and change the code/setting.

------------------------

------------------------

> Code Written and maintained by Daniel Jajliardo @ TheTechSphere <br>
> Copywrite 2017 Daniel Jajliardo @ TheTechSphere <br>
