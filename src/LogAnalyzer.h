#ifndef LOG_ANALYZER_H
#define LOG_ANALYZER_H

#include <string>
#include <vector>
#include <unordered_map>

class LogAnalyzer {
private:
    std::unordered_map<std::string, int> ipCount;
    std::unordered_map<std::string, int> endpointCount;

    int errorCount = 0;
    int warningCount = 0;
    int infoCount = 0;

    void processLines(const std::vector<std::string>& lines);

public:
    void analyze(const std::string& filename, int threadCount);
    void printResults() const;
};

#endif
