/*************************************************************************
      > File Name: day1_7_reverse_single_list.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Tue 16 Jul 2019 10:45:06 PM CST
 ************************************************************************/

#include <iostream>
#include "Single_List.h"
#include "Circular_List.h"
#include "Double_List.h"

using namespace std;

int main(int argc, char **argv, char **env)
{
#if 0 
    Single_List<int> l;
    l.insert(4); //insert a node
    l.insert(7);
    l.insert(1);
    l.insert(0);
    l.insert(3); //insert several nodes
    l.dump();
    l.reverse_order();
    l.dump();

    Circular_List<int> cl;
    cl.insert(4); //insert a node
    cl.insert(7);
    cl.insert(1);
    cl.insert(0);
    cl.insert(3); //insert several nodes
    cl.dump();
    cl.reverse_order();
    cl.dump();

    Double_List<int> dl;
    dl.insert(4); //insert a node
    dl.insert(7);
    dl.insert(1);
    dl.insert(0);
    dl.insert(3); //insert several nodes
    dl.dump();
    dl.reverse_order();
    dl.dump();
#else
    Single_List<double> l;
    l.insert(4.2); //insert a node
    l.insert(7.2);
    l.insert(1.0);
    l.insert(0);
    l.insert(3.5); //insert several nodes
    l.dump();
    l.reverse_order();
    l.dump();

    Circular_List<double> cl;
    cl.insert(4.2); //insert a node
    cl.insert(7.2);
    cl.insert(1.0);
    cl.insert(0);
    cl.insert(3.5); //insert several nodes
    cl.dump();
    cl.reverse_order();
    cl.dump();

    Double_List<double> dl;
    dl.insert(4.2); //insert a node
    dl.insert(7.2);
    dl.insert(1.0);
    dl.insert(0);
    dl.insert(3.5); //insert several nodes
    dl.dump();
    dl.reverse_order();
    dl.dump();
#endif

    return 0;
}
