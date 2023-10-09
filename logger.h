#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance; // This ensures only one instance is created
        return instance;
    }

    void log(const std::string& message) {
        std::ofstream logFile(logFileName, std::ios_base::app);
        if (logFile.is_open()) {
            // Get the current date and time
            time_t now = time(0);
            tm* localTime = localtime(&now);

            // Format the timestamp
            char timestamp[100];
            strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S] ", localTime);

            // Write the log message with a timestamp
            logFile << timestamp << message << std::endl;
            logFile.close();
        }
    }

private:
    Logger() {
        logFileName = "application_log.txt"; // Change this to your desired log file name
    }

    Logger(const Logger&) = delete; // Prevent copying
    Logger& operator=(const Logger&) = delete; // Prevent assignment

    std::string logFileName;
};
