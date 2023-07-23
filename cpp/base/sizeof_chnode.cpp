#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

using DWORD = unsigned int;
using QWORD = unsigned long;
using WORD = unsigned short;

struct MachineData
{
    DWORD dwVirCount = 0;//多少个虚拟节点
    QWORD qwMachineID = 0;
    std::string strIP = "";
    WORD wPort = 0;
};

//虚拟节点
typedef class ConsistentHashNode
{
public:

    //主机IP，此主机的第几个虚节点序号
    ConsistentHashNode(const MachineData& xData, DWORD dwVirIdx)
        : m_nodeData(xData), m_dwVirtualIndex(dwVirIdx) { }

    ConsistentHashNode() : m_dwVirtualIndex(0) { }
    std::string ToStr() const;
    QWORD GetMachineID() const;
    std::string GetIP() const;
    WORD GetPort() const;

private:
    MachineData m_nodeData;//主机IP,主机在主机列表中的索引
    DWORD       m_dwVirtualIndex;//虚拟节点序号
} CHNode;

int main()
{
    std::cout << "sizeof:" << sizeof(CHNode) << endl;
    std::cout << "sizeof string: " << sizeof(string) << endl;
    std::string ss = "sssssssssssssss0000";
    std::cout << "sizeof ss: " << sizeof(ss) << endl;
    return 0;
}
