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
        return fd;
    }
    return fd;
}

int main() {
    std::string prefix = "[lock_file1] ";
    std::cout << prefix << "try to lock file..." << std::endl;
    int fd = lock_file("test.txt");
    int seconds = 10;
    std::cout << prefix << "start to sleep " << seconds << " second" << std::endl;
    for (int i = 0; i < seconds; ++i) {
        std::cout << prefix << "sleep countdown " << seconds - i
            << " ..." << std::endl;
        sleep(1);
    }
    std::cout << prefix << "exit..." << endl;

    return 0;
}
