#pragma once

//template < template<typename TargetType> typename Container, typename TargetType> class Interface
//{
//
//};

#include<iostream>
#include<queue>

using namespace std;

template<typename Data>class Interface {
public:
    virtual ~Interface() = default;
    virtual void insert(Data data) = 0;
    virtual void inorder() = 0;
};

template<typename Data>
class ConcretteInterface : public Interface<Data> {
public:

    void insert(Data data) 
    {
        
    }
    void inorder()
    {

    }
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
   void insert(Data data) 
    {

    }
   void inorder()
   {

   }
};

template<typename Data, typename StrategyType>
class TreeDecorator :public Decorator<Data> {
public:
    Strategy<Data>* compId;/* = new DocId_strategy;*/
    AVLTree<Data>* tree;/* = new AVLTree<Data>(compId);*/
    TreeDecorator(Interface<Data>* interface_) 
    : Decorator<Data>(interface_), compId(new StrategyType), tree(new AVLTree<Data>(compId))
    {

    }
    void insert(Data data)
    {
        tree->insert_(data);
    }
    void inorder()
    {
        tree->inorder_();
    }
};

template<typename Data>
class QueueDecorator :public Decorator<Data> {
public:
    queue<Data> queue_;
    Data data;
    QueueDecorator(Interface<Data>* interface_) :Decorator<Data>(interface_) {}
    void insert(Data data) 
    {
        queue_.push(data);
    }
    void inorder()
    {
        for (int i = 0; i < queue_.size() - 1; i++)
        {
            cout << *(queue_.front()) << endl;
        }
    }
};