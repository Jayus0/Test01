#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class print
{
public:
    void operator() (const T& elem)
    {
        cout<<elem<<", ";
    }
};

void test01()
{
    int ia[6] = {0, 1, 2, 3, 4, 5};
    vector<int> iv (ia, ia + 6);

    //print<int>() 是一个临时对象，不是一个函数调用操作
    for_each(iv.begin(), iv.end(), print<int>());
}


int main() {
    test01();
    return 0;
}
