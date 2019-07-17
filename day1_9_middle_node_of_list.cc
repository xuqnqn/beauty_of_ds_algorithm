/*************************************************************************
      > File Name: day1_9_middle_node_of_list.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Wed 17 Jul 2019 07:30:41 AM CST
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
    l.insert(4); 
    l.insert(7);
    l.insert(1);
    l.insert(0);
    l.insert(3);
    l.insert(2); 
    l.insert(17);
    l.insert(17);
    l.insert(11);
    l.insert(6);
    l.dump();
    l.show_middle_node();
    l.clear();
    l.dump();
    l.show_middle_node();

    Circular_List<int> cl;
    cl.insert(4); 
    cl.insert(7);
    cl.insert(1);
    cl.insert(0);
    cl.insert(3);
    cl.insert(2); 
    cl.insert(17);
    cl.insert(11);
    cl.insert(6);
    cl.dump();
    cl.show_middle_node();
    cl.clear();
    cl.dump();
    cl.show_middle_node();

    Double_List<int> dl;
    dl.insert(4); 
    dl.insert(7);
    dl.insert(1);
    dl.insert(0);
    dl.insert(3);
    dl.insert(2); 
    dl.insert(17);
    dl.insert(11);
    dl.insert(6);
    dl.dump();
    dl.show_middle_node();
    dl.clear();
    dl.dump();
    dl.show_middle_node();

#else
    Single_List<double> l;
    l.insert(4.2); 
    l.insert(7.1);
    l.insert(1.9);
    l.insert(0  );
    l.insert(3.7);
    l.insert(2.1 ); 
    l.insert(17.8);
    l.insert(11.0);
    l.insert(6   );
    l.insert(6   );
    l.insert(3.7 ); 
    l.dump();
    l.show_middle_node();
    l.clear();
    l.dump();
    l.show_middle_node();


    Circular_List<double> cl;
    cl.insert(4.2); 
    cl.insert(7.1);
    cl.insert(1.9);
    cl.insert(0  );
    cl.insert(3.7);
    cl.insert(2.1 ); 
    cl.insert(17.8);
    cl.insert(11.0);
    cl.insert(6   );
    cl.insert(3.7 ); 
    cl.dump();
    cl.show_middle_node();
    cl.clear();
    cl.dump();
    cl.show_middle_node();

    Double_List<double> dl;
    dl.insert(4.2); 
    dl.insert(7.1);
    dl.insert(1.9);
    dl.insert(0  );
    dl.insert(3.7);
    dl.insert(2.1 ); 
    dl.insert(17.8);
    dl.insert(11.0);
    dl.insert(6   );
    dl.insert(3.7 ); 
    dl.dump();
    dl.show_middle_node();
    dl.clear();
    dl.dump();
    dl.show_middle_node();


#endif

    return 0;
}


