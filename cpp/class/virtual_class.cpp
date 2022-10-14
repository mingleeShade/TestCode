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
    virtual void virtual_interface() = 0;
protected:
    int m_id = 0;
};

class Derive : public Base {
public:
    Derive() {
        m_sub_id = g_count++; 
        cout << "Derive create. id: " << m_sub_id << endl;
    }
    ~Derive() {
        cout << "Derive destroy. id: " << m_sub_id << endl;
    }

    void virtual_interface() override
    {
    }
protected:
    int m_sub_id = 0;
};

int main()
{
    Derive d;
    return 0;
}
