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
#include <list>

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
        double bulk_sort(); 

    private:
        void dump_data(const vector<T> &a);
        void mergeTwoPart(vector<T> & a, int p, int r, int q);
        void merge(vector<T> & a, int p, int q);
        void qksort(vector<T> & a, int p, int q);
        int  partition(vector<T> & a, int p, int q);

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
void My_Sort<T> :: mergeTwoPart(vector<T> & a, int p, int r, int q) {
    vector<T> t;
    int i = p;
    int j = r + 1;

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
void My_Sort<T> :: merge(vector<T> & a, int p, int q) {
    if(p >= q) return;
    int r = (p + q) / 2;

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
int My_Sort<T> :: partition(vector<T> & a, int p, int q) {
    T pivot = a[q];
    int j = p;
    for(int i = j; i < q; i++) {    //注意： i = j
        if(a[i] < pivot) {
            T tmp = a[j];//这里可以再加个判断避免一下不必要的自赋值
            a[j] = a[i];
            a[i] = tmp;
            j++;
        }
    }
    T tmp = a[j];
    a[j] = a[q];
    a[q] = tmp;

    return j;
}

template <typename T>
void My_Sort<T> :: qksort(vector<T> & a, int p, int q) {
    if(p >= q) return;

    int i = 0;

    i = partition(a, p, q);
    qksort(a, p, i - 1);
    qksort(a, i + 1, q);

    return;
}

template <typename T>
double My_Sort<T> :: quick_sort() {
    TIC;
    qksort(_d, 0, _d.size() - 1);
    TOC;
}

template <typename T>
void My_Sort<T> :: dump_data(const vector<T> &a) {
    unsigned int i = 0;
    for(auto it = a.begin(); it != a.end(); it++) {
        if(!(i++ % 16) && (i-1)) cout << endl;
        printf("%6d ", *it);
        //cout << *it << " ";
    }
    cout << endl;
    cout << "total data num: " << a.size() << endl;
}


template <typename T>
double My_Sort<T> :: bulk_sort() {
    TIC;
    T max = _d[0];
    T min = _d[0];
    for(int i = 0; i < _d.size(); i++) { //找到最大值和最小值，获取数据 “范围”
        if(max < _d[i]) max = _d[i];
        if(min > _d[i]) min = _d[i];
    }
    
    const int bulk_cnt = 10; //10 + 1个桶
    T range = max - min;
    T interval = range / bulk_cnt;

    vector<vector<T>> bulk;
    for(int i = 0; i <= bulk_cnt; i++) { //i <= bulk_cnt， 注意这个=号，这是个坑
        bulk.push_back(vector<T>());     //注意嵌套vector的使用方法，要先push
    }

    for(int i = 0; i < _d.size(); i++) { 
        for(int j = 0; j <= bulk_cnt; j++) {
            if(j == (_d[i] - min) / interval) { //可以用gdb条件断点在此次调试, ie: b 242 if _d[i] == 45397
                bulk[j].push_back(_d[i]);
                break;
            }
        }
    }

    for(int i = 0; i <= bulk_cnt; i++) { 
        qksort(bulk[i], 0, bulk[i].size() - 1); //桶排序，在桶内部调用快速排序
    }

#if 0 
    cout << "dumping out bulk:" << endl;
    for(int i = 0; i <= bulk_cnt; i++) { 
        dump_data(bulk[i]);
    }
#endif

    int k = 0;
    for(int i = 0; i <= bulk_cnt; i++) { 
        for(int j = 0; j < bulk[i].size(); j++) {
            _d[k++] = bulk[i][j];
        }
    }

    TOC;
}

#endif
