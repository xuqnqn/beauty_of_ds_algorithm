/*************************************************************************
      > File Name: day1_2_fixed_ordered_array.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Sun 14 Jul 2019 06:46:07 PM CST
 ************************************************************************/

#include <iostream>
#include "Fixed_Ordered_Array.h"
using namespace std;


int main(int argc, char **argv, char **env)
{
#if 0 
    Fixed_Ordered_Array<int> a(5);

    a.push_back(1);
    a.push_back(4);
    a.push_back(2);
    a.erase(4);
    a.erase(1);
    a.push_back(8);
    a.push_back(1);
    a.push_back(10);
    a.erase(3);
#else
    Fixed_Ordered_Array<double> a(5);

    a.push_back(1.1);
    a.push_back(4);
    a.push_back(2.5);
    a.erase(4);
    a.erase(1);
    a.push_back(8);
    a.push_back(1);
    a.push_back(10);
    a.erase(3);
#endif

    //cout << a << endl;
    cout << "last content: ";
    a.dump();

    return 0;
}
