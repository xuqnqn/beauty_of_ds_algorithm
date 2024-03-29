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
        int merge(const Circular_List & a);
        int reverse_order();
        void clear();
        void show_middle_node() const;
        void dump() const;

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
    cout << "Circular list, inserting " << a << endl;
    Node * p;
    try {
        p = new Node(a);    
    } catch (exception &e) {
        cout << "in Circular list insert function:" << e.what() << endl;
        return -1;
    }

#if 0   //Always insert a new Node at list head
    p->next = head->next;
    head->next = p;
#else   //keep list in ascending order when insert a new Node
    Node *q = head->next;
    Node *r = head;
    while(q != head) {
        if(q->data > p->data) {
            p->next = q;
            r->next = p;
            return 0;
        } else {
            r = q;
        }
        q = q->next;
    }
    p->next = q;
    r->next = p;
#endif    

    return 0;
}

template<typename T>
int Circular_List<T> :: remove(const T& a) {
    cout << "Circular list, removing " << a << endl;
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
        cout << "Circular list, " << a << " is not found" << endl;
        return -1;
    }
    return 0;
}

template<typename T>
void Circular_List<T> :: clear() {
    cout << "Circular list, clearing" << endl;
    Node *p = head->next;
    head->next = head;
    while(p != head) {
        Node *q = p->next;
        delete p;
        p = q;
    }

    return;
}

template<typename T>
int Circular_List<T> :: merge(const Circular_List & a) {
    cout << "Circular list, merging list: ";
    a.dump();

    Node * p = a.head->next;
    Node * q = head->next;
    Node * r = head;

    while(p != a.head && q != head) {
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

    while(p != a.head) {
        Node * m = new Node(p->data);
        r->next = m;
        r = r->next;
        p = p->next;
    }
    r->next = head;

    return 0;
}

template<typename T>
int Circular_List<T> :: reverse_order() {
    Node *p = head->next;
    Node *q = nullptr;
    head->next = head;
    while(p != head) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }

    cout << "Circular list, list order is reversed" << endl;
    return 0;
}

template<typename T>
void Circular_List<T> :: show_middle_node() const {
    cout << "Circular list, middle node: ";
    if(head->next == head) {
        cout << "NULL" << endl;
        return;
    }

    if(head->next->next == head) {
        cout << head->next->data << endl;
        return;
    } 

    Node *p = head->next;
    Node *q = head->next->next; 
    while(q != head && q->next != head) {
        p = p->next;
        q = q->next->next;
    }
    if(q == head) {   //此处，如果在大脑中不好想明白，在纸上画个图就清楚了
        cout << p->data << endl;
    } else {
        cout << p->data << " "<< p->next->data << endl;
    }

    return;
}

template<typename T>
void Circular_List<T> :: dump() const {
    if(head->next == head){
        cout << "Circular list, List is empty" << endl;
        return;
    }

    cout << "Circular list, List element: ";
    Node *p = head->next;
    while(p != head) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return;
}




#endif
