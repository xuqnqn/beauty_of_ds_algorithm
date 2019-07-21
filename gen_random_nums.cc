/*************************************************************************
      > File Name: gen_random_nums.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Sun 21 Jul 2019 10:49:35 PM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

const unsigned int RANDOM_NUM_CNT = 10000;
//const unsigned int RANDOM_NUM_CNT = 200;

int main(int argc, char **argv, char **env)
{
    std::srand(std::time(nullptr));
    
    vector<unsigned int> va;
    va.reserve(RANDOM_NUM_CNT);
    for(int i = 0; i < RANDOM_NUM_CNT; i++) {
        va.push_back(std::rand() % 0xFFFF);
    }

    std::ofstream randfile("rand_nums.txt", std::ios::binary);
    if(!randfile.is_open()) {
        cout << "rand_nums.txt is not open" << endl;
        exit(0);
    }

    for(auto it = va.begin(); it != va.end(); it++) {
        randfile << *it << " ";
    }
    randfile.close();

    return 0;
}
