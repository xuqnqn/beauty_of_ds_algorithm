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
        int merge(const Single_List & a);
        int reverse_order();
        void clear();
        void show_middle_node() const;
        void dump() const;  //定义为const 函数，这样const形参对象，就可以调用这个const 函数了

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

#if 0   //Always insert a new Node at list head
    p->next = head->next;
    head->next = p;
#else   //keep list in ascending order when insert a new Node
    Node *q = head->next;
    Node *r = head;
    while(q) {
        if(q->data > p->data) {
            p->next = q;
            r->next = p;
            return 0;
        } else {
            r = q;
        }
        q = q->next;
    }
    r->next = p;
#endif

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
void Single_List<T> :: clear() {
    cout << "Single list, clearing" << endl;
    Node *p = head->next;
    head->next = nullptr;
    while(p) {
        Node *q = p->next;
        delete p;
        p = q;
    }

    return;
}

template<typename T>
int Single_List<T> :: merge(const Single_List & a) {
    cout << "Single list, merging list: ";
    a.dump();

    Node * p = a.head->next;
    Node * q = head->next;
    Node * r = head;

    while(p && q) {
        if(q->data > p->data) {
            Node * m = new Node(p->data);
            m->next = q;
            r->next = m;
            r = m;
            p = p->next;
        } else {
            r = q;
            q = q->next;
        }
    }

    while(p) {
        Node * m = new Node(p->data);
        r->next = m;
        r = r->next;
        p = p->next;
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
void Single_List<T> :: show_middle_node() const {
    cout << "Single list, middle node: ";
    if(!head->next) {
        cout << "NULL" << endl;
        return;
    }

    if(!head->next->next) {
        cout << head->next->data << endl;
        return;
    } 

    Node *p = head->next;
    Node *q = head->next->next; 
    while(q && q->next) {
        p = p->next;
        q = q->next->next;
    }
    if(!q) {   //此处，如果在大脑中不好想明白，在纸上画个图就清楚了
        cout << p->data << endl;
    } else {
        cout << p->data << " "<< p->next->data << endl;
    }

    return;
}

template<typename T>
void Single_List<T> :: dump() const {
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
