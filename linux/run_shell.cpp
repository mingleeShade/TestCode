#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;
int main (int argc, char* argv[])
{
    pid_t pid = fork();
    if (pid < 0)
    {
        cout << "create sub process failed." << endl;
        return 1;
    }
    if (pid == 0)
    {
        // 子进程
        cout << "there is sub process." << endl;
        // 启动其他进程
        execl("./test_server", "test_server");

        cout << "this code never be executed in sub process." << endl;
    }
    else
    {
        // 父进程
        while (true)
        {
            cout << "run_shell running..." << endl;
            sleep(5);
        }
    }
    return 0;
}
