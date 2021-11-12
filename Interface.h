#pragma once

#include<iostream>
#include<queue>
#include<vector>
#include "Strategy.h"

using namespace std;

template<typename Data>class Interface {
public:
    virtual ~Interface() {};
    virtual void insert(Data data) = 0;
    virtual void inorder() = 0;
    virtual void find(Data data, Strategy<Data>* comp) = 0;
    virtual void remove(Data data) = 0;
    virtual void remove(Data data, Strategy<Data>* comp) = 0;
};

template<typename Data>
class ConcretteInterface : public Interface<Data> {
public:

    void insert(Data data) {}
    void inorder(){}
    void find(Data data, Strategy<Data>* comp){}
    void remove(Data data){}
    void remove(Data data, Strategy<Data>* comp){}
};

template<typename Data>
class Decorator :public Interface<Data> {
private:
    Interface<Data>* interface_;

public:
    Decorator(Interface<Data>* _interface) {
        interface_ = _interface;
    }
    ~Decorator() {
        delete interface_;
    }
    void insert(Data data) {}
    void inorder() {}
    void find(Data data, Strategy<Data>* comp) {}
    void remove(Data data) {}
    void remove(Data data, Strategy<Data>* comp) {}
};

template<typename Data, typename StrategyType>
class TreeDecorator :public Decorator<Data> {
public:
    Strategy<Data>* compId;
    AVLTree<Data>* tree;
    TreeDecorator(Interface<Data>* interface_) 
    : Decorator<Data>(interface_), compId(new StrategyType), tree(new AVLTree<Data>(compId)){}
    void insert(Data data)
    {
        tree->insert_(data);
    }
    void inorder()
    {
        tree->inorder_();
    }
    void find(Data data, Strategy<Data>* comp)
    {
        tree->findnode_(data);
    }
    void remove(Data data)
    {
        tree->remove_(data);
    }
};

template<typename Data>
class QueueDecorator :public Decorator<Data> {
public:
    queue<Data> queue_;
    QueueDecorator(Interface<Data>* interface_)
    : Decorator<Data>(interface_) {}
    void insert(Data data) 
    {
        queue_.push(data);
    }
    void inorder()
    {
        vector<Data> tmp;
        while(queue_.size() > 0)
        {
            cout << *(queue_.front()) << endl;
            tmp.push_back(queue_.front());
            queue_.pop();
        }
        for (auto it = tmp.begin(); it != tmp.end(); it++)
        {
            queue_.push(*it);
        }
    }
    void find(Data data, Strategy<Data>* comp)
    {
        vector<Data> tmp;
        bool finf_flg = false;
        while (queue_.size() > 0)
        {
            if (comp->compare(data, queue_.front()) == 0)
            {
                finf_flg = true;
                cout << *(queue_.front()) << endl;
            }
            tmp.push_back(queue_.front());
            queue_.pop();
        }
        for (auto it = tmp.begin(); it != tmp.end(); it++)
        {
            queue_.push(*it);
        }
        if (!finf_flg)
            cout << "Element not found!" << endl;
    }
    void remove(Data data, Strategy<Data>* comp)
    {
        vector<Data> tmp;
        //Strategy<Data>* comp = new DocId_strategy;
        while (queue_.size() > 0)
        {
            if (!(comp->compare(data, queue_.front()) == 0))
                tmp.push_back(queue_.front());
            queue_.pop();
        }
        for (auto it = tmp.begin(); it != tmp.end(); it++)
        {
            queue_.push(*it);
        }
    }
};