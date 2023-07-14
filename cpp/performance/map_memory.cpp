#include <iostream>
#include <map>
#include <fstream>
#include <string>

void print_memory_usage()
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

int main()
{
    std::map<unsigned long long, unsigned int> m;

    for (int i = 0; i < 38 * 1000 * 1000; ++i )
    {
        m[i] = i + 1;
    }

    print_memory_usage();
}
