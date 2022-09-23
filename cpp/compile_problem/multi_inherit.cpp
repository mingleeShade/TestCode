#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


int g_count = 0;
class Base {
public:
    Base() {
        m_id = g_count++;
        cout << "Base create. id: " << m_id << endl;
    }
    ~Base() {
        cout << "Base destroy. id: " << m_id << endl;
    }
protected:
    int m_id = 0;
};

class Type {
public:
    std::string operator[] (const std::string& str) {
        return "str";
    }
};

class Derive : public Base, public Type {
public:
    Derive() {
        m_sub_id = g_count++; 
        cout << "Derive create. id: " << m_sub_id << endl;
    }
    ~Derive() {
        cout << "Derive destroy. id: " << m_sub_id << endl;
    }

    string Test(const std::string& str) {
        return (*this)[str];
    }
protected:
    int m_sub_id = 0;
};

int main() {
    Derive d;
    cout << "Test: " << d.Test("str") << endl;
    return 0;
}
