/*************************************************************************
      > File Name: day1_8_merge_two_ordered_list.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Wed 17 Jul 2019 04:55:17 AM CST
 ************************************************************************/

#include <iostream>
#include "Single_List.h"
#include "Circular_List.h"
#include "Double_List.h"

using namespace std;

int main(int argc, char **argv, char **env)
{
#if 0 
    Single_List<int> l1;
    l1.insert(4); 
    l1.insert(7);
    l1.insert(1);
    l1.insert(0);
    l1.insert(3);
    l1.dump();

    Single_List<int> l2;
    l2.insert(2); 
    l2.insert(17);
    l2.insert(11);
    l2.insert(6);
    l2.insert(3); 
    l2.dump();

    l1.merge(l2);
    l1.dump();

    Circular_List<int> cl1;
    cl1.insert(4); 
    cl1.insert(7);
    cl1.insert(1);
    cl1.insert(0);
    cl1.insert(3);
    cl1.dump();

    Circular_List<int> cl2;
    cl2.insert(2); 
    cl2.insert(17);
    cl2.insert(11);
    cl2.insert(6);
    cl2.insert(3); 
    cl2.dump();

    cl1.merge(cl2);
    cl1.dump();

    Double_List<int> dl1;
    dl1.insert(4); 
    dl1.insert(7);
    dl1.insert(1);
    dl1.insert(0);
    dl1.insert(3);
    dl1.dump();

    Double_List<int> dl2;
    dl2.insert(2); 
    dl2.insert(17);
    dl2.insert(11);
    dl2.insert(6);
    dl2.insert(3); 
    dl2.dump();
    
    dl1.merge(dl2);
    dl1.dump();

#else
    Single_List<double> l1;
    l1.insert(4.2); 
    l1.insert(7.1);
    l1.insert(1.9);
    l1.insert(0  );
    l1.insert(3.7);
    l1.dump();

    Single_List<double> l2;
    l2.insert(2.1 ); 
    l2.insert(17.8);
    l2.insert(11.0);
    l2.insert(6   );
    l2.insert(3.7 ); 
    l2.dump();

    l1.merge(l2);
    l1.dump();

    Circular_List<double> cl1;
    cl1.insert(4.2); 
    cl1.insert(7.1);
    cl1.insert(1.9);
    cl1.insert(0  );
    cl1.insert(3.7);
    cl1.dump();

    Circular_List<double> cl2;
    cl2.insert(2.1 ); 
    cl2.insert(17.8);
    cl2.insert(11.0);
    cl2.insert(6   );
    cl2.insert(3.7 ); 
    cl2.dump();

    cl1.merge(cl2);
    cl1.dump();

    Double_List<double> dl1;
    dl1.insert(4.2); 
    dl1.insert(7.1);
    dl1.insert(1.9);
    dl1.insert(0  );
    dl1.insert(3.7);
    dl1.dump();

    Double_List<double> dl2;
    dl2.insert(2.1 ); 
    dl2.insert(17.8);
    dl2.insert(11.0);
    dl2.insert(6   );
    dl2.insert(3.7 ); 
    dl2.dump();
    
    dl1.merge(dl2);
    dl1.dump();


#endif

    return 0;
}


