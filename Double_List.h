/*************************************************************************
      > File Name: Double_List.h
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Tue 16 Jul 2019 09:40:40 PM CST
 ************************************************************************/

#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#include <iostream>

using namespace std;

//带头节点的双向链表，比不带头节点的实现简单
template <typename T>
class Double_List {
    public:
        Double_List();
        ~Double_List();
        Double_List(const Double_List & l) = delete;
        Double_List & operator = (const Double_List & l) = delete;

        struct Node {
            Node(const T& a) : data(a), pre(nullptr), next(nullptr) {}
            Node() : data(0), pre(nullptr), next(nullptr) {}
            T data;
            Node * pre;
            Node * next;
        };

        int insert(const T& a);
        int remove(const T& a);
        void dump();

    private:
        Node * head; 
};

template<typename T>
Double_List<T> :: Double_List() {
    try {
        head = new Node;
    } catch (exception &e) {
        cout << "in Double list constructor: " << e.what() << endl;
    }
}

template<typename T>
Double_List<T> :: ~Double_List() {
    Node * p;
    while(head->next) {
        p = head->next;
        head->next = head->next->next;
        delete p;
    }
    delete head;
}

template<typename T>
int Double_List<T> :: insert(const T& a) {
    cout << "inserting " << a << endl;
    Node * p;
    try {
        p = new Node(a);    
    } catch (exception &e) {
        cout << "in Double list insert function:" << e.what() << endl;
        return -1;
    }
    if(head->next) {    //这里容易忘记有四个指针要修改
        Node * q = head->next;
        q->pre = p;
        head->next = p;

        p->next = q;
        p->pre = head;
    } else {
        head->next = p;

        p->next = nullptr;
        p->pre = head;
    }

    return 0;
}

template<typename T>
int Double_List<T> :: remove(const T& a) {
    cout << "removing " << a << endl;
    Node *p = head->next;
    Node *q = head;
    while(p && p->data != a) {
        q = p;
        p = p->next;
    }
    if(p && p->data == a) {
        q->next = p->next;
        q->next->pre = q;
        delete p;
    } else {
        cout << a << " is not found" << endl;
        return -1;
    }
    return 0;
}

template<typename T>
void Double_List<T> :: dump() {
    if(!head->next){
        cout << "List is empty" << endl;
        return;
    }

    cout << "List element: ";
    Node *p = head->next;
    Node *q = head;
    while(p) {
        cout << p->data << " ";
        q = p;
        p = p->next;
    }
    cout << endl;

    cout << "List element: ";
    while(q != head) {
        cout << q->data << " ";
        q = q->pre;
    }
    cout << ", reversed order" << endl;
    return;
}



#endif
