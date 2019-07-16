/*************************************************************************
      > File Name: Circular_List.h
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Tue 16 Jul 2019 09:20:02 PM CST
 ************************************************************************/

#ifndef _CIRCULAR_LIST_H
#define _CIRCULAR_LIST_H

#include <iostream>

using namespace std;

//带头节点的循环链表，比不带头节点的实现简单
template <typename T>
class Circular_List {
    public:
        Circular_List();
        ~Circular_List();
        Circular_List(const Circular_List & l) = delete;
        Circular_List & operator = (const Circular_List & l) = delete;

        struct Node {
            Node(const T& a) : data(a), next(nullptr) {}
            Node() : data(0), next(nullptr) {}
            T data;
            Node * next;
        };

        int insert(const T& a);
        int remove(const T& a);
        void dump();

    private:
        Node * head; 
};

template<typename T>
Circular_List<T> :: Circular_List() {
    try {
        head = new Node;
        head->next = head;
    } catch (exception &e) {
        cout << "in Circular list constructor: " << e.what() << endl;
    }
}

template<typename T>
Circular_List<T> :: ~Circular_List() {
    Node * p;
    while(head->next != head) {
        p = head->next;
        head->next = head->next->next;
        delete p;
    }
    delete head;
}

template<typename T>
int Circular_List<T> :: insert(const T& a) {
    cout << "inserting " << a << endl;
    Node * p;
    try {
        p = new Node(a);    
    } catch (exception &e) {
        cout << "in Circular list insert function:" << e.what() << endl;
        return -1;
    }
    p->next = head->next;
    head->next = p;
    return 0;
}

template<typename T>
int Circular_List<T> :: remove(const T& a) {
    cout << "removing " << a << endl;
    Node *p = head->next;
    Node *q = head;
    while(p != head && p->data != a) {
        q = p;
        p = p->next;
    }
    if(p != head && p->data == a) {
        q->next = p->next;
        delete p;
    } else {
        cout << a << " is not found" << endl;
        return -1;
    }
    return 0;
}

template<typename T>
void Circular_List<T> :: dump() {
    if(head->next == head){
        cout << "List is empty" << endl;
        return;
    }

    cout << "List element: ";
    Node *p = head->next;
    while(p != head) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return;
}




#endif
