#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

struct TypeObject
{
    unsigned long long addr;
    size_t size;
    std::vector<long long> value_list;
};

int main()
{
    std::vector<TypeObject> obj_vec;
    TypeObject o1;
    o1.value_list.push_back(10);
    TypeObject o2;
    o2.value_list.push_back(20);
    o2.value_list.push_back(23333);
    o2.value_list.push_back(23);
    TypeObject o3;
    o3.value_list.push_back(31);
    o3.value_list.push_back(30);

    obj_vec.push_back(o1);
    obj_vec.push_back(o2);
    obj_vec.push_back(o3);
    std::cout << "addr of obj_vec: " << &obj_vec << std::endl;
    std::cout << "sizeof TypeObject: " << sizeof(TypeObject)
              << ", sizeof vector: " << sizeof(std::vector<long long>) << std::endl;
    int i = 0;
    for (auto& obj : obj_vec)
    {
        std::cout << "addr: " << &obj
                  << ", offset: " << (unsigned long long)&obj - (unsigned long long)&obj_vec[0]
                  << ", index: " << (unsigned long long)(&obj - &obj_vec[0]) / sizeof(TypeObject)
                  << ", index: " << (&obj - &obj_vec[0])
                  << std::endl;
        for (auto& i : obj.value_list)
        {
            std::cout << "|--> addr: " << &i << std::endl;
        }
        ++i;
    }
    return 0;
}
