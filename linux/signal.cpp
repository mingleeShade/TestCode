#include <ctime>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <signal.h>
#include <unistd.h>
using namespace std;

bool running = true;

void signalHandler(int sig)
{
    running = false;
    std::cout << "sig: " << sig << endl;
}

int main()
{
    struct sigaction action;
    action.sa_flags = 0;
    action.sa_handler = signalHandler;   //信号处理函数
    sigaction(40, &action, nullptr);

    while (running) {
        std::cout << "Program running..." << endl;
        ::usleep(1000 * 1000);
    }
    std::cout << "Program stop." << endl;
    return 0;
}
