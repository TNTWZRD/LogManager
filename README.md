**LogManagerV2**
===============
Version 2.02, Updated 01-20-17.

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
```cpp
#include "src/logManager.h"
#include "src/fileManager.h" 
#include "src/smallUtils.h"
```

Create a LogManager Object:
```cpp
namespace logger {
	LogManager LOGS = LogManager::get(AllLogs::AllOn);
}
```

Or for more control:
```cpp
namespace logger {
	LogManager LOGS = LogManager::get(DefaultLogs::DefaultOn, CustomLogs::CustomOn);
}
```


All Variables:
-----------------

**AllLogs:**
```cpp
	AllLogs::AllOn <br>
	AllLogs::AllOff <br>
```
**DefaultLogs**
```cpp
DefaultLogs::DefaultOn;
DefaultLogs::Info;
DefaultLogs::Warning;
DefaultLogs::Error;
DefaultLogs::Debug;
DefaultLogs::DefaultOff;
```
NOTE: Enabling Debug enables everything below it, Error, Warning, Etc. This works for all of them.

**Custom**
```cpp
	CustomLogs::CustomOn;
	CustomLogs::CustomOff;
```
Logging
---------

To send a log use:
```cpp
LOGS.LOGINFO("Info Log Works");
LOGS.LOGWARNING("Warning Log Works");
LOGS.LOGERROR("Error Log Works");
LOGS.LOGDEBUG("Debug Log Works");
LOGS.LOGCUSTOM("CUSTOM_LOGGER_NAME", "Custom Logger Works");
```

If you would like to disable the timestamp use the following:
```cpp
LOGS.LOGINFO("Info Log Works", 0 );
LOGS.LOGWARNING("Warning Log Works", 0);
LOGS.LOGERROR("Error Log Works", 0);
LOGS.LOGDEBUG("Debug Log Works", 0);
LOGS.LOGCUSTOM("LOGGER_NAME", "Custom Logger Works", 0);
```

Other:
--------

**If you dont want to initailize a LogManager Variable you can use:**

```cpp
namespace logger{
	LogManager::get(AllLogs::AllOn).LOGINFO("No OBJ Log");
}
```

**NOTE:** When you initialize the first object, or use the above code, you will be unable to change what log types are going to be shown. They are set once and may not be changed until you close the application and change the code/setting.

------------------------

------------------------

> Code Written and maintained by Daniel Jajlairdo, and Corbin Matchull @ TheTechSphere <br>
> Copywrite 2017 Daniel Jajliardo @ TheTechSphere <br>
