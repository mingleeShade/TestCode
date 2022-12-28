#include <fstream>
#include <ostream>


int main() {
    std::ofstream ofs("test.txt", std::ofstream::out);

    for (int i = 0; i < 10000; ++i) {
        ofs << "123.............................................." << std::endl;
    }
    ofs << std::flush;
}
