#include <iostream>
#include <fstream>

inline void print_memory_usage()
{
    std::ifstream file("/proc/self/status");
    std::string line;

    while (std::getline(file, line))
    {
        if (line.substr(0, 5) == "VmRSS")
        {
            std::cout << "Memory Usage: " << line << std::endl;
            break;
        }
    }
}
