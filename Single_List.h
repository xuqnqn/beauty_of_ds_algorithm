/*************************************************************************
      > File Name: Single_List.h
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Tue 16 Jul 2019 07:36:51 AM CST
 ************************************************************************/

#ifndef _SINGLE_LIST_H
#define _SINGLE_LIST_H

#include <iostream>

using namespace std;

//带头节点的单链表，比不带头节点的实现简单
template <typename T>
class Single_List {
    public:
        Single_List();
        ~Single_List();
        Single_List(const Single_List & l) = delete;
        Single_List & operator = (const Single_List & l) = delete;

        struct Node {
            Node(const T& a) : data(a), next(nullptr) {}
            Node() : data(0), next(nullptr) {}
            T data;
            Node * next;
        };

        int insert(const T& a);
        int remove(const T& a);
        int reverse_order();
        void dump();

    private:
        Node * head; 
};

template<typename T>
Single_List<T> :: Single_List() {
    try {
        head = new Node;
    } catch (exception &e) {
        cout << "in Single list constructor: " << e.what() << endl;
    }
}

template<typename T>
Single_List<T> :: ~Single_List() {
    Node * p;
    while(head->next) {
        p = head->next;
        head->next = head->next->next;
        delete p;
    }
    delete head;
}

template<typename T>
int Single_List<T> :: insert(const T& a) {
    cout << "Single list, inserting " << a << endl;
    Node * p;
    try {
        p = new Node(a);    
    } catch (exception &e) {
        cout << "in Single list insert function:" << e.what() << endl;
        return -1;
    }
    p->next = head->next;
    head->next = p;
    return 0;
}

template<typename T>
int Single_List<T> :: remove(const T& a) {
    cout << "Single list, removing " << a << endl;
    Node *p = head->next;
    Node *q = head;
    while(p && p->data != a) {
        q = p;
        p = p->next;
    }
    if(p && p->data == a) {
        q->next = p->next;
        delete p;
    } else {
        cout << "Single list, " << a << " is not found" << endl;
        return -1;
    }
    return 0;
}

template<typename T>
int Single_List<T> :: reverse_order() {
    Node *p = head->next;
    Node *q = nullptr;
    head->next = nullptr;
    while(p) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }

    cout << "Single list, list order is reversed" << endl;
    return 0;
}

template<typename T>
void Single_List<T> :: dump() {
    if(!head->next){
        cout << "Single list, List is empty" << endl;
        return;
    }

    cout << "Single list, List element: ";
    Node *p = head->next;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return;
}


#endif
