/*************************************************************************
      > File Name: Dynamical_Array.h
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Sun 14 Jul 2019 08:38:26 PM CST
 ************************************************************************/

#ifndef _DYNAMICAL_ARRAY_H
#define _DYNAMICAL_ARRAY_H

using namespace std;

template <typename T>
class Dynamical_Array {
    public:
        Dynamical_Array(int n = 200);
        Dynamical_Array(const Dynamical_Array & a);
        Dynamical_Array & operator = (const Dynamical_Array & a);
        ~Dynamical_Array();
        T & operator [] (int i);

    private:
        T * _array;
        int _size;
};

template <typename T>
Dynamical_Array<T> :: Dynamical_Array(int n) : _size(n) {
    try {
        _array = new T[n];
    } catch (exception & e) {
        cout << "In Dynamical_Array(int n), Error: " << e.what() << endl;
    }
}

template <typename T>
Dynamical_Array<T> :: Dynamical_Array(const Dynamical_Array & a) {
    try {
        _array = new T[a._size];
    } catch(exception & e) {
        cout << "In Dynamical_Array(const Dynamical_Array & a), Error: " << e.what() << endl;
    }
    for(int i = 0; i < a._size; i++) {
        _array[i] = a._array[i];
    }

    _size = a._size;
}

template <typename T>
Dynamical_Array<T> & Dynamical_Array<T> :: operator = (const Dynamical_Array & a) {
    if(&a == this) return *this;

    T * p;
    try {
        p = new T[a._size];
    } catch(exception & e) {
        cout << "In Dynamical_Array(const Dynamical_Array & a), Error: " << e.what() << endl;
    }
    for(int i = 0; i < a._size; i++) {
        p[i] = a._array[i];
    }

    delete [] _array;
    _array = p;
    _size = a._size;

    return *this;
}


template <typename T>
Dynamical_Array<T> :: ~Dynamical_Array() {
    delete [] _array;
}

template <typename T>
T & Dynamical_Array<T> :: operator [] (int i) {
    if(i >= _size) {
        int new_size = i * 2;
        T * p;
        try {
            p = new T[new_size];
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl; 
        }

        cout << "Dynamical Array's size is enlarged to: " << new_size << endl;

        for(int j = 0; j < _size; j++) {
            p[j] = _array[j];
        }
        delete [] _array;
        _array = p;
        _size = new_size;
    }

    return _array[i];
}


#endif
