/*************************************************************************
      > File Name: day1_6_double_list.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Tue 16 Jul 2019 09:38:53 PM CST
 ************************************************************************/

#include <iostream>
#include "Double_List.h"

using namespace std;

int main(int argc, char **argv, char **env)
{
#if 0
    Double_List<int> l;
    l.dump();   //dump empty list

    l.remove(7); //remove from empty list

    l.insert(4); //insert a node
    l.dump();

    l.insert(7);
    l.insert(1);
    l.insert(0);
    l.insert(3); //insert several nodes
    l.dump();

    l.remove(7); //remove a existed node
    l.dump();

    l.remove(79); //remove a non-existed node
#else
    Double_List<double> l;
    l.dump();   //dump empty list

    l.remove(7.3); //remove from empty list

    l.insert(4.2); //insert a node
    l.dump();

    l.insert(7.2);
    l.insert(1.0);
    l.insert(0);
    l.insert(3.5); //insert several nodes
    l.dump();

    l.remove(7.2); //remove a existed node
    l.dump();

    l.remove(79); //remove a non-existed node
#endif

    return 0;
}
