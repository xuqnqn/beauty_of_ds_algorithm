/*************************************************************************
      > File Name: select_sort.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Sun 21 Jul 2019 11:23:00 PM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include "My_Sort.h"

using namespace std;

void dump_data(const vector<unsigned int> &a) {
    unsigned int i = 0;
    for(auto it = a.begin(); it != a.end(); it++) {
        if(!(i++ % 16) && (i-1)) cout << endl;
        printf("%6d ", *it);
        //cout << *it << " ";
    }
    cout << endl;
    cout << "total data num: " << a.size() << endl;
}

int main(int argc, char **argv, char **env)
{
    std::ifstream rand_file("rand_nums.txt");
    if(!rand_file.is_open()) {
        cout << "file rand_nums.txt is not open" << endl;
        return -1;
    }

    vector<unsigned int> vs;
    for(unsigned int a; rand_file >> a;) {
        vs.push_back(a);
    }

    if(rand_file.bad()) cout << "I/O error while reading\n" << endl;
    else if(rand_file.eof()) cout << "Read all data successfully\n" << endl;
    else if(rand_file.fail()) cout << "Non-integer data encountered\n" << endl;

    vector<unsigned int> vb(vs);
    vector<unsigned int> vi(vs);
    vector<unsigned int> vm(vs);
    vector<unsigned int> vq(vs);

    double elapsed_time = 0;
    cout << "\nbefore sort, dump data \'vs\':" << endl;
    dump_data(vs);
    //用临时对象调用排序函数方法
    elapsed_time = My_Sort<unsigned int>(vs).select_sort();
    cout << "\nafter sort, dump data \'vs\':" << endl;
    dump_data(vs);
    cout << "sort \'vs\' used time: " << elapsed_time << "(ms)" << endl;

    cout << "\nbefore sort, dump data \'vb\':" << endl;
    dump_data(vb);
    elapsed_time = My_Sort<unsigned int>(vb).bubble_sort();
    cout << "\nafter sort, dump data \'vb\':" << endl;
    dump_data(vb);
    cout << "sort \'vb\' used time: " << elapsed_time << "(ms)" << endl;

    cout << "\nbefore sort, dump data \'vi\':" << endl;
    dump_data(vi);
    elapsed_time = My_Sort<unsigned int>(vi).insert_sort();
    cout << "\nafter sort, dump data \'vi\':" << endl;
    dump_data(vi);
    cout << "sort \'vi\' used time: " << elapsed_time << "(ms)" << endl;

    cout << "\nbefore sort, dump data \'vm\':" << endl;
    dump_data(vm);
    elapsed_time = My_Sort<unsigned int>(vm).merge_sort();
    cout << "\nafter sort, dump data \'vm\':" << endl;
    dump_data(vm);
    cout << "sort \'vm\' used time: " << elapsed_time << "(ms)" << endl;

    cout << "\nbefore sort, dump data \'vq\':" << endl;
    dump_data(vq);
    elapsed_time = My_Sort<unsigned int>(vq).quick_sort();
    cout << "\nafter sort, dump data \'vq\':" << endl;
    dump_data(vq);
    cout << "sort \'vq\' used time: " << elapsed_time << "(ms)" << endl;


    return 0;
}
