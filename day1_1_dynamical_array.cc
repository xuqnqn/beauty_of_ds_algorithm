/*************************************************************************
      > File Name: day1_1_dynamical_array.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Sun 14 Jul 2019 06:46:01 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include "Dynamical_Array.h"

int main(int argc, char **argv, char **env)
{
    const int len = 20;
    const int extra = 10;

#if 0 
    //Dynamical_Array<int> darray(len);
    Dynamical_Array<int> darray;
    Dynamical_Array<int> darray2(darray);
    Dynamical_Array<int> darray3;
    //Dynamical_Array<int> darray3(len);
    darray3 = darray;

    for(int i = 0; i < len + extra; i++) {
        darray[i] = i;
        darray2[i] = i + 5;
        darray3[i] = i + 10;
    }
#else
    Dynamical_Array<string> darray(len);
    Dynamical_Array<string> darray2(darray);
    Dynamical_Array<string> darray3(len);
    darray3 = darray;

    for(int i = 0; i < len + extra; i++) {
        darray[i] = "a" + std::to_string(i);
        darray2[i] = "b" + std::to_string(i);
        darray3[i] = "c" + std::to_string(i);
    }
#endif

    for(int i = 0; i < len + extra; i++) {
        cout << "darray[" << i << "] = " << darray[i] << endl;
    }
    for(int i = 0; i < len + extra; i++) {
        cout << "darray2[" << i << "] = " << darray2[i] << endl;
    }
    for(int i = 0; i < len + extra; i++) {
        cout << "darray3[" << i << "] = " << darray3[i] << endl;
    }

    return 0;
}
