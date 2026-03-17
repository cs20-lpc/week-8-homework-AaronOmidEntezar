#ifndef LINKEDLIST_STACK_HPP
#define LINKEDLIST_STACK_HPP

#include <iostream>
#include "Stack.hpp"

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedListStack : public Stack<T> {
private:
    Node<T>* top;   // points to the top node of stack

    void copy(const LinkedListStack<T>&);

public:
    LinkedListStack();

    LinkedListStack(const LinkedListStack<T>&);

    LinkedListStack<T>& operator=(const LinkedListStack<T>&);

    virtual ~LinkedListStack();

    virtual void clear() override;

    virtual int getLength() const override;

    virtual bool isEmpty() const override;

    virtual T peek() const override;

    virtual void pop() override;

    virtual void push(const T&) override;

    virtual void rotate(typename Stack<T>::Direction) override;

    virtual void print() override;
};

#include "LinkedListStack.tpp"
#endif