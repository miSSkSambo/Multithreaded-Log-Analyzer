#include "LogAnalyzer.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>

std::mutex mtx;

void LogAnalyzer::processLines(const std::vector<std::string>& lines) {
    for (const auto& line : lines) {

        std::istringstream iss(line);
        std::string timestamp, level, ip, endpoint;

        iss >> timestamp >> level >> ip >> endpoint;

        std::lock_guard<std::mutex> lock(mtx);

        if (level == "ERROR")
            errorCount++;
        else if (level == "WARNING")
            warningCount++;
        else if (level == "INFO")
            infoCount++;

        ipCount[ip]++;
        endpointCount[endpoint]++;
    }
}

void LogAnalyzer::analyze(const std::string& filename, int threadCount) {

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file.\n";
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    if (lines.empty()) {
        std::cerr << "Log file is empty.\n";
        return;
    }

    int chunkSize = lines.size() / threadCount;
    std::vector<std::thread> threads;

    for (int i = 0; i < threadCount; ++i) {

        int start = i * chunkSize;
        int end = (i == threadCount - 1) ? lines.size() : start + chunkSize;

        std::vector<std::string> chunk(
            lines.begin() + start,
            lines.begin() + end
        );

        threads.emplace_back(
            &LogAnalyzer::processLines,
            this,
            chunk
        );
    }

    for (auto& t : threads) {
        t.join();
    }
}

void LogAnalyzer::printResults() const {

    std::cout << "\n=== Log Analysis Results ===\n";
    std::cout << "ERROR   : " << errorCount << "\n";
    std::cout << "WARNING : " << warningCount << "\n";
    std::cout << "INFO    : " << infoCount << "\n";

    std::string topIP;
    int maxCount = 0;

    for (const auto& pair : ipCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            topIP = pair.first;
        }
    }

    std::cout << "\nMost Frequent IP: "
              << topIP << " (" << maxCount << " times)\n";
}
