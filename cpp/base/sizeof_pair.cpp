#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

typedef std::pair<unsigned int, unsigned char*> CmdPair;
typedef std::pair<volatile bool, CmdPair> ItemPair;

int main()
{
    cout << endl << sizeof(ItemPair) << endl;
    cout << sizeof(CmdPair) << endl;
    return 0;
}
