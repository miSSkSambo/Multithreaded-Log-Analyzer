# 🚀 Multithreaded Log Analyzer (High-Performance C++ Edition)

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Build](https://img.shields.io/badge/Build-g%2B%2B-success)
![Platform](https://img.shields.io/badge/Platform-Ubuntu%2022.04-orange)
![Concurrency](https://img.shields.io/badge/Concurrency-std::thread-purple)
![License](https://img.shields.io/badge/License-MIT-brightgreen)
![Status](https://img.shields.io/badge/Project-Internship%20Ready-success)

A high-performance, multithreaded log analysis engine built in modern C++ using `std::thread` and `std::mutex` for concurrent processing.

Designed to demonstrate systems programming fundamentals, concurrency control, and performance optimization on Linux environments.

---

# 📑 Table of Contents

- [Executive Summary](#-executive-summary)
- [Technology Stack](#-technology-stack)
- [Architecture Overview](#-architecture-overview)
- [Concurrency Model](#-concurrency-model)
- [Installation](#-installation)
- [Build Instructions](#-build-instructions)
- [Usage Guide](#-usage-guide)
- [Performance Measurement](#-performance-measurement)
- [Screenshots](#-screenshots)
- [Future Enhancements](#-future-enhancements)
- [License](#-license)

---

# 📖 Executive Summary

This project demonstrates:

- Multithreaded file processing
- Safe shared-memory synchronization
- Log parsing and data aggregation
- Performance benchmarking using `<chrono>`
- Clean multi-file C++ architecture
- Linux compilation with `g++` and POSIX threading

The application processes large `.log` files and extracts:

- ERROR count
- WARNING count
- INFO count
- Most frequent IP address
- Most frequent endpoint
- Execution time benchmarking

---

# 🧰 Technology Stack

| Technology | Purpose |
|------------|----------|
| C++17 | Core programming language |
| STL (Standard Template Library) | Data structures & utilities |
| `std::thread` | Multithreading |
| `std::mutex` | Thread synchronization |
| `std::unordered_map` | High-performance hashing |
| `std::chrono` | Performance measurement |
| File I/O (`fstream`) | Log file processing |
| Ubuntu 22.04 | Development environment |
| g++ | Compilation |

---

# 🏗 Architecture Overview

```
Multithreaded-Log-Analyzer/
│
├── src/
│   ├── main.cpp               # Entry point
│   └── LogAnalyzer.cpp        # Core logic implementation
│
├── include/
│   └── LogAnalyzer.h          # Class declarations
│
├── sample.log                 # Example log file
│
├── build/                     # Compiled binaries (ignored)
├── .gitignore
└── README.md
```

---

# ⚙️ Concurrency Model

The application uses:

- Thread partitioning (work chunking)
- Mutex-protected shared counters
- Lock guards for exception-safe synchronization
- Thread joining to ensure completion

### Execution Flow

1. Read entire log file into memory
2. Divide lines into equal chunks
3. Spawn multiple threads
4. Each thread:
   - Parses log entries
   - Updates shared counters safely
5. Join all threads
6. Output results + execution time

---

# 💻 Installation

```bash
git clone https://github.com/yourusername/Multithreaded-Log-Analyzer.git
cd Multithreaded-Log-Analyzer
```

---

# 🛠 Build Instructions

Compile using:

```bash
g++ src/*.cpp -Iinclude -pthread -o loganalyzer
```

Explanation:

- `-Iinclude` → Include header files
- `-pthread` → Enable multithreading support
- `-o loganalyzer` → Output executable

---

# 🚀 Usage Guide

Run:

```bash
./loganalyzer
```

Default configuration:
- Processes `sample.log`
- Uses 4 threads

---

# ⏱ Performance Measurement

Execution time is measured using:

```cpp
std::chrono::high_resolution_clock
```

Example output:

```
=== Log Analysis ===
ERROR: 3
WARNING: 1
INFO: 2
Most Frequent IP: 192.168.1.1 (3 times)
Execution Time: 0.00021 seconds
```

---

# 📊 Sample Log Format

```
2026-03-01 ERROR 192.168.1.1 /login
2026-03-01 INFO 192.168.1.2 /home
2026-03-01 WARNING 192.168.1.1 /dashboard
```

Format:
```
[TIMESTAMP] [LEVEL] [IP] [ENDPOINT]
```

---

# 🔬 Key Engineering Concepts Demonstrated

- Thread lifecycle management
- Race condition prevention
- Hash-based frequency counting
- Workload partitioning
- Time complexity awareness
- Systems-level thinking
- Linux-based development

---

# 📈 Future Enhancements

- Command-line argument support
- Top 5 IP ranking
- Endpoint analytics
- Single-thread vs multi-thread benchmarking mode
- Memory optimization (reduce lock contention)
- CMake integration
- Unit testing framework
- CI/CD integration
- Docker containerization

---

# 👨‍💻 Author

Katlego

---

# 📜 License

MIT License
