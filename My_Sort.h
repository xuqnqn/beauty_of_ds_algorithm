/*************************************************************************
      > File Name: My_Sort.h
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Mon 22 Jul 2019 12:23:10 AM CST
 ************************************************************************/

#ifndef _MY_SORT_H
#define _MY_SORT_H

#include <sys/time.h>
#include <vector>

using namespace std;

#if 1 
#define TIC \
struct timeval time1, time2; \
gettimeofday(&time1, nullptr)

#define TOC \
gettimeofday(&time2, nullptr); \
double elapsed_time = (time2.tv_sec - time1.tv_sec) * 1000. + \
(time2.tv_usec - time1.tv_usec) / 1000.; \
return elapsed_time

//fprintf(stdout, "Elapsed time: %lf(ms)\n", elapsed_time)
#else
#define TIC
#define TOC return 0
#endif


template <typename T>
class My_Sort {
    public:
        My_Sort() = delete;
        My_Sort(const My_Sort & ms) = delete;
        My_Sort & operator = (const My_Sort & ms) = delete;
        ~My_Sort() = default;

        My_Sort(vector<T> & v) : _d(v) {}

        double select_sort();
        double bubble_sort();
        double insert_sort();
        double merge_sort(); 
        double quick_sort(); 

    private:
        vector<T> & _d;     //dataArray;
};

template <typename T>
double My_Sort<T> :: select_sort() {
    TIC;
    for(int i = 0; i < _d.size() - 1; i++) {
        for(int j = i + 1; j < _d.size(); j++) {
            if(_d[i] > _d[j]) {
                T tmp = _d[i];
                _d[i] = _d[j];
                _d[j] = tmp;
            }
        }
    }
    TOC;
}

template <typename T>
double My_Sort<T> :: bubble_sort() {
    TIC;
    for(int i = _d.size() - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(_d[j] > _d[j + 1]) {  //此处没有=号保证排序是稳定的
                T tmp = _d[j + 1];
                _d[j + 1] = _d[j];
                _d[j] = tmp;
            }
        }
    }
    TOC;
}

template <typename T>
double My_Sort<T> :: insert_sort() {
    TIC;
    for(int i = 1; i < _d.size(); i++) {
        T tmp = _d[i];
        int j = i - 1;
        for(; j >= 0; j--) {
            if(_d[j] > tmp) {  //此处没有=号保证排序是稳定的
                _d[j + 1] = _d[j];
            } else {
                break;
            }
        }
        _d[j + 1] = tmp;
    }
    TOC;
}

template <typename T>
double My_Sort<T> :: merge_sort() {
    TIC;

    TOC;
}

template <typename T>
double My_Sort<T> :: quick_sort() {
    TIC;

    TOC;
}

#endif
