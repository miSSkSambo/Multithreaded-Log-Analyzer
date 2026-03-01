#include "LogAnalyzer.h"
#include <iostream>
#include <chrono>

int main() {

    LogAnalyzer analyzer;

    auto start = std::chrono::high_resolution_clock::now();

    analyzer.analyze("sample.log", 4);

    auto end = std::chrono::high_resolution_clock::now();

    analyzer.printResults();

    std::chrono::duration<double> duration = end - start;

    std::cout << "\nExecution Time: "
              << duration.count()
              << " seconds\n";

    return 0;
}
