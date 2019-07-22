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
        void mergeTwoPart(vector<T> & a, unsigned int p, unsigned int r, unsigned int q);
        void merge(vector<T> & a, unsigned int p, unsigned int q);

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
    for(int i = _d.size() - 1; i > 0; i--) {
        bool isSwapped = false;
        for(int j = 0; j < i; j++) {
            if(_d[j] > _d[j + 1]) {  //此处没有=号保证排序是稳定的
                T tmp = _d[j + 1];
                _d[j + 1] = _d[j];
                _d[j] = tmp;
                isSwapped = true;
            }
        }
        if(!isSwapped) break;   //这个优化说明在一次冒泡遍历过程中，没有swap，说明都是有序的了，可以提前退出循环比较
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
                break;      //这个优化可以提前退出循环比较
            }
        }
        _d[j + 1] = tmp;
    }
    TOC;
}

template <typename T>
void My_Sort<T> :: mergeTwoPart(vector<T> & a, unsigned int p, unsigned int r, unsigned int q) {
    vector<T> t;
    unsigned int i = p;
    unsigned int j = r + 1;

    while(i <= r && j <= q) {
        if(a[i] <= a[j]) {
            t.push_back(a[i]);
            i++;
        } else {
            t.push_back(a[j]);
            j++;
        }
    }

    while(i <= r) {
        t.push_back(a[i]);
        i++;
    }

    while(j <= q) {
        t.push_back(a[j]);
        j++;
    }

    for(i = 0; i < t.size(); i++) {
        a[p + i] = t[i];
    }

    return; 
}


template <typename T>
void My_Sort<T> :: merge(vector<T> & a, unsigned int p, unsigned int q) {
    if(p >= q) return;
    unsigned int r = (p + q) / 2;

    merge(a, p, r);
    merge(a, r + 1, q);
    mergeTwoPart(a, p, r, q); // merge a[p, r] with a[r+1, q]

    return;
}


template <typename T>
double My_Sort<T> :: merge_sort() {
    TIC;

    merge(_d, 0, _d.size() - 1);
    TOC;
}

template <typename T>
double My_Sort<T> :: quick_sort() {
    TIC;

    TOC;
}

#endif
