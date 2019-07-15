/*************************************************************************
      > File Name: Fixed_Ordered_Array.h
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Mon 15 Jul 2019 11:25:29 PM CST
 ************************************************************************/

#ifndef _FIXED_ORDERED_ARRAY_H
#define _FIXED_ORDERED_ARRAY_H

#include <iostream>
#include <cstring>
#include <exception>

using namespace std;


template <typename T>
class Fixed_Ordered_Array {
    public:
        Fixed_Ordered_Array(int size = 10);
        Fixed_Ordered_Array(const Fixed_Ordered_Array & a);
        Fixed_Ordered_Array & operator = (const Fixed_Ordered_Array & a);
        ~Fixed_Ordered_Array();


        int push_back(const T & data);
        int erase(const T & data);

        //friend ostream & operator << <T> (ostream & os, const Fixed_Ordered_Array<T> & d); 

        void dump() {
            for(int i = 0; i < _size; i++) {
                cout << _array[i] << " ";
            }
            cout << endl;
        }


    private:
        T *         _array;
        int         _pos;
        const int   _size;
};



template <typename T>
Fixed_Ordered_Array<T> :: Fixed_Ordered_Array(int size) : _size(size) {
    try {
        _array = new T[size];
    } catch (exception &e) {
        cout << "" << e.what() << endl;
    }
    memset(_array, 0, size);
    _pos = 0;
}

template <typename T>
Fixed_Ordered_Array<T> :: Fixed_Ordered_Array(const Fixed_Ordered_Array & a) {
    try {
        _array = new T[a._size];
    } catch (exception &e) {
        cout << "" << e.what() << endl;
    }

    memcpy(_array, a._array, a._size);
    _size = a._size;
    _pos = 0;
}

template <typename T>
Fixed_Ordered_Array<T> & Fixed_Ordered_Array<T> :: operator = (const Fixed_Ordered_Array & a) {
    if(this == &a) return *this;
    try {
        _array = new T[a._size];
    } catch (exception &e) {
        cout << "" << e.what() << endl;
    }

    memcpy(_array, a._array, a._size);
    _size = a._size;
    _pos = 0;

    return *this;
}

template <typename T>
Fixed_Ordered_Array<T> :: ~Fixed_Ordered_Array() {
    _pos = 0;
    delete [] _array;
}


template <typename T>
int Fixed_Ordered_Array<T> :: push_back(const T & data) { /// <<<------------------ should be highlighted -------------
    if(_pos >= _size) {
        cout << "Cannot push_back directly, array dump: ";
        dump();
        int i = 0, j = 0; 
        while(j < _size) {
            while(_array[j] == T(0) && j < _size) j++;
            if(j >= _size) break;
            if(i != j) {
                _array[i] = _array[j];    
            }
            j++;
            i++;
        }
        
        if(i < _size) {
            _pos = i;
            cout << "array is compacted: ";
            dump();
        } else {
            cout << "array is full" << endl;
            return -1;
        }
    }

    _array[_pos++] = data;
    cout << data << " is pushed_back" << endl;

    return 0;
}

template <typename T>
int Fixed_Ordered_Array<T> :: erase(const T & data) {
    int i = 0;
    for(i = 0; _array[i] != data && i < _size; i++);
    if(i < _size) {
        _array[i] = T(0);
        cout << data << " is erased" << endl;
        return 0;
    }

    cout << data << " is not found" << endl;
    return -1;
}


#endif
