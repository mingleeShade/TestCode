#include <string>
#include <fcntl.h>
#include <sys/file.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
using namespace std;


int lock_file(const std::string& file_path) {
    int flag = (O_RDONLY | O_CREAT);
    int mode = 0444;
    int fd = open(file_path.c_str(), flag, mode);
    if (fd < 0) {
        printf("open %s error,fd:%d\n", file_path.c_str(), fd);
        return 0;
    }
    int ret = flock(fd, LOCK_EX | LOCK_NB);
    if (ret < 0) {
        ::close(fd);
        printf("lock %s error,fd:%d\n", file_path.c_str(), fd);
        return 0;
    }
    return fd;
}

int main () {

    std::string prefix = "[lock_file2]";
    while (true) {
        std::cout << prefix << "try to lock file..."<< endl;
        if (lock_file("test.txt") == 0) {
            cout << prefix << "lock failed, skip..." << endl;
        } else {
            cout << prefix << "lock succees." << endl;
            break;
        }
        sleep(1);
    }
    cout << prefix << "exit..." << endl;
    return 0;
}
